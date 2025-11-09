//
// Created by Mingjie.Zhu22 on 2025/11/8.
//
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // map<char, int> magazine;
        vector<int> note_char;
        note_char.assign(26,0);
        vector<int> magazine_char;
        magazine_char.assign(26,0);

        for (char c : magazine)
        {
            if (c != ' ')
            {
                magazine_char[c - 'a']++;
            }
        }

        for (char c : ransomNote)
        {
            if (c != ' ')
            {
                note_char[c - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (note_char[i] > magazine_char[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    struct Test { string ransom; string magazine; bool expect; };
    Test tests[] = {
        {"a", "b", false},
        {"aa", "ab", false},
        {"aa", "aab", true},
        {"", "", true},
        {"ab", "a b", true}
    };
    for (const auto& t : tests) {
        bool ok = sol.canConstruct(t.ransom, t.magazine);
        cout << "ransomNote=\"" << t.ransom << "\" magazine=\"" << t.magazine << "\" -> "
             << (ok ? "true" : "false") << " (expected " << (t.expect ? "true" : "false") << ")\n";
    }
    return 0;
}

