#include <iostream> 
using namespace std;

struct ListNode
{
	/* data */
	int val;
	ListNode *next;
	ListNode (int x = 0):val(x), next(NULL) {};
};


ListNode *ReverseLinkedList(ListNode *head, int m, int n)
{
	ListNode *root = new ListNode(-1);
	root->next = head;

	ListNode *prev = root;
	ListNode *curr = head;
	ListNode *next = head->next;

	for (int i = 1; i < m; i++) 
	{
		prev = curr;
		curr = next;
		next = next->next;
	}

	ListNode *curr_root = prev;

	for (int i = m; i < n; i++) 
	{
		curr->next = prev;
		prev = curr;
		curr = next;
		next = next->next;
	}
	curr->next = prev;

	curr_root->next->next = next;
	curr_root->next = curr; 

	return root->next;
}


int main(int argc, char const *argv[])
{
	ListNode *L1 = new ListNode();
	ListNode *L2 = new ListNode(3);
	L1->next = L2;
	ListNode *L3 = new ListNode(7);
	L2->next = L3;
	ListNode *L4 = new ListNode(2);
	L3->next = L4;
	ListNode *L5 = new ListNode(5);
	L4->next = L5;

	cout << "List" << endl;

	ListNode *head = L1;
	while (head->next) 
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << head->val << endl;

	cout << "After reverse" << endl;

	head = ReverseLinkedList(L1, 1, 5);
	while (head->next) 
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << head->val << endl;

	return 0;
}