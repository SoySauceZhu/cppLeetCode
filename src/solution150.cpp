//
// Created by Mingjie.Zhu22 on 2025/11/7.
//

#include <iostream>
#include <sstream> // add the definiton of stringstream to std namespace
#include <cctype>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        stringstream ss;
        for (char c: s) {
            if (isalpha(c) || isdigit(c)) {
                ss << (char)tolower(c);
            }
        }

        s = ss.str();

        int i = 0, j = s.size() - 1;
        bool palindrome = true;

        while (i < j) {
            if (s[i++] != s[j--]) palindrome = false;
        }

        return palindrome;
    }
};


int main() {
    Solution sol;
    string tests[] = {
        "",
        "A man, a plan, a canal: Panama",
        "race a car",
        "0P",
        "ab_a"
    };

    for (const string &t : tests) {
        cout << '"' << t << "\" -> " << (sol.isPalindrome(t) ? "true" : "false") << '\n';
    }

    return 0;
}
