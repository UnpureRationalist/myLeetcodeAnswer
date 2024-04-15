#include "header.h"

class Solution {
  ListNode *mergeSort(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *pre = nullptr;
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    pre->next = nullptr;
    ListNode *lst1 = mergeSort(head);
    ListNode *lst2 = mergeSort(slow);
    ListNode *res = merge(lst1, lst2);
    return res;
  }

  ListNode *merge(ListNode *lst1, ListNode *lst2) {
    ListNode dummy;
    ListNode *pre = &dummy;
    while (lst1 && lst2) {
      if (lst1->val <= lst2->val) {
        pre->next = lst1;
        lst1 = lst1->next;
      } else {
        pre->next = lst2;
        lst2 = lst2->next;
      }
      pre = pre->next;
    }
    while (lst1) {
      pre->next = lst1;
      lst1 = lst1->next;
      pre = pre->next;
    }
    while (lst2) {
      pre->next = lst2;
      lst2 = lst2->next;
      pre = pre->next;
    }
    return dummy.next;
  }

 public:
  ListNode *sortList(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    return mergeSort(head);
  }
};
