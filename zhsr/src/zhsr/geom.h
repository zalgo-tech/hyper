
namespace geom {
	// Takes two points and returns the distance between them
	double dist(pt a, pt b) {
		int dxSq = pow(b.x-a.x, 2);
		int dySq = pow(b.y-a.y, 2);
		return sqrt(abs(dxSq + dySq));
	}
	// Takes three side lengths of a triangle and returns the angle corresponding to c
	double angle(double a, double b, double c) {
		double numerator = pow(c,2) - pow(a,2) - pow(b,2);
		double denominator = -2 * a * b;
		double ang = acos(round(numerator) / round(denominator));
		return ang;
	}
	template <class T>
	int mini(T* itms, int length){
		int idx = 0;
		for(int i = 0; i < length; i++) {
			if (*(itms + i) < *(itms + idx)) {
				idx = i;
			}
		}
		return idx;
	}
	template <class T>
	T minv(T* itms, int length){
		T tmp = *(itms + 0);
		for(int i = 0; i < length; i++) {
			if (*(itms + i) < tmp) {
				tmp = *(itms + i);
			}
		}
		return tmp;
	}
	template <class T>
	int maxi(T* itms, int length){
		int idx = 0;
		for(int i = 0; i < length; i++) {
			if (*(itms + i) > *(itms + idx)) {
				idx = i;
			}
		}
		return idx;
	}
	template <class T>
	T maxv(T* itms, int length){
		T tmp = *(itms + 0);
		for(int i = 0; i < length; i++) {
			if (*(itms + i) > tmp) {
				tmp = *(itms + i);
			}
		}
		return tmp;
	}
	template <class T>
	int aGTb(const void* a, const void* b) { // a greater than b?
		T A = *( (T*) a);
		T B = *( (T*) b);
		if (A > B) return 1;
		else return -1;
	}
	template <class T>
	int aLTb(const void* a, const void* b) {
		return (-1 * aGTb<T>(a, b));
	}
	template <class T>
	void swap(T* a, T* b) {
		T temp = *a;
		*a = *b;
		*b = temp;
	}
	void sortTriByX(pt* pts) {
		pt* a = &(*(pts + 0));
		pt* b = &(*(pts + 1));
		pt* c = &(*(pts + 2));
		if (b->x < a->x) swap(b, a);
		if (c->x < a->x) swap(c, a);
		if (c->x < b->x) swap(c, b);
	}
	double slope(pt a, pt b) {
		double dy = b.y - a.y;
		double dx = b.x - a.x;
		return (dy / dx);
	}
	double yitc(double m, int x, int y) {
		return (y - round(m * x));
	}
	double yitc(double m, pt p) {
		return (p.y - round(m * p.x));
	}
};

