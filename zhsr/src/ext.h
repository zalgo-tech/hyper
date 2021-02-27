#ifndef EXT_H
#define EXT_H

#include <assert.h>

// A series of extensions for c++ functionality.

namespace ops {
	// Constrains a to b, in both positive and negative directions
	template <class T>
	T clamp(T* a, T min, T max) {
		assert(min < max); // Abort if min and max are the same, or if min greater than max
		if (*a < min) *a = min;
		if (*a > max) *a = max;
	}
}

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
	int end = 0;
	// Add new item to start of list
	void pushb(T val) {
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
		end++;
		return;
	}
	// Add new item to end of list
	void pushf(T val) {
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
		end++;
		return;
	}
	// Inserts item at idx and pushes other items up
	void insert(T val, int idx) {
		idx = ops::clamp(&idx, 0, end);
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
		end++;
	}
	// Returns first item and removes it
	T popf() {
		if (first == NULL) { return NULL; }
		T val = first->value;
		if (first->next == NULL) {
			first = NULL;
			last = NULL;
			return val;
		}
		first = first->next;
		return val;
	}
	// Returns last item and removes it
	T popb() {
		if (last == NULL) { return NULL; }
		T val = last->value;
		if (last->prev == NULL) {
			first = NULL;
			last = NULL;
			return val;
		}
		last = last->prev;
		return val;
	}
	void remove(int idx) {
		assert(first != NULL); // Abort if list is empty
		assert(idx >= 0 and idx <= end); // Abort if index out of range
		dlnode<T>* current = first;
		for (int i = 0; i < idx; i++) {
			current = current->next;
		}
	}
	// Returns the first item
	T peekf() {
		if (first == NULL) { return NULL; }
		return first->value;
	}
	// Returns the last item
	T peekb() {
		if (last == NULL) { return NULL; }
		return last->value;
	}
	// Looks for first occurence of val and returns its index
	// If val is not found, returns -1
	int find(T val) {
		dlnode<T>* current = first;
		for (int idx = 0; current != NULL; idx++) {
			if (current->value == val) { return idx; }
			current = current->next;
		}
		return -1;
	}
	T get(int idx) {
		assert(first != NULL); // Abort if list is empty
		assert(idx >= 0 and idx <= end); // Abort if index out of range
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
	int count = 0;
	// Total size of data measured in elements
	int size = 0;
	// Use an existing array or block of memory as the data for this array
	// Takes a pointer and the size of its memory as input
	// Aborts if input data is null or input size is 0
	void use(T* ptr, int s) {
		assert(ptr != NULL);
		assert(s != 0);
		data = ptr;
		size = s;
	}
	// Appends value
	// Returns index of inserted value
	int pushb(T value) {
		size++;
		// Handle an empty array (no memory allocated yet)
		if (data == NULL) {
			data = (T*) malloc(1 * sizeof(T));
			*data = value;
			return 0;
		}
		// Keep track of the previously allocated memory to copy its data
		T* prev = data;
		// Allocate new memory with room for one more element
		data = (T*) malloc((size + 1) * sizeof(T));
		int i = 0;
		// Iterate through all elements, stopping at the index of the newly added memory
		while (i < size - 1) {
			printf("size = %i, index = %i, value = %i\n", size, i, *(prev + i));
			*(data + i) = *(prev + i);
			i++;
		}
		// Fill the new memory with the user defined value
		printf("index = %i, value = %i\n", i, value);
		*(data + i) = value;
		return i;
	}
	// Prepends value, increases proceding items by one index
	// Returns index of inserted value
	int pushf(T value) {
		
		return 0;
	}
	// Inserts value between two indices
	// Returns index of inserted value
	// Aborts if index out of bounds or list empty
	int insert(T value, int idx, int ofs) {

		return 0;
	}
	// Returns value at given index
	// Aborts if index out of bounds or list empty
	T get(int idx) {
		assert(data != NULL);
		assert(idx >= 0 and idx < size);
		return *(data + idx);
	}
	// Sets value at given index
	// Aborts if index out of bounds or list empty
	int set(T value, int idx) {
		assert(data != NULL);
		assert(idx >= 0 and idx < size);
		*(data + idx) = value;
	}
	// Returns index of first occurence of given value
	// If not found, returns -1
	// Aborts if list empty
	int find(T value) {
		assert(data != NULL);
		for (int i = 0; i < size; i++) {
			if (*(data + i) == value) return i;
		}
		return -1;
	}
};
#endif