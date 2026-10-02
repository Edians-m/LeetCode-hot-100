#include <iostream>
#include <list>
using namespace std;


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

int main() {
    int n;
    cin >> n;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    ListNode* current = reversedHead;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}