

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
  };

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* current = head;
    int count = 0;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    current = head;
    for (int i = 0;i < count - n - 1;i++) {
        current = current->next;
    }
    if (count == n) {
        ListNode* nexHead = head->next;
        delete head;
        return nexHead;
    }
    ListNode* tail = (current->next);
    current->next = current->next->next;
    delete(tail);
    return head;
}