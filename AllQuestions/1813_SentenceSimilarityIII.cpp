#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/**
 * @brief You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.

For example,

s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

 

Example 1:

Input: sentence1 = "My name is Haley", sentence2 = "My Haley"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".

Example 2:

Input: sentence1 = "of", sentence2 = "A lot of words"

Output: false

Explanation:

No single sentence can be inserted inside one of the sentences to make it equal to the other.

Example 3:

Input: sentence1 = "Eating right now", sentence2 = "Eating"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.

 

Constraints:

1 <= sentence1.length, sentence2.length <= 100
sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
The words in sentence1 and sentence2 are separated by a single space.
 * 
 */

class Solution {
public:
    bool areSentencesSimilar(std::string sentence1, std::string sentence2) {
        std::vector<std::string> words1, words2;
        std::string word = "";
        std::istringstream stream1(sentence1), stream2(sentence2);

        while (stream1 >> word) {
            words1.push_back(word);
        }

        while (stream2 >> word) {
            words2.push_back(word);
        }

        // Check common prefix
        int i = 0, j = 0;
        while (i < words1.size() && i < words2.size() && words1[i] == words2[i]) {
            ++i;
        }

        // Check common suffix
        while (j < words1.size() - i && j < words2.size() - i && words1[words1.size() - 1 - j] == words2[words2.size() - 1 - j]) {
            ++j;
        }

        // Check if the sum of prefix and suffix is equal to the word count of smaller sentence
        return i + j == std::min(words1.size(), words2.size());
    }
};

int main(void) {
    Solution sol;
    std::string sentence1 = "My name is Haley";
    std::string sentence2 = "My Haley";
    std::cout << sol.areSentencesSimilar(sentence1, sentence2) << std::endl;
    return 0;
}