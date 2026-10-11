/**
 * @file find-index-suboptimal.cpp
 * Temporal complexity: O(n*m)
 * Spatial complexity: O(1)
 */

#include <string>
#include <cassert>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (haystack.length() == 0) return (-1);
        auto points{0}, first{0};
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[points]) {
                if (!points) first = i;
                points++;
            }
            else if (points){
                points = 0;
                i = first;
            } 
            if (points == needle.length()) return (first);
        }
        return (-1);
    }
};

int main() {
    Solution s;
    assert(s.strStr("hello", "ll") == 2);
    assert(s.strStr("aaaaa", "bba") == -1);
}