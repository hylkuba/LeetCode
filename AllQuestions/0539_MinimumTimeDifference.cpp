#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

/**
 * @brief Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 

Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".
 * 
 */

class Solution {
    struct TTime {
        int h;
        int m;

        TTime(){}

        TTime(int hour, int min) : h(hour), m(min) {}

        int min() {
            return h * 60 + m;
        }

        friend bool operator<(const TTime &lhs, const TTime &rhs) {
            if(lhs.h == rhs.h) {
                return lhs.m < rhs.m;
            }
            return lhs.h < rhs.h;
        }
    };
public:
    int findMinDifference(std::vector<std::string>& timePoints) {
        std::vector<TTime> list;
        
        for(auto time : timePoints) {
            TTime next;
            next.h = std::stoi(time.substr(0, 2));
            next.m = std::stoi(time.substr(3, 2));
            list.push_back(next);
        }

        std::sort(list.begin(), list.end());
        
        int smallest = 24 * 60;
        for(int i = 1; i < list.size(); i++) {
            int curr = list[i].min() - list[i-1].min();
            if(curr < smallest) {
                smallest = curr;
                if(smallest == 0) return 0;
            }
        }

        int curr = (60 * 24 - list[list.size() - 1].min()) + list[0].min();
        if(curr < smallest) {
            smallest = curr;
        }

        return smallest;
    }
};

int main(void) {
    Solution sol;
    std::vector<std::string> timePoints = {"23:59","00:00"};
    std::cout << sol.findMinDifference(timePoints) << std::endl;
    return 0;
}