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