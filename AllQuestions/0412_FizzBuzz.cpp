#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
 

Example 1:

Input: n = 3
Output: ["1","2","Fizz"]
Example 2:

Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]
Example 3:

Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 

Constraints:

1 <= n <= 104
 * 
 */

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> result;

        for(int i = 1; i <= n; i++) {
            if(i % 3 == 0) {
                if(i % 5 == 0) {
                    result.push_back("FizzBuzz");
                } else {
                    result.push_back("Fizz");
                }
            } else if(i % 5 == 0) {
                result.push_back("Buzz");
            } else {
                result.push_back(std::to_string(i));
            }
        }

        return result;
    }
};

int main(void) {
    Solution s;
    std::vector<std::string> result = s.fizzBuzz(15);

    for(const auto& str : result) {
        std::cout << str << " ";
    }

    std::cout << std::endl;
}