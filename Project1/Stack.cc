#include "Stack.h"
#include <stdlib.h>

// Initializes an empty Stack.
Stack::Stack() {
	num_elements = 0;
}

// Cleans up memory before the Stack's destruction.
Stack::~Stack() {
	while(num_elements > 0)
	{
		pop();
	}
	head->next = NULL;
}

// Pushes value onto the top of the stack.
void Stack::push(int value) {
	node* newNode = new node;
	newNode->value = value;
	if(num_elements != 0)
	{
		node* temp = head->next;
		head->next = newNode;
	        newNode->next = temp;
	}
	else
	{
		head->next = newNode;
	}
	num_elements++;
}

// Pops the top-most value off the stack and returns its value.
int Stack::pop() {
	if (size() != 0)
	{
		node* temp = head->next;
		head->next = head->next->next;
		num_elements--;
		int tval = temp->value;
		delete temp;
		return tval;
	}
	else
	{
		return 0;
	}
}

// Returns the value at the top of the stack.  Works similarly to pop(), but
// retains the internal structure of the stack.  That is, it does not remove
// the top-most element.
int Stack::getTopElement() const {
	return head->next->value;
}

// Returns the number of elements currently in the stack.
int Stack::size() const {
	return num_elements;
}
