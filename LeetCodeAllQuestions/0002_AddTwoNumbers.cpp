#include <iostream>
#include <list>
#include <string>
#include <algorithm>

/**
 * @brief You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 * 
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        ListNode* result = new ListNode();
        ListNode* resultPointer = result;

        bool overflow = false;
        while(curr1 != nullptr && curr2 != nullptr) {
            
            int tmp = curr1->val + curr2->val;
            
            // Add 1 if there is an overflow
            if(overflow) {
                tmp++;
                overflow = false;
            }

            // Check if there is an overflow
            if(tmp >= 10) {
                tmp %= 10;
                overflow = true;
            }

            // Assign the value
            resultPointer->val = tmp;
            
            if(curr1->next == nullptr) {

                while(curr2->next != nullptr) {
                    curr2 = curr2->next;
                    resultPointer->next = new ListNode();
                    resultPointer = resultPointer->next;

                    if (overflow) {
                        tmp = curr2->val + 1;
                        if(tmp >= 10) {
                            tmp %= 10;
                            overflow = true;
                        } else {
                            overflow = false;
                        }
                        resultPointer->val = tmp;
                    } else {
                        resultPointer->val = curr2->val;
                    }
                }

                break;
            }
            
            if(curr2->next == nullptr) {

                while(curr1->next != nullptr) {
                    curr1 = curr1->next;
                    resultPointer->next = new ListNode();
                    resultPointer = resultPointer->next;

                    if (overflow) {
                        tmp = curr1->val + 1;
                        if(tmp >= 10) {
                            tmp %= 10;
                            overflow = true;
                        } else {
                            overflow = false;
                        }
                        resultPointer->val = tmp;
                    } else {
                        resultPointer->val = curr1->val;
                    }
                }

                break;
            }

            // If nodes continue, create a new node
            resultPointer->next = new ListNode();
            resultPointer = resultPointer->next;

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        // If overflow prevails, add last digit 1
        if(overflow) {
            resultPointer->next = new ListNode();
            resultPointer = resultPointer->next;
            resultPointer->val = 1;
        }

        return result;
    }
};

int main(void) {
    Solution sol;

    ListNode* l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode* l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    
    ListNode* result = sol.addTwoNumbers(l1, l2);

    while(result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
}