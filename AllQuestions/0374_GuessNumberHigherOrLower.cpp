#include <iostream>

/**
 * @brief We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.

 

Example 1:

Input: n = 10, pick = 6
Output: 6
Example 2:

Input: n = 1, pick = 1
Output: 1
Example 3:

Input: n = 2, pick = 1
Output: 1
 

Constraints:

1 <= n <= 231 - 1
1 <= pick <= n
 * 
 */

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int n) {
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        if(guess(n) == 0) return n;
        
        int pick = n / 2;
        int left = 0;
        int right = n;
        int val;
        while((val = guess(pick)) != 0) {
            if(val == -1) {
                right = pick;
                pick = left + (pick - left) / 2;
            } else {
                left = pick;
                pick = pick + (right - pick) / 2;
            }
        }
        return pick;
    }
};

int main(void) {
    Solution sol;
    std::cout << sol.guessNumber(10) << std::endl;
    std::cout << sol.guessNumber(1) << std::endl;
    std::cout << sol.guessNumber(2) << std::endl;
    return 0;
}