#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    // Инициализация Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed\n");
        return 1;
    }

    // Создание сокета
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        fprintf(stderr, "Socket creation failed: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Настройка адреса сервера
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1280);

    // Преобразование IP-адреса
    if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address or address not supported\n");
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Подключение к серверу
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        fprintf(stderr, "Connection failed: %d\n", WSAGetLastError());
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    printf("Connected to server!\n");

    // Ввод и отправка сообщения
    char message[1024];
    printf("Enter the string, please: ");

    if (fgets(message, sizeof(message), stdin) == NULL) {
        fprintf(stderr, "Input error\n");
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Убираем символ новой строки
    message[strcspn(message, "\n")] = '\0';

    // Отправка данных
    if (send(clientSocket, message, (int)strlen(message) + 1, 0) == SOCKET_ERROR) {
        fprintf(stderr, "Send failed: %d\n", WSAGetLastError());
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    printf("Message sent to server\n");

    // Получение ответа от сервера
    char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);

    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        printf("Server response: %s\n", buffer);
    }
    else if (bytesReceived == 0) {
        printf("Server disconnected\n");
    }
    else {
        fprintf(stderr, "Receive failed: %d\n", WSAGetLastError());
    }

    // Закрытие соединения
    closesocket(clientSocket);
    WSACleanup();

    printf("Press Enter to exit...");
    getchar();

    return 0;
}