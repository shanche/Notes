//Reverse a linked list from position m to n.
#include<iostream>
#include<new>
#include<climits>

using namespace std;

struct ListNode { 						//definition for singly-linked list.
public:
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {} 			//constructor
};

void Append(ListNode* head, int x){ 				//add one node after the last node
	ListNode *last = new ListNode(x);
	head->next = last;
}

ListNode* ReverseBetween(ListNode* head, int m, int n) {   	//this algorithm is in-place and one-pass
    n-=m;
    ListNode prehead(0);
    prehead.next=head;
    ListNode* mpre=&prehead;
    while(--m)mpre=mpre->next; 
    ListNode* pstart=mpre->next;                                //pstart point to the mth node, mpre point to the node before it
    while(n--)
    {
        ListNode *p=pstart->next;				//p point to the node after pstart
        pstart->next=p->next;					//delete this node
        p->next=mpre->next;
        mpre->next=p;						//move it after mpre
    }
    return prehead.next;
    
  }

int main()
{
   double x;
   int i;
   cout << "Enter a list of numbers to construct a singly-linked list \n"
        << "(Quit with a letter):" << endl;

   ListNode prehead(0);
   ListNode* head = &prehead;
   for( i = 0; cin >> x; ++i, head = head->next)
	Append(head,x);

   cin.clear();
   cin.ignore(INT_MAX,'\n');

   head = prehead.next;
   cout << "The given singly-linked list:" << endl;	
   while( head) {cout << head->val << "  "; head = head->next;}
   cout << endl;

   int m, n;
   cout << "Reverse between nodes:"<<endl;
   cin >> m >> n;

   head = ReverseBetween(prehead.next, m, n);
   cout << "The reversed numbers" << endl;	
   while( head) {cout << head->val << "  "; head = head->next;}
   cout << endl;
	return 0;
}
