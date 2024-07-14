#include <iostream>

/**
 * @brief You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
 * 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* sorted = nullptr;
        ListNode* start = sorted;

        if(list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        bool firstNum = true;
        while(list1 != nullptr && list2 != nullptr) {
            
            if(firstNum) {
                sorted = new ListNode();
                firstNum = false;
                start = sorted;
            } else {
                sorted->next = new ListNode();
                sorted = sorted->next;
            }
            
            if(list1->val < list2->val) {
                sorted->val = list1->val;
                list1 = list1->next;
            } else {
                sorted->val = list2->val;
                list2 = list2->next;
            }
        }

        if(sorted == nullptr) {
            sorted = new ListNode();
            start = sorted;

            if(list1 != nullptr) {
                sorted->val = list1->val;
                list1 = list1->next;
            } else {
                sorted->val = list2->val;
                list2 = list2->next;
            }
        }

        while(list1 != nullptr) {
            sorted->next = new ListNode();
            sorted = sorted->next;
            sorted->val = list1->val;
            list1 = list1->next;
        }

        while(list2 != nullptr) {
            sorted->next = new ListNode();
            sorted = sorted->next;
            sorted->val = list2->val;
            list2 = list2->next;
        }

        return start;
    }
};

int main(void) {
    Solution s;
    ListNode* list1 = nullptr;
    ListNode* list2 = new ListNode(0);
    ListNode* result = s.mergeTwoLists(list1, list2);
    
    printList(result);

    return 0;
}