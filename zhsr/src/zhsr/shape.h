
struct pt {
	int x, y;
	pt() { x = 0; y = 0; }
	pt(int dx, int dy) { x = dx; y = dy; }
};

struct shape {
	pt pos;
	list<pt*> pts;
	color fill;
	bool draw;
	shape() {
		pos = pt(0,0);
		fill = rgb(255,255,255);
		draw = true;
	}
	virtual color modColor(int x, int y, color c) {}
};

struct tri: shape {
	pt a, b, c;
};