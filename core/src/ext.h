#pragma once

#ifndef EXT_H
#define EXT_H

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

// A series of extensions for c++ functionality.

#ifdef ZALGO_EXT_IO
	#include <stdio.h>
	#ifdef ZALGO_EXT_SILENCE_PRINTF
		#define printf(...)
	#endif
	#ifdef ZALGO_EXT_CONTROL_PRINTF
		#define printf(...) ZALGO_EXT::conditional_printf(__VA_ARGS__)
	#endif
#endif

namespace ZALGO_EXT {
	// Set i to 0 to silence printf
	int (*conditional_printf) (const char*, ...) = printf;
	int silent_printf(const char* _, ...) { return 0; }
	void printf_verbosity(int verbose) {
		if (!verbose) conditional_printf = silent_printf;
		else conditional_printf = printf;
	}
};

template <class T>
struct dlnode { // Doubly linked node
	T value;
	dlnode* next = NULL;
	dlnode* prev = NULL;
};

template <class T>
struct list {
	dlnode<T>* first = NULL;
	dlnode<T>* last = NULL;
	int size = 0;
	// If list is empty, returns true
	bool empty() { return (first == NULL); }
	// Add new item to start of list
	void pushb(T val) {
		size++;
		dlnode<T>* add = new dlnode<T>;
		add->value = val;
		if (first == NULL) {
			first = add;
			last = add;
			return;
		}
		last->next = add;
		add->prev = last;
		last = add;
		return;
	}
	// Add new item to end of list
	void pushf(T val) {
		size++;
		dlnode<T>* add = new dlnode<T>;
		add->value = val;
		if (last == NULL) {
			first = add;
			last = add;
			return;
		}
		first->prev = add;
		add->next = first;
		first = add;
		return;
	}
	// Inserts item 'val' at index 'idx' and pushes other items up
	// Does nothing if index out of range
	// If list empty, inserted item becomes first item
	void insert(T val, int idx) {
		if (idx < 0 or idx > size - 1) return;
		size++;
		dlnode<T>* add = new dlnode<T>;
		add->value = val;
		if (first == NULL) {
			first = add;
			last = add;
			return;
		}
		dlnode<T>* current = first;
		for (int i = 0; i < idx - 1; i++) {
			current = current->next;
		}
		dlnode<T>* following = current->next;
		current->next = add;
		add->prev = current;
		add->next = following;
	}
	// Returns first item and removes it
	// Returns NULL if list empty
	T popf() {
		if (first == NULL) return NULL;
		size--;
		T val = first->value;
		if (first->next == NULL) {
			first = NULL;
			last = NULL;
			return val;
		}
		dlnode<T>* rem = first;
		first = first->next;
		free(rem);
		return val;
	}
	// Returns last item and removes it
	// Returns NULL if list empty
	T popb() {
		if (last == NULL) return NULL;
		size--;
		T val = last->value;
		if (last->prev == NULL) {
			free(last);
			first = NULL;
			last = NULL;
			return val;
		}
		dlnode<T>* rem = last;
		last = last->prev;
		free(rem);
		return val;
	}
	// Returns the item at index 'idx' and removes it
	// Returns NULL if index out of range or list empty
	T remove(int idx) {
		if (idx < 0 or idx > size - 1) return NULL;
		if (first == NULL) return NULL;
		size--;
		dlnode<T>* current = first;
		for (int i = 0; i < idx; i++) {
			current = current->next;
		}
		T val = current->value;
		if (current->prev == NULL) {
			if (current->next == NULL) {
				first = NULL;
				last = NULL;
				free(current);
				return val;
			}
			first = current->next;
			free(current);
			return val;
		}
		if (current->next == NULL) {
			if (current->prev == NULL) {
				first = NULL;
				last = NULL;
				free(current);
				return val;
			}
			last = current->prev;
			free(current);
			return val;
		}
		current->prev->next = current->next;
		current->next->prev = current->prev;
		free(current);
		return val;
	}
	// Returns the first item
	// Returns NULL if list empty
	T peekf() {
		if (first == NULL) return NULL;
		return first->value;
	}
	// Returns the last item
	// Returns NULL if list empty
	T peekb() {
		if (last == NULL) return NULL;
		return last->value;
	}
	// Looks for first occurence of value 'val' and returns its index
	// Returns -1 if value not found
	// Returns NULL if list empty
	int find(T val) {
		if (first == NULL) return NULL;
		dlnode<T>* current = first;
		for (int idx = 0; current != NULL; idx++) {
			if (current->value == val) return idx;
			current = current->next;
		}
		return -1;
	}
	// Returns item at index 'idx'
	// Returns NULL if index out of range or list empty
	T get(int idx) {
		if (idx < 0 or idx > size - 1) return NULL;
		if (first == NULL) return NULL;
		dlnode<T>* current;
		current = first;
		for (int i = 0; i < idx; i++) {
			if (current != NULL) current = current->next;
		}
		if (current == NULL) return NULL;
		return current->value;
	}
};

