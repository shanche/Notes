#include<iostream>
#include<string>

struct Node{
	double value;
	Node* next;
};  // struct is a class, and all of its variables are public


Node* deleteNode(Node* Node_i, Node* head);
void printList(Node* head);

int main()
{
	Node * node1 = new Node;
	Node * node2 = new Node;
	Node * node3 = new Node;

	node1->value = 1;
	node1->next = node2;
	node2->value = 2;
	node2->next = node3;
	node3->value = 3;
	node3->next = NULL;

	printList(node1);

	deleteNode(node2, node1);

	printList(node1);

	Node* new_head = deleteNode(node1, node1);
	printList(new_head);

	Node* new_head2 = deleteNode(node3, new_head);
	printList(new_head2);

	system("pause");
}

void printList(Node* head)
{
	if (head == NULL)
	{
		std::cout << "There is no Node left" << std::endl;
		return;    // the function ends here.
	}

	for (Node* tmp = head; tmp != NULL; tmp = tmp->next)
	{
		std::cout << tmp->value << ",";
	}

	std::cout << std::endl;
}

Node* deleteNode(Node* Node_i, Node* head)
{
	Node* tmp = head;
	Node* previous = NULL;
	// if Node_i is the header
	if (Node_i == head)
	{
		tmp = Node_i->next;
		delete Node_i;
		return tmp;
	}
	else 
	{
        // if Node_i is not the header
		for (; tmp != NULL; tmp = tmp->next)
		{
			if (tmp->next == Node_i)
			{
				previous = tmp;
				tmp = tmp->next;
				break;
			}
		}
		previous->next = tmp->next;
		delete tmp;  // delete Node_i
		return head;
	}

}