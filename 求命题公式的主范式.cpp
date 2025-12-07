#include<bits/stdc++.h>
using namespace std;
map<char, int> priority = {
    {'!', 5},
    {'&', 4},
    {'|', 3},
    {'-', 2},
    {'+', 1},
    {'(', 0}
};
bool is_ope(char c) {
    return c == '!' || c == '&' || c == '|' || c == '-' || c == '+' || c == '(' || c == ')';
}
string getansfix(const string& infix) {
    string ansfix;
    stack<char> ope_stack;
    for (char c : infix) {     
        if (!is_ope(c)) {
            ansfix += c;
        } else if (c == '(') {
            ope_stack.push(c);
        } else if (c == ')') {
            while (!ope_stack.empty() && ope_stack.top() != '(') {
                ansfix += ope_stack.top();
                ope_stack.pop();
            }
            ope_stack.pop(); 
        } else {
            while (!ope_stack.empty() && priority[ope_stack.top()] >= priority[c]) {
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

bool cal(bool a, bool b, char ope) {
    switch (ope) {
        case '&': return a && b;
        case '|': return a || b;
        case '-': return !a || b;
        case '+': return a == b;
        default: return false;
    }
}

bool eval(string& ansfix,map<char, bool>& values) {
    stack<bool> cal_stack;
    
    for (char c : ansfix) {
        if (!is_ope(c)) {
            cal_stack.push(values.at(c));
        } else if (c == '!') {
            bool a = cal_stack.top();
            cal_stack.pop();
            cal_stack.push(!a);
        } else {
            bool b = cal_stack.top();
            cal_stack.pop();
            bool a = cal_stack.top();
            cal_stack.pop();
            cal_stack.push(cal(a, b, c));
        }
    }
    
    return cal_stack.top();
}

set<char> getvars(const string& expre) {
    set<char> vars;
    for (char c : expre) {
        if (!is_ope(c)) {
            vars.insert(c);
        }
    }
    return vars;
}

int main() {
    string input;
    getline(cin, input);
    
    set<char> vars = getvars(input);
    int varsize = vars.size();
    int total = 1 << varsize;
    
    vector<int> minterms;
    vector<int> maxterms;
    
    string ansfix = getansfix(input);
    
    for (int i = 0; i < total; i++) {
        map<char, bool> values;
        int j = varsize - 1;
        for (char var : vars) {
            values[var] = (i >> j) & 1;
            j--;
        }
        
        bool result = eval(ansfix, values);
        if (result) {
            minterms.push_back(i);
        } else {
            maxterms.push_back(i);
        }
    }
    
    if (minterms.empty()) {
        cout << "0";
    } else {
        for (int k = 0; k < minterms.size(); k++) {
            if (k != 0) cout << " ∨ ";
            cout << "m" << minterms[k];
        }
    }
    
    cout << " ; ";
    
    if (maxterms.empty()) {
        cout << "1";
    } else {
        for (int k = 0; k < maxterms.size(); k++) {
            if (k != 0) cout << " ∧ ";
            cout << "M" << maxterms[k];
        }
    }
    cout<<endl;
    return 0;
}