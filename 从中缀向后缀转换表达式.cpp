#include<bits/stdc++.h>
using namespace std;
map<char, int> priority = {
    {'^', 3},
    {'*', 2},
    {'/', 2},
    {'-', 1},
    {'+', 1},
    {'(', 0}
};

bool is_ope(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')';
}

string getansfix(const string& infix) {
    string ansfix;
    stack<char> ope_stack;
    for (char c : infix) {
        if (c == ' ') continue;
        if (!is_ope(c)) {
            ansfix += c;
        } 
        else if (c == '(') {
            ope_stack.push(c);
        } 
        else if (c == ')') {
            while (!ope_stack.empty() && ope_stack.top() != '(') {
                ansfix += ope_stack.top();
                ope_stack.pop();
            }
            ope_stack.pop();
        } 
        else {
            while (!ope_stack.empty() && ((c != '^' && priority[ope_stack.top()] >= priority[c]) || (c == '^' && priority[ope_stack.top()] > priority[c]))) {
                ansfix += ope_stack.top();
                ope_stack.pop();
            }
            ope_stack.push(c);
        }
    }
    while (!ope_stack.empty()) {
        ansfix += ope_stack.top();
        ope_stack.pop();
    }
    return ansfix;
}

int main() {
    int n;
    cin >> n;
    getchar(); 
    while (n--) {
        string input;
        getline(cin, input);
    	input.erase(input.end() - 1);
    	string ansfix = getansfix(input); 
		cout<<ansfix<<endl;
	}
    return 0;
}