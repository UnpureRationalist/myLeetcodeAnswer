struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *nex) : val(x), next(nex) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        while (head != slow) {
          head = head->next;
          slow = slow->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};