#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

/**
 * @brief You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].
Example 2:

Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].
 

Constraints:

1 <= words.length <= 105
1 <= words[i].length <= 40
words[i] consists only of lowercase English letters.
sum(words[i].length) <= 3 * 105
1 <= queries.length <= 105
0 <= li <= ri < words.length
 * 
 */

class Solution {
    std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
public:
    std::vector<int> vowelStrings(std::vector<std::string>& words, std::vector<std::vector<int>>& queries) {
        std::vector<int> valid;
        int cnt = 0;
        for(auto word : words) {
            if(vowels.find(word[0]) != vowels.end() &&
            vowels.find(word[word.size() - 1]) != vowels.end()) {
                cnt++;
            }
            valid.push_back(cnt);
        }

        std::vector<int> ans;
        for(auto query : queries) {
            int l = query[0];
            int r = query[1];

            if(l >= 1) {
                ans.push_back(valid[r] - valid[l - 1]);
            } else {
                ans.push_back(valid[r]);
            }

        }

        return ans;
    }
};

int main(void) {
    Solution sol;
    std::vector<std::string> words = {"aba","bcb","ece","aa","e"};
    std::vector<std::vector<int>> queries = {{0,2},{1,4},{1,1}};
    std::vector<int> ans = sol.vowelStrings(words, queries);
    for(auto a : ans) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}