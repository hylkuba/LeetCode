#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/**
 * @brief Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
 

Example 1:

Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
Example 2:

Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.
Example 3:

Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
 

Constraints:

0 <= arr.length <= 105
-109 <= arr[i] <= 109
 * 
 */

class Solution {
public:
	std::vector<int> arrayRankTransform(std::vector<int>& arr) {
		std::map<int, int> ranking;
		std::vector<int> sortedArr = arr;
		std::sort(sortedArr.begin(), sortedArr.end());

		int rank = 1;
		for (int num : sortedArr) {
			if (ranking.find(num) == ranking.end()) {
				ranking[num] = rank++;
			}
		}

		std::vector<int> result(arr.size());
		for (int i = 0; i < arr.size(); i++) {
			result[i] = ranking[arr[i]];
		}

		return result; 
	}
};

int main(void) {
	Solution solution;
	std::vector<int> arr = {40, 10, 20, 30};
	std::vector<int> result = solution.arrayRankTransform(arr);
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}