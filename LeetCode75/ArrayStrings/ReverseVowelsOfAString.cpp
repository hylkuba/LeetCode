#include <string>
#include <set>

class Solution {
public:
    std::string reverseVowels(std::string s) {
        if(s.size() <= 1) return s;
        
        size_t l = 0;
        size_t r = s.size() - 1;

        std::set<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

        while(l < r) {
            if(vowels.find(s[l]) != vowels.end()) {
                char c = s[l];
                while(l < r) {

                    if(vowels.find(s[r]) != vowels.end()) {
                        s[l] = s[r];
                        s[r] = c;
                        r--;
                        break;
                    }
                    r--;
                }
            }

            l++;
        }

        return s;
    }
};