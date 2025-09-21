#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkBrackets(const string& s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    setlocale(LC_ALL, "rus");
    string input;
    cout << "Введите строку: ";
    getline(cin, input);
    cout << "Скобки расставлены "
        << (checkBrackets(input) ? "верно" : "не верно")
        << endl;

    return 0;
}