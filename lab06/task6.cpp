#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix to prefix
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    stack<char> s;
    string prefix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            prefix += ch;
        }
        else if (ch == ')') {
            s.push(ch);
        }
        else if (ch == '(') {
            while (!s.empty() && s.top() != ')') {
                prefix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        }
        else { // operator
            while (!s.empty() && precedence(s.top()) > precedence(ch)) {
                prefix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

// Evaluate prefix expression
int evaluatePrefix(string prefix) {
    stack<int> s;
    reverse(prefix.begin(), prefix.end());

    for (char ch : prefix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push(pow(a, b)); break;
            }
        }
    }

    return s.top();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix form: " << prefix << endl;

    int result = evaluatePrefix(prefix);
    cout << "Evaluated result: " << result << endl;

    return 0;
}
