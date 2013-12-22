//#include "run.h"
// Creates an empty binary tree
template<class T> binTree<T>::binTree() {
	root = NULL;
}

// Cleans up memory before the tree's destruction
template<class T> binTree<T>::~binTree() {
	destruct(root);
}

// Inserts the value into the appropriate place in the tree.
// this function will use helper function insert(T val, node* n) to insert a value.
template<class T> void binTree<T>::insert(T val) {
	if(root == NULL)
        {
                delete root;
                root = new node(val, NULL, NULL);
        }
	else
	{
		insert(val, root);
	}
}

// Helper function for insert that takes a node argument.
// You should find the node n which the new node will be added to that.
// Then add new node to node n
template<class T> void binTree<T>::insert(T val, node* n) {
	if(val < n->val)
	{
		if(n->left == NULL)
		{
			n->left = new node(val, NULL, NULL);
		}
		else
		{
			insert(val, n->left);
		}
	}
	else if(val > n->val)
	{
		if(n->right == NULL)
		{
			n->right = new node(val, NULL, NULL);
		}
		else
		{
			insert(val, n->right);
		}
	}
}

// Finds the v in the tree such that v == val. It's assumed that
// for the generic type being used that if both v < val and v > val
// are false, then v == val is true.  Once v is found, it is returned.
// If no matching value is found in the tree, not_found is thrown.
// You should throw not_found in this way: 
// throw not_found();
template<class T> T binTree<T>::find(T val) const {
	if(root == NULL)
	{
		throw not_found();
	}
	else
	{
		return find(val, root);
	}
	throw not_found();
}

// Helper function for find that accepts a node argument.
// The interface function find(T val) uses this function to find the val
// You should find the node n which which contains value val.
// Then return value val if it was not found throw not_found by:
// throw not_found();
template<class T> T binTree<T>::find(T val, node* n) const {
	if(val < n->val)
	{
		if(n->left == NULL)
		{
			throw not_found();
		}
		else
		{
			return find(val, n->left);
		}
	}
	else if(val > n->val)
	{
		if(n->right == NULL)
		{
			throw not_found();
		}
		else
		{
			return find(val, n->right);
		}
	}
	return n->val;
}

// Removes a value from the tree.  Works identically to find (and operates
// with the same assumptions), except that it removes the value from the
// tree in addition to returning it.
template<class T> T binTree<T>::remove(T val) {
	if(root == NULL)
	{
		throw not_found();
	}
	else
	{
		return remove(val, root, root);
	}
	//throw not_found();
}

// Helper function to remove that accepts a node argument.
template<class T> T binTree<T>::remove(T val, node* n, node* parent) {
	if(val < n->val)
	{
		if(n->left == NULL)
		{
			throw not_found();
		}
		else
		{
			return remove(val, n->left, n);
		}
	}
	else if(val > n->val)
	{
		if(n->right == NULL)
		{
			throw not_found();
		}
		else
		{
			return remove(val, n->right, n);
		}
	}
	

	if(n->left == NULL && n->right == NULL)
	{
		if(parent->right == n)
		{
			parent->right = NULL;
		}
		else
		{
			parent->left = NULL;
		}
		T tmp = n->val;
		delete n;	
		return tmp;
	}
	else if(n->left == NULL)
	{
		if(parent->right == n)
		{
			parent->right = n->right;
		}
		else
		{
			parent->left = n->right;
		}
		T tmp = n->val;
		delete n;
		return tmp;
	}
	else if(n->right == NULL)
	{
		if(parent->right == n)
		{
			parent->right = n->left;
		}
		else
		{
			parent->left = n->left;
		}
	
		T tmp = n->val;
                delete n;
                return tmp;
	}
	else
	{
		node* temp = n->right;
		while(temp->left != NULL)
		{
			temp = temp->left;
		}
		temp->left = n->left;
		if(parent->right == n)
		{
			parent->right = n->right;
		}
		else
		{
			parent->left = n->right;
		}
		T tmp = n->val;
                delete n;
                return tmp;
	}
}

// Helper function for the destructor that recursively deletes all
// nodes in the tree.
template<class T> void binTree<T>::destruct(node* n) {
	//Was never able to get this method to work properly, always results in a segfault 
	//despite the program passing all other tests.
	
	//if(n != NULL)
	//{
	//	if(n->right != NULL)
	//	{
			//destruct(n->right);
	//	}
	//	if(n->left != NULL)
	//	{
			//destruct(n->left);
	//	}
		//delete n;
	//}
}
