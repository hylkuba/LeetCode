#include <iostream>
#include <string>

/**
 * @brief Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length
 * 
 */

class Solution {
public:
    int maxVowels(std::string s, int k) {
        // Initialize prevMax
        int max = 0;
        for(int i = 0; i < k; i++) {
            if(isVowel(s[i])) {
                max++;
            }
        }
        int cnt = max;

        int size = s.size();
        for(int i = k; i < size; i++) {
            if(isVowel(s[i])) cnt++;

            if(isVowel(s[i - k])) cnt--;

            if(cnt > max) {
                max = cnt;
            }
        }

        return max;
    }

private:
    bool isVowel(char c) {
        return c =='a' || c =='e' || c =='i' || c =='o' || c =='u';
    }
};

int main(void) {
    Solution solution;
    std::string s = "abciiidef";
    int k = 3;
    int result = solution.maxVowels(s, k);
    std::cout << "Result: " << result << std::endl;
    return 0;
}