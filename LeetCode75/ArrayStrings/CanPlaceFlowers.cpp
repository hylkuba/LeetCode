#include <vector>
#include <iostream>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        if(n == 0) return true;

        for(size_t i = 0; i < flowerbed.size(); i++) {

            if(flowerbed[i] == 0) {
                
                if(i == 0 && (i + 1 >= flowerbed.size() || flowerbed[i + 1] == 0)) {
                    flowerbed[i] = 1;
                    n--;
                } else if(i == flowerbed.size() - 1 && (i - 1 < 0 || flowerbed[i - 1] == 0)) {
                    flowerbed[i] = 1;
                    n--;
                } else if(i > 0 && i < flowerbed.size() - 1 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }

            if(n == 0) return true;
        }

        return n == 0;
    }
};
