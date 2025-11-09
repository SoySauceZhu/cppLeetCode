//
// Created by Mingjie.Zhu22 on 2025/11/9.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char x: s) {
            if (x == '(' || x == '{' || x == '[') {
                st.push(x);
            } else if (x == ')' || x == '}' || x == ']') {
                if (st.empty())return false;
                char top = st.top();
                if ((x == ')' && top != '(') ||
                    (x == '}' && top != '{') ||
                    (x == ']' && top != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();;
    }

    bool isValid1(string s) {
        stack<char> parentheses;

        for (char c: s) {
            if (parentheses.empty()) {
                parentheses.push(c);
                continue;
            }
            switch (c) {
                case ')':
                    if (parentheses.top() == '(') {
                        parentheses.pop();
                    } else {
                        parentheses.push(c);
                    }
                    continue;
                case ']':
                    if (parentheses.top() == '[') {
                        parentheses.pop();
                    } else {
                        parentheses.push(c);
                    }
                    continue;
                case '}':
                    if (parentheses.top() == '{') {
                        parentheses.pop();
                    } else {
                        parentheses.push(c);
                    }
                    continue;
                default:
                    parentheses.push(c);
            }
        }

        return parentheses.empty() ? true : false;
    }
};


int main() {
    Solution sol;
    std::string tests[] = {"(])", "()[]{}", "(]", "([)]", "{[]}", "[", "]"};
    for (const auto &t: tests) {
        cout << "\"" << t << "\" -> " << (sol.isValid(t) ? "true" : "false") << '\n';
    }
    return 0;
}
