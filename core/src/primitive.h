
struct color {
	uint8_t r, g, b, a;
	color gray() {
		color aux;
		uint8_t gry = (r + g + b) / 3
		aux.r = gry; aux.g = gry; aux.b = gry;
		return aux;
    }
	color invert() {
		color aux;
		aux.r = 1 - r; aux.g = 1 - g; aux.b = 1 - b;
		return aux;
	}
};

struct rgb: color {
	rgb(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
		r = r; g = g; b = b; a = a;
	}
};

struct hsv: color {
	hsv(uint8_t h, uint8_t s, uint8_t v) {}
};

struct vec2 {
	double x, y;
	vec2() { x = 0; y = 0; }
	vec2(double x, double y) { x = x; y = y; }
};

// Two dimensional rectangle (square / rectangle)
// Positive x direction goes right
// Positive y direction goes down
struct rect2: vec2 {
	// width (x) and height (y)
	double w, h;
	rect2() { x = 0; y = 0; w = 0; h = 0; }
	rect2(double x, double y, double w, double h) {
		x = x; y = y;
		w = w; h = h;
	}
	// Whether a given point falls inside this rect, including points that fall directly on edges or corners
	bool encloses(vec2 pt) {
		bool ex = pt.x >= x and pt.x <= x + w;
		bool ey = pt.y <= y and pt.y >= y - h;
		return (ex and ey);
	}
	// Whether the given rect is completely enclosed by this rect, including points of the given rect that fall directly on edges or corners
	bool encloses(rect2 rect) {
		bool TL = rect.tl().x >= x and rect.tl().y <= y;
		bool BR = rect.bl().x <= (x + w) and rect.bl().y >= (y - h);
		return (TL and BR);
	}
	vec2 tl() { return vec2(x,y); } // Top left
	vec2 tr() { // Top right
		vec2 c {x,y};
		c.x += w;
		return c;
	}
	vec2 bl() { // Bottom left
		vec2 c {x,y};
		c.y -= h;
		return c;
	}
	vec2 br() { // Bottom right
		vec2 c {x,y};
		c.x += w;
		c.y -= h;
		return c;
	}
	vec2 center() { // Center
		vec2 c {x,y};
		c.x += w / 2;
		c.y -= h / 2;
		return c;
	}
};

struct vec3 {
	double x, y, z;
	vec3() { x = 0; y = 0; z = 0; }
	vec3(double x, double y, double z) { x = x; y = y; z = z; }
}

// 3-dimensional rectangle (cube / rectangular prism)
// Origin is bottom east south corner
// Positive x direction goes east
// Positive y direction goes up
// Positive z direction goes north
struct rec3: vec3 {
	// width (x), height (y), and depth (z)
	double w, h, d;
	rect3() { x = 0; y = 0; z = 0; w = 0; h = 0; d = 0; }
	rect3(double x, double y, double z, double w, double h, double d) {
		x = x; y = y; z = z;
		w = w; h = h; d = d;
	}
	// Whether a given point falls inside this rect, including points that fall directly on edges or corners
	bool encloses(vec3 pt) {
		bool ex = pt.x >= x and pt.x <= x + w;
		bool ey = pt.y >= y and pt.y <= y + h;
		bool ez = pt.z >= z and pt.z <= z + d;
		return (ex and ey and ez);
	}
	// Whether the given rect is completely enclosed by this rect, including points of the given rect that fall directly on edges or corners
	bool encloses(rect3 rect) {
		bool NS; // North and south
		bool EW; // East and west
		bool TB; // Top and bottom
		return (TL and BR);
	}
	vec3 ebs() { // East bottom south corner
	}
	vec3 ets() { // East top south corner
	}
	vec3 ebn() { // East bottom north corner
	}
	vec3 etn() { // East top north corner
	}
	vec3 wbs() { // West bottom south corner
	}
	vec3 wts() { // West top south corner
	}
	vec3 wbn() { // West bottom north corner
	}
	vec3 wtn() { // West top north corner
	}
}

// Data structure for storing two-dimensional data such as bitmaps or graph points
template <class T>
struct grid {
	// width and height
	int w, h;
	// block of memory with grid data
	T* data;
	// Points data to a new block of memory based on current width and height
	// Frees the memory currently pointed to by data
	grid() {
		if (data != NULL) { free(data); }
		data = (T*) malloc(w * h * sizeof(T));
	}
	// Points data to an existing block of memory
	// Frees the memory currently pointed to by data
	grid(grid g) {
		if (data != NULL) { free(data); }
		data = g;
	}
	// Returns size in elements of this grid
	// (This can simply be found by multiplying width and height)
	int size() { return w * h; }
	// Returns the value stored at a given column x of row y
	T get(int x, int y) {
		return *(data + (w * y) + x);
	}
	// Sets the value stored at a given column x of row y
	void set(int x, int y, T data) {
		*(data + (w * y) + x) = data;
	}
};

struct bitmap: grid<color> {};