#include <stack>
#include <unordered_map>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> values = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') stack.push(c);
            else if (stack.empty()) return false;
            else if (values[c] == stack.top()) {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }
};

int main() {
    Solution solution;
    std::string input = "({[]})";
    bool result = solution.isValid(input);
    return result ? 0 : 1;
}