template <class T>
struct array {
	// Block of memory containing all elements and any extra allocated space
	T* data = NULL;
	// Number of elements currently stored
	unsigned int count = 0;
	// Total size of data measured in elements
	unsigned int size = 0;
	array() {}
	// Use an existing array or block of memory to initialize the data for this array
	// Takes a pointer 'ptr', the total size of the block 's', and the number of stored elements 'e'
	// Does nothing if 'ptr' is NULL or size is 0
	// Does not free previous data block
	void use(T* ptr, int s, int e) {
		T* newData = (T*) malloc(s * sizeof(T));
		memcpy(newData, ptr, e);
		data = newData;
		count = e;
		size = s;
	}
	// Returns true if number of elements stored is 0, or size is 0, or data is NULL
	bool empty() { return (count == 0 or size == 0 or data == NULL); }
	// Appends value
	// Returns index of inserted value
	// Returns -1 if memory insufficient
	int pushb(T value) {
		count++;
		// Handle an empty array (no memory allocated yet)
		if (data == NULL) {
			data = (T*) malloc(1 * sizeof(T));
			*data = value;
			return 0;
		}
		// If there is room for the new element, avoid resizing
		if (count <= size) {
			*(data + count) = value;
			return count;
		}
		size++;
		// Attempt to resize data block
		T* resize = (T*) realloc(data, size * sizeof(T));
		// If resize failed, reset count and size to their original values and return
		if (resize == NULL) {
			count--;
			size--;
			return -1;
		} else {
			data = resize;
		}
		// If the resize was successful, simply fill the new memory
		*(data + count) = value;
		return count;
	}
	// Prepends value, increases proceding items by one index
	// Returns index of inserted value
	// Returns -1 if memory insufficient
	int pushf(T value) {
		count++;
		// Handle an empty array (no memory allocated yet)
		if (data == NULL) {
			data = (T*) malloc(1 * sizeof(T));
			*data = value;
			return 0;
		}
		// If there is no room for the new element, resize
		if (count > size) {
			size++;
			// Attempt to resize current data block
			T* resize = (T*) realloc(data, size * sizeof(T));
			// If resize failed, allocate a new block and copy the data from the current block to the new block
			if (resize == NULL) {
				count--;
				size--;
				return -1;
			} else {
				data = resize;
			}
		}
		// Set first element
		*(data + 0) = value;
		return count;
	}
	// Inserts value at given index
	// Returns index of inserted value
	// Returns NULL if index out of bounds or list empty
	int insert(T value, int idx) {

		return 0;
	}
	// Returns value at given index
	// Returns NULL if index out of bounds or list empty
	T get(int idx) {
		return *(data + idx);
	}
	// Sets value at given index
	// Aborts if index out of bounds or list empty
	int set(T value, int idx) {
		
		*(data + idx) = value;
		return idx;
	}
	// Returns index of first occurence of given value
	// Returns -1 if not found
	// Returns NULL if list empty
	int find(T value) {
		assert(data != NULL);
		for (int i = 0; i < size; i++) {
			if (*(data + i) == value) return i;
		}
		return -1;
	}
	#ifdef ZALGO_EXT_IO
	void dump() {
		for (int i = 1; i < size; i++) {
			printf("index %i, value %i\n",i,get(i - 1));
		}
	}
	#endif
};

struct tree {
	tree* parent = NULL;
	int idx = -1;
	list<tree*> children;
	// Free all memory for this node AND all of its children RECURSIVELY
	// Effectively destroys an entire node tree or a branch of a node tree
	// Returns the number of nodes that were deallocated
	int destroy() {
	}
	// If n is in the tree, reparent n to this node
	// Otherwise, load n into the tree and make this node the parent
	// Returns the index of n among its siblings
	int addChild(tree* n) {
		if (n->parent != NULL) n->parent->removeChild(n->idx);
		n->parent = this;
		n->idx = children.size;
		children.pushb(n);
		return n->idx;
	}
	// Removes the child node at index idx AND all its children from the node tree
	// DOES NOT free the memory of n or its children
	// After removing a child node, it can be reparented as long as it has not been destroyed or freed
	// Returns the number of children (not including the children of this node's children) after removing the given child node
	int removeChild(int idx) {
		tree* child = children.get(idx);
		child->parent = NULL;
		child->idx = -1;
		children.remove(child->idx);
		return children.size;
	}
	// Returns the child stored at index idx
	tree* getChild(int idx) {
		return children.get(idx);
	}
};

struct grid {
	T* data = NULL;
	int w, h;
	grid() {}
	grid(int nw, int nh) {
		w = nw; h = nh;
		data = (T*) malloc(w * h * sizeof(T));
	}
	grid (int nw, int nh, T* ndata) {
		w = nw; h = nh;
		if (data != NULL) free(data);
		data = ndata;
	}
	void set(int x, int y, T value) {
		int idx = (y * w) + x;
		data[idx] = T;
	}
};

#endif