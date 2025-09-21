#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

#pragma comment(lib, "ws2_32.lib")

class SocketServer {
private:
    WSADATA wsaData;
    SOCKET serverSocket;
    sockaddr_in serverAddr;

public:
    SocketServer() : serverSocket(INVALID_SOCKET) {
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            throw std::runtime_error("WSAStartup failed");
        }
    }

    ~SocketServer() {
        if (serverSocket != INVALID_SOCKET) {
            closesocket(serverSocket);
        }
        WSACleanup();
    }

    void initializeSocket() {
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket == INVALID_SOCKET) {
            throw std::runtime_error("Socket creation failed");
        }

        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(1280);
        serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    }

    void bindAndListen() {
        if (bind(serverSocket, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
            throw std::runtime_error("Bind failed");
        }

        if (listen(serverSocket, 5) == SOCKET_ERROR) {
            throw std::runtime_error("Listen failed");
        }

        std::cout << "Server listening on port 1280..." << std::endl;
    }

    void processClient(SOCKET clientSocket) {
        char buffer[1024];
        int bytesReceived;

        while ((bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0)) > 0) {
            buffer[bytesReceived] = '\0';
            std::cout << "Received from client: " << buffer << std::endl;

            std::string letters = filterLetters(buffer, bytesReceived);
            std::cout << "Filtered letters: " << letters << std::endl;

            std::string sortedLetters = sortLetters(letters);
            std::cout << "Sorted result: " << sortedLetters << std::endl;

            if (send(clientSocket, sortedLetters.c_str(), sortedLetters.length(), 0) == SOCKET_ERROR) {
                std::cerr << "Send failed" << std::endl;
                break;
            }

            std::cout << "Sent sorted letters to client" << std::endl;
        }

        if (bytesReceived == 0) {
            std::cout << "Client disconnected" << std::endl;
        }
        else if (bytesReceived == SOCKET_ERROR) {
            std::cerr << "Receive error" << std::endl;
        }
    }

    void run() {
        while (true) {
            sockaddr_in clientAddr;
            int clientAddrSize = sizeof(clientAddr);

            SOCKET clientSocket = accept(serverSocket, reinterpret_cast<sockaddr*>(&clientAddr), &clientAddrSize);
            if (clientSocket == INVALID_SOCKET) {
                std::cerr << "Accept failed" << std::endl;
                continue;
            }

            std::cout << "Client connected" << std::endl;
            processClient(clientSocket);
            closesocket(clientSocket);
        }
    }

private:
    std::string filterLetters(const char* buffer, int length) {
        std::string letters;
        for (int i = 0; i < length; ++i) {
            if (std::isalpha(static_cast<unsigned char>(buffer[i]))) {
                letters += buffer[i];
            }
        }
        return letters;
    }

    std::string sortLetters(const std::string& letters) {
        std::string sorted = letters;
        std::sort(sorted.begin(), sorted.end());
        return sorted;
    }
};

int main() {
    try {
        SocketServer server;
        server.initializeSocket();
        server.bindAndListen();
        server.run();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}