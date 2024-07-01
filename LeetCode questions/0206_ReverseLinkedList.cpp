#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return head;
        }

        std::stack<ListNode*> order;
        
        // Add nodes to stack
        while(head != nullptr) {
            order.push(head);
            head = head->next;
        }

        head = order.top();
        order.pop();

        ListNode* curr = head;

        while(!order.empty()) {
            curr->next = order.top();
            order.pop();
            curr = curr->next;
        }

        curr->next = nullptr;

        return head;
    }
};

int main(void) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    Solution sol;
    ListNode* reversed = sol.reverseList(head);

    while(reversed != nullptr) {
        std::cout << reversed->val << " ";
        reversed = reversed->next;
    }

    return 0;
}