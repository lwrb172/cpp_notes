#include <iostream>

using namespace std;

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
        int carry = 0;
        ListNode* preHead = new ListNode(0);
        ListNode* tmp = preHead;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            tmp->next = new ListNode(sum%10);
            tmp = tmp->next;
        }

        return preHead->next;
    }
};

int main() {
    Solution* s = new Solution;
//  ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
//  ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    ListNode* l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode* l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

    ListNode* result = s->addTwoNumbers(l1, l2);
    while (result != nullptr) {
        cout << result->val << endl;
        result = result->next;
    }

    return 0;
}
