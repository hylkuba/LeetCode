#include <iostream>
#include <vector>
#include <queue>

/**
 * @brief You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
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

// Comparison structure for the priority queue
struct compare {
    bool operator()(const ListNode* l1, const ListNode* l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* sorted = nullptr;
        ListNode** start = &sorted;

        // Priority queue to store the nodes, sorted by node values
        std::priority_queue<ListNode*, std::vector<ListNode*>, compare> pq;

        // Initialize the priority queue with the first node of each list
        for (ListNode* list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        // Merge the lists
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            *start = smallest;
            start = &((*start)->next);

            if (smallest->next) {
                pq.push(smallest->next);
            }
        }

        return sorted;
    }
};

int main(void) {
    Solution sol;
    std::vector<ListNode*> lists;
    ListNode* list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* list3 = new ListNode(2, new ListNode(6));
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);
    ListNode* result = sol.mergeKLists(lists);
    printList(result);
    return 0;
}