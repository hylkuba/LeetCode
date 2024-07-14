#include <iostream>
#include <string>

/**
 * @brief Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
 * 
 */

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int firstIndex = -1;

        if(haystack.size() < needle.size()) {
            return firstIndex;
        } else if(haystack.size() == needle.size()) {
            if(haystack == needle) {
                return 0;
            } else {
                return firstIndex;
            }
        }

        int tmpFirstIndex = -1;
        size_t currIndex = 0;
        for(size_t i = 0; i < haystack.size(); i++) {
            if(haystack[i] == needle[currIndex]) {
                size_t j = i;
                tmpFirstIndex = i;
                while(j < haystack.size() && currIndex < needle.size() && haystack[j] == needle[currIndex]) {
                    j++;
                    currIndex++;
                }

                if(currIndex == needle.size()) {
                    firstIndex = tmpFirstIndex;
                    break;
                } else {
                    currIndex = 0;
                }
            }
        }

        return firstIndex;
    }
};

int main(void) {
    Solution s;
    std::string haystack = "abc";
    std::string needle = "c";
    std::cout << s.strStr(haystack, needle) << std::endl;
    return 0;
}