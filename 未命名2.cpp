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

map<char, int> variables; // 用于存储变量名和其对应的值

bool is_ope(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '(' || c == ')' || c == '#';
}

bool is_var(const string& token) {
    return token.length() == 1 && isalpha(token[0]);
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
        if (!is_ope(c) && !isdigit(c) && c != ' ' && !isalpha(c)) {
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
            if (i == infix.length() - 1 && infix[i] != ')' && infix[i] != '=') {
                return false; 
            }
            if (i > 0 && is_ope(infix[i - 1]) && infix[i - 1] != ')' && infix[i] != '(' && infix[i] != ')') {
                return false; 
            }
        }
    }
    return true;
}

bool error_0(const string& postfix) {
    stack<int> evalu;
    istringstream iss(postfix);
    string token;
    while (iss >> token) {
        if (!is_ope(token[0])) {
            if (is_var(token)) {
                evalu.push(variables[token[0]]);
            } else {
                evalu.push(stoi(token));
            }
        } else {
            if (evalu.size() < 2 && token[0] != '#') {
                return false;
            }
            if (token[0] == '#') {
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
                if ((token[0] == '/' || token[0] == '%') && right == 0) {
                    return true;
                }
                switch (token[0]) {
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
    istringstream iss(infix);
    string token;
    string left_var = ""; // 用于存储左侧的变量名

    while (iss >> token) {
        if (is_var(token)) {
            if (left_var.empty()) {
                left_var = token;
            } else {
                ansfix += token + ' ';
            }
        } else if (token == "=") {
            while (!ope_stack.empty()) {
                ansfix += ope_stack.top() + ' ';
                ope_stack.pop();
            }
            ansfix += token + ' ';
        } else if (is_ope(token[0])) {
            if (token[0] == '-' && (ansfix.empty() || ansfix.back() == '(')) {
                ope_stack.push('#');
            } else {
                while (!ope_stack.empty() && ((token[0] != '^' && priority[ope_stack.top()] >= priority[token[0]]) || (token[0] == '^' && priority[ope_stack.top()] > priority[token[0]]))) {
                    ansfix += ope_stack.top() + ' ';
                    ope_stack.pop();
                }
                ope_stack.push(token[0]);
            }
        } else {
            ansfix += token + ' ';
        }
    }

    while (!ope_stack.empty()) {
        ansfix += ope_stack.top() + ' ';
        ope_stack.pop();
    }

    return left_var + ' ' + ansfix; // 返回左侧变量名和后缀表达式
}

int getans(const string& postfix) {
    stack<int> evalu;
    istringstream iss(postfix);
    string token;
    string left_var;

    iss >> left_var; // 读取左侧变量名
    if (!is_var(left_var)) {
        return INT_MIN;
    }

    while (iss >> token) {
        if (!is_ope(token[0])) {
            if (is_var(token)) {
                evalu.push(variables[token[0]]);
            } else {
                evalu.push(stoi(token));
            }
        } else if (token == "=") {
            if (evalu.size() != 1) {
                return INT_MIN;
            }
            variables[left_var[0]] = evalu.top(); // 为左侧变量赋值
        } else {
            if (evalu.size() < 2 && token[0] != '#') {
                return INT_MIN;
            }
            if (token[0] == '#') {
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
                switch (token[0]) {
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
    return variables[left_var[0]]; // 返回左侧变量的值
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string input;
        getline(cin, input);
        string postfix = getansfix(input);
        if (postfix.empty() || error_0(postfix)) {
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
