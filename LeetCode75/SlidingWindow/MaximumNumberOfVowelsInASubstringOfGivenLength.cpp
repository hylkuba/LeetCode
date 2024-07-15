#include <string>

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