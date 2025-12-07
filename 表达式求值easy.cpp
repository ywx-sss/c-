#include<bits/stdc++.h>
using namespace std;

map<char, int> priority = {
    {'#', 4}, 
    {'^', 3},
    {'*', 2},
    {'/', 2},
    {'%', 2},
    {'-', 1},
    {'+', 1},
    {'(', 0}
};

bool is_ope(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '(' || c == ')' || c == '#';
}

bool is_kuohao(const string& infix) {
    stack<char> s;
    for (char c : infix) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            if (s.empty()) return false;
            s.pop();
        }
    }
    return s.empty();
}

bool is_vaild(const string& infix) {
    for (char c : infix) {
        if (!is_ope(c) &&!isdigit(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

bool is_vaildope(const string& infix) {
    for (int i = 0; i < infix.length(); i++) {
        if (is_ope(infix[i])) {
            if (i == 0 && infix[i] != '(' && infix[i] != '-') {
                return false; 
            }
            if (i == infix.length() - 1 && infix[i] != ')'&& infix[i] != '-') {
                return false; 
            }
            if (is_ope(infix[i - 1]) && infix[i - 1] != ')' && infix[i] != '('&& infix[i] != '-') {
                return false; 
            }
        }
    }
    return true;
}
bool error_0(const string& postfix) {
    stack<int> evalu;
    for (int i = 0; i < postfix.length(); i++) {
        if (postfix[i] == ' ') continue;
        if (!is_ope(postfix[i])) {
            int num = 0;
            while (i < postfix.length() &&!is_ope(postfix[i]) && postfix[i] != ' ') {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            i--;
            evalu.push(num);
        } else {
            if (evalu.size() < 2 && postfix[i] != '#') {
                return false;
            }
            if (postfix[i] == '#') {
                if (evalu.empty()) {
                    return false;
                }
                int operand = evalu.top();
                evalu.pop();
                evalu.push(-operand);
            } else {
                int right = evalu.top();
                evalu.pop();
                int left = evalu.top();
                evalu.pop();
                if ((postfix[i] == '/' || postfix[i] == '%') && right == 0) {
                    return true;
                }
                switch (postfix[i]) {
                    case '+':
                        evalu.push(left + right);
                        break;
                    case '-':
                        evalu.push(left - right);
                        break;
                    case '*':
                        evalu.push(left * right);
                        break;
                    case '/':
                        evalu.push(left / right);
                        break;
                    case '%':
                        evalu.push(left % right);
                        break;
                    case '^':
                        int result = 1;
                        for (int j = 0; j < right; j++) {
                            result *= left;
                        }
                        evalu.push(result);
                        break;
                }
            }
        }
    }
    return false;
}

string getansfix(const string& infix) {
    if (!is_kuohao(infix) || !is_vaild(infix) || !is_vaildope(infix)) {
        return "";
    }
    string ansfix;
    stack<char> ope_stack;
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == ' ') continue;
        if (!is_ope(infix[i])) {
            ansfix += infix[i];
            while (i + 1 < infix.length() &&!is_ope(infix[i + 1])) {
                ansfix += infix[++i];
            }
            ansfix += ' ';
        } else if (infix[i] == '(') {
            ope_stack.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!ope_stack.empty() && ope_stack.top() != '(') {
                ansfix += ope_stack.top();
                ansfix += ' ';
                ope_stack.pop();
            }
            if (ope_stack.empty()) {
                return "";
            }
            ope_stack.pop();
        } else if (infix[i] == '-') {
            if (i == 0 || infix[i - 1] == '(' || (is_ope(infix[i - 1]) && infix[i - 1] != ')')) {
                while (!ope_stack.empty() && priority[ope_stack.top()] >= priority['#']) {
                    ansfix += ope_stack.top();
                    ansfix += ' ';
                    ope_stack.pop();
                }
                ope_stack.push('#');
            } else {
                while (!ope_stack.empty() && ((infix[i] != '^' && priority[ope_stack.top()] >= priority[infix[i]]) || (infix[i] == '^' && priority[ope_stack.top()] > priority[infix[i]]))) {
                    ansfix += ope_stack.top();
                    ansfix += ' ';
                    ope_stack.pop();
                }
                ope_stack.push('-');
            }
        } else {
            if (infix[i] == '^') {
                while (!ope_stack.empty() && priority[ope_stack.top()] > priority['^']) {
                    ansfix += ope_stack.top();
                    ansfix += ' ';
                    ope_stack.pop();
                }
            } else {
                while (!ope_stack.empty() && priority[ope_stack.top()] >= priority[infix[i]]) {
                    ansfix += ope_stack.top();
                    ansfix += ' ';
                    ope_stack.pop();
                }
            }
            ope_stack.push(infix[i]);
        }
    }
    while (!ope_stack.empty()) {
        ansfix += ope_stack.top();
        ansfix += ' ';
        ope_stack.pop();
    }
    return ansfix;
}

int getans(const string& postfix) {
    stack<int> evalu;
    for (int i = 0; i < postfix.length(); i++) {
        if (postfix[i] == ' ') continue;
        if (!is_ope(postfix[i])) {
            int num = 0;
            while (i < postfix.length() &&!is_ope(postfix[i]) && postfix[i] != ' ') {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            i--;
            evalu.push(num);
        } else {
            if (evalu.size() < 2 && postfix[i] != '#') {
                return INT_MIN;
            }
            if (postfix[i] == '#') {
                if (evalu.empty()) {
                    return INT_MIN;
                }
                int operand = evalu.top();
                evalu.pop();
                evalu.push(-operand);
            } else {
                int right = evalu.top();
                evalu.pop();
                int left = evalu.top();
                evalu.pop();
                switch (postfix[i]) {
                    case '+':
                        evalu.push(left + right);
                        break;
                    case '-':
                        evalu.push(left - right);
                        break;
                    case '*':
                        evalu.push(left * right);
                        break;
                    case '/':
                        if (right == 0) {
                            return INT_MAX;
                        }
                        evalu.push(left / right);
                        break;
                    case '%':
                        if (right == 0) {
                            return INT_MAX;
                        }
                        evalu.push(left % right);
                        break;
                    case '^':
                        // 检查指数是否为负数
                        if (right < 0) {
                            return INT_MIN; 
                        }
                        int result = 1;
                        for (int j = 0; j < right; j++) {
                            result *= left;
                        }
                        evalu.push(result);
                        break;
                }
            }
        }
    }
    if (evalu.size() != 1) {
        return INT_MIN;
    }
    return evalu.top();
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string input;
        getline(cin, input);
        string postfix = getansfix(input);
        if (postfix.empty() && !error_0(postfix)) {
            cout << "error." << endl;
            continue;
        }
        int result = getans(postfix);
        if (result == INT_MIN) {
            cout << "error." << endl;
        } else if (result == INT_MAX) {
            cout << "Divide 0." << endl;
        } else {
            cout << result << endl;
        }
    }
    return 0;
}