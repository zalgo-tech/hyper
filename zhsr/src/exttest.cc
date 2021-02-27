#include <cstdlib>
#include <cstdio>
#include "ext.h"

int main(int argc, char** argv) {
	array<int> l;
	l.pushb(23);
	l.pushb(25);
	int idx = 0;
	int g = l.find(234);
	int item2 = *(l.data + 1);
	printf("index %i = %i\n", idx, g);
	return 0;
}