#include <vector>
#include <map>
#include <set>
#include <iostream>

/**
 * @brief Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
 * 
 */

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::map<int, int> occurences;

        int size = arr.size();
        for(int i = 0; i < size; i++) {
            occurences[arr[i]]++;
        }
        
        std::set<int> unique;
        for(const auto& it : occurences) {
            int cnt = it.second;
            if(unique.find(cnt) != unique.end()) {
                return false;
            }
            unique.insert(cnt);
        }
        
        return true;
    }
};

int main(void) {
    Solution s;
    std::vector<int> arr = {1,2,2,1,1,3};
    std::cout << s.uniqueOccurrences(arr) << std::endl;
    return 0;
}