#include "ext.h"

struct obj {
	// Called by engine when this node is added to a tree (when it goes from having no parent to having a parent)
	// It is not called if the node is moved within or between one or more trees
	virtual void _init() {}
	// Called by the engine when this node is reparented
	virtual void _load() {}
	// Called by engine when receiving user input
	virtual void _input() {}
	// Called by engine along with draw of each frame
	virtual void _frame() {}
};

struct node: obj {
	char* name = "";
	node* parent = NULL;
	int idx = -1;
	list<node*> children;
	// Free all memory for this node AND all of its children RECURSIVELY
	// Effectively destroys an entire node tree or a branch of a node tree
	// Returns the number of nodes that were deallocated
	int destroy() {
		list<int> siblingPositions;
		siblingPositions.pushb(0);
		int totalFreed = 0;
		node* current = this;
		while (siblingPositions.peekb() > 0) {
			
		}
		return totalFreed;
	}
	// If n is in the tree, reparent n to this node
	// Otherwise, load n into the tree and make this node the parent
	// Returns the index of n among its siblings
	int addChild(node* n) {
		if (n->parent != NULL) n->parent->removeChild(n->idx);
		n->parent = this;
		children.pushb(n);
		n->idx = children.size - 1;
		return n->idx;
	}
	// Removes the child node at index idx AND all its children from the node tree
	// DOES NOT free the memory of n or its children
	// After removing a child node, it can be reparented as long as it has not been destroyed or freed
	// Returns the number of children (not including the children of this node's children) after removing the given child node
	int removeChild(int idx) {

		return children.size;
	}
	// Returns the child node with name 'n'
	// Returns NULL if this node has no children with name 'n'
	node* getChild(char* n) {

		return NULL;
	}
	// Returns the child stored at index idx
	node* getChild(int idx) {
		return children.get(idx);
	}
};

// A node with a graphic to be drawn
struct visual: node {
	// When set, this node will be drawm
	bool draw = 0;

};
