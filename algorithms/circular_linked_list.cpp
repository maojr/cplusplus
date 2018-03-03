// Given a linked list, determine if it is a circular linked list
#include <assert.h>
#include <stdlib.h>

#include <vector>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

bool isCircularLinkedList(ListNode* head) {
    if (head == nullptr)
        return false;
    ListNode* p1 = head;
    ListNode* p2 = head;
    while (p1->next && p1->next->next) {
        p1 = p1->next->next;
        p2 = p2->next;
        if (p1 == p2)
            return true;
    }
    return false;
}

ListNode *getCircularLinkedList(const std::vector<int> &v) {
  assert(v.size() >= 2);
  ListNode* head = new ListNode(v[0]);
  ListNode* tail = head;
  for (int i = 1; i < v.size(); ++i) {
    tail->next = new ListNode(v[i]);
    tail = tail->next;
  }
  tail->next = head;
  return head;
}

void destroyCircularLinkedList(ListNode *head) {
    ListNode* p = head;
    while (p != nullptr) {
        ListNode* tmp = p->next;
        delete p;
        if (tmp != head)
            p = tmp;
        else
            p = nullptr;
    }
}

int main() {
  srand(0);
  std::vector<int> v(10);
  std::generate(v.begin(), v.end(), rand);

  ListNode* head = getCircularLinkedList(v);
  if (isCircularLinkedList(head))
    std::cout << "Is Cirtular Linked List" << std::endl;
  destroyCircularLinkedList(head);

  return 0;
}
