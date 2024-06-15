#include <iostream>
#include <string>
#include <algorithm>

/**
 * @brief Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.

 

Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
Example 2:

Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII
Example 3:

Input: num = 1994

Output: "MCMXCIV"

Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV
 

Constraints:

1 <= num <= 3999
 * 
 */

class Solution {
public:
    std::string intToRoman(int num) {
        int multiplier = 1;
        std::string result = "";

        while (num > 0) {
            int remainder = num % 10;

            result += addRoman(remainder, multiplier);

            // Adjust values for next numbers
            num /= 10;
            multiplier *= 10;
        }

        // Reverse the result in order to return it in correct order
        std::reverse(result.begin(), result.end());
        return result;
    }

private:

    std::string addRoman(int remainder, int multiplier) {
        std::string result = "";

        // If remainder is smaller than 4, append appropriate character
        if(remainder < 4) {
            result = addDigits(remainder, multiplier);

            return result;

        } else if(4 == remainder) {
            switch(multiplier) {
                case 1:
                    result = "IV";
                    break;

                case 10:
                    result = "XL";
                    break;
                
                case 100:
                    result = "CD";
                    break;

                default:
                    break;
            }

            std::reverse(result.begin(), result.end());
            return result;
        } else if(remainder >= 5 && remainder < 9) {

            switch(multiplier) {
                case 1:
                    result = "V";
                    break;

                case 10:
                    result = "L";
                    break;
                
                case 100:
                    result = "D";
                    break;

                default:
                    break;
            }

            if(5 == remainder) {
                return result;

            } else {
                result += addDigits(remainder % 5, multiplier);

                std::reverse(result.begin(), result.end());
                return result;
            }

        } else if(9 == remainder) {
            switch(multiplier) {
                case 1:
                    result = "IX";
                    break;

                case 10:
                    result = "XC";
                    break;
                
                case 100:
                    result = "CM";
                    break;

                default:
                    break;
            }

            std::reverse(result.begin(), result.end());
            return result;
        }

        // Result has to be reversed, because it will get reversed again in main function
        std::reverse(result.begin(), result.end());
        return result;
    }

    std::string addDigits(int remainder, int multiplier) {
        std::string result = "";
        
        char symbol = '_';

        switch(multiplier) {
            case 1:
                symbol = 'I';
                break;
            
            case 10:
                symbol = 'X';
                break;
            
            case 100:
                symbol = 'C';
                break;

            case 1000:
                symbol = 'M';
                break;
            
            default:
                break;
        }

        for (int i = 0; i < remainder; i++) {
            result += symbol;
        }

        return result;
    }
};

int main(void) {
    Solution solution;
    std::cout << solution.intToRoman(3749) << std::endl;
    std::cout << solution.intToRoman(58) << std::endl;
    std::cout << solution.intToRoman(1994) << std::endl;
    return 0;
}