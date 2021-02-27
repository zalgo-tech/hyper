
struct obj {
	// Called by engine when this node is added to a tree
	// It is not called if the node is moved within one or more trees
	void init() {}
	// Called by engine when receiving user input
	void input() {}
	// Called by engine along with draw of each frame
	void frame() {}
};

struct node: obj {
	char* name = "";
	node* parent = NULL;
	int idx;
	list<node*> children;
	// If n is in the tree, reparent n to this node
	// Otherwise, load n into the tree and make this node the parent
	// Returns the index of n among its siblings
	int addChild(node* n) {
		n->parent = this;
		children.pushb(n);
		n->idx = children.end;
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
