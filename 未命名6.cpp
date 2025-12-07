#include <iostream>
#include <string>
#include <map>
using namespace std;

string replaceLowercaseSubstrings(const string& input, const map<string, string>& variables) {
    string result;
    for (size_t i = 0; i < input.length(); ) {
        if (islower(input[i])) {
            size_t start = i;
            // 找到连续小写字母的结束位置
            while (i < input.length() && islower(input[i])) {
                i++;
            }
            // 提取连续小写字母子串
            string lowercaseSub = input.substr(start, i - start);
            // 检查该子串是否在 variables 中
            cout<<lowercaseSub<<" ";
            auto it = variables.find(lowercaseSub);
            if (it != variables.end()) {
                result += it->second;
            } else {
                result += lowercaseSub;
            }
        } else {
            result += input[i];
            i++;
        }
    }
    return result;
}

int main() {
    // 示例 variables 映射
    map<string, string> variables = {
        {"abc", "var_abc"},
        {"xyz", "var_xyz"}
    };
    string input = "HELLOabcWORLDxyz";
    string output = replaceLowercaseSubstrings(input, variables);
    cout << "原始字符串: " << input << endl;
    cout << "替换后的字符串: " << output << endl;
    return 0;
}