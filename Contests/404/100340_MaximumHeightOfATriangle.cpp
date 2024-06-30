#include <iostream>
#include <cmath>

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int max = 0;
        
        int row = 1;
        int r = red;
        int b = blue;
        // Odd red
        while(true) {
            if(row % 2 == 1) {
                if(r - row >= 0) {
                    r-=row;
                } else {
                    break;
                }
            } else {
                if(b - row >= 0) {
                    b -= row;
                } else {
                    break;
                }
            }
            row++;
        }

        row--;
        
        max = row;
        
        // Odd blue
        row = 1;
        r = red;
        b = blue;
        while(true) {
            if(row % 2 == 1) {
                if(b - row >= 0) {
                    b -= row;
                } else {
                    break;
                }
            } else {    
                if(r - row >= 0) {
                    r -= row;
                } else {
                    break;
                }
            }
            row++;
        }
        row--;
        
        return std::max(max, row);
    }
};

int main(void) {
    std::cout << Solution().maxHeightOfTriangle(2, 4) << std::endl;
}