#include <iostream>
#include <vector>

/**
 * @brief Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
 * 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> arr;

        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }

        if(arr.size() < 2) return true;

        size_t l = 0;
        size_t r = arr.size() - 1;

        while(l < r) {
            if(arr[l] != arr[r]) return false;

            l++;
            r--;
        }

        return true;
    }
};

int main(void) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution sol;
    std::cout << std::boolalpha << sol.isPalindrome(head) << std::endl;

    return 0;
}