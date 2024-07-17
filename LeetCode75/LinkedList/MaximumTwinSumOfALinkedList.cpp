#include <map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        std::map<int, int> m;

        int cnt = 0;

        // Store all values into map where key is the index
        while(head) {
            m[cnt++] = head->val;
            head = head->next;
        }

        int highestKey = m.rbegin()->first;
        int lowestKey = 0;

        // Loop through the map and find the maximum sum of twin pairs
        int maxSum = 0;
        while(lowestKey < highestKey) {
            maxSum = std::max(maxSum, m[lowestKey] + m[highestKey]);
            lowestKey++;
            highestKey--;
        }

        return maxSum;
    }
};