
//Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


ListNode *reverse(ListNode *head, int m, int n) {
    if (head == NULL || m >= n) {
        return head;
    }
    
    ListNode* newHead = new ListNode(0);
    
    newHead->next = head;
    head = newHead;
            
    for (int i = 1; i < m; i++) {
        if (head == NULL) {
            return NULL;
        }
        head = head->next;            
    }
    
    ListNode* prev = head->next;
    ListNode* curr = pre->next;
            
    for(int i = 0 ; i < n-m ; i++){
        ListNode * tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
     }
     head->next->next = curr;
     head->next = prev;
     head = newHead->next
     delete newHead;
     return head;
}
