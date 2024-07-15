#include <vector>
#include <iostream>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int charSize = chars.size();

        if(charSize <= 1) return charSize;
        
        std::vector<char> result;

        for(int i = 0; i < charSize; ) {

            // Loop and count the amount of the same character
            char prev = chars[i++];
            int cnt = 1;
            while(i < charSize && chars[i] == prev) {
                i++;
                cnt++;
            }

            // If there is just one character, add that character to result and increment i
            if(cnt == 1) {
                result.push_back(prev);
            }
            // Else add the new character to result followed by the count of characters 
            else {
                result.push_back(prev);
                std::string cntStr = std::to_string(cnt);
                for(char c : cntStr) {
                    result.push_back(c);
                }
            }
        }

        chars = result;
        return chars.size();
    }
};