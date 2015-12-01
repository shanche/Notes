#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x):val(x), next(NULL) {};
};

class List {
public:
  ListNode *head;
  List() { head = NULL; }
  void Append(int data);
  void Print();
};

void List::Append(int data){
  ListNode * newNode = new ListNode(data);
  ListNode *tmp = head;
  
  if ( tmp != NULL ){
    while ( tmp->next != NULL ){
      tmp = tmp->next;
    }
    tmp->next = newNode;
  } else {
    head = newNode;
  }
}

void List::Print(){
  ListNode *tmp = head;
  if ( tmp == NULL ){
    cout << "EMPTY" << endl;
    return;
  } else {
    while ( tmp!= NULL ) {
      cout << tmp->val << "-->" ;
      tmp = tmp->next;
    }
    cout << "NULL" << endl;
  }
}

  
  
ListNode *reverseBetween(ListNode *head, int m, int n){
  ListNode *dummy = new ListNode(0);
  dummy->next = head;
  
  int pos = 1;
  
  // jump to (m-1)th node
  while ( pos < m-1 && head != NULL ){
    head = head->next;
    ++ pos;
  }
  ++pos;
  // pre position m
  ListNode *pre = head->next, *cur = pre->next;
  while ( pos < n && cur != NULL ){
    ListNode *curNext = cur->next;
    cur->next = pre;
    pre = cur;
    cur = curNext;
    ++pos;
  }

  head->next->next = cur;
  head->next = pre;
  head = dummy->next;
  delete dummy;
  return head;
}


int main(){
  List list;
  for (int i=1; i< 10; i++){
    list.Append(i);
  }
  list.Print();
  ListNode  *head = list.head;
  reverseBetween(head, 2, 5 );
  list.Print();
}  
