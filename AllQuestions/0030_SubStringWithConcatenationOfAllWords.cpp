#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/**
 * @brief You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

Explanation:

The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []

Explanation:

There is no concatenated substring.

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]

Explanation:

The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

 

Constraints:

1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.
 * 
 */

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {    
        
        std::vector<int> indices;
        if (s.empty() || words.empty()) return indices;

        int wordLength = words[0].size();
        int totalLength = wordLength * words.size();
        if (s.size() < totalLength) return indices;

        // Build the word count map
        std::unordered_map<std::string, int> wordCount;
        for (const auto& word : words) {
            ++wordCount[word];
        }

        // Slide over the string in steps of wordLength (This allows all possible matching strings)
        for (int startIndex = 0; startIndex < wordLength; ++startIndex) {
            int left = startIndex, count = 0;
            std::unordered_map<std::string, int> seenWords;

            for (int j = startIndex; j <= s.size() - wordLength; j += wordLength) {
                std::string word = s.substr(j, wordLength);
                // If the word is part of words
                if (wordCount.find(word) != wordCount.end()) {
                    seenWords[word]++;
                    count++;
                    // If the word is seen more times than it exists in words, slide the window
                    while (seenWords[word] > wordCount[word]) {
                        std::string temp = s.substr(left, wordLength);
                        seenWords[temp]--;
                        count--;
                        left += wordLength;
                    }
                    // If all words are seen
                    if (count == words.size()) {
                        indices.push_back(left);
                        // Slide the window
                        seenWords[s.substr(left, wordLength)]--;
                        count--;
                        left += wordLength;
                    }
                } else {
                    // Reset if the word is not in words
                    seenWords.clear();
                    count = 0;
                    left = j + wordLength;
                }
            }
        }

        return indices;
    }
};

int main(void) {
    Solution s;
    std::string str = "barfoothefoobarman";
    std::vector<std::string> words = {"foo", "bar"};
    std::vector<int> indices = s.findSubstring(str, words);
    for (const auto& index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
    return 0;
}