#include <iostream>
#include <string>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        size_t length1 = word1.length();
        size_t length2 = word2.length();

        std::string result = "";

        size_t i = 0;
        for(i; i < length1; i++) {
            result += word1[i];
            if(i < length2) {
                result += word2[i];
            }
        }

        if(i < length2) {
            for(i; i < length2; i++) {
                result += word2[i];
            }
        }

        return result;
    }
};