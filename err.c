In file included from src/hyper.h:4,
                 from src/main.cc:1:
src/ext.h: In function ‘char* inpf(int, char*)’:
src/ext.h:12:10: warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
   12 |   return "";
      |          ^~
In file included from src/hyper.h:5,
                 from src/main.cc:1:
src/primitive.h: At global scope:
src/primitive.h:3:2: error: ‘uint8_t’ does not name a type; did you mean ‘u_int8_t’?
    3 |  uint8_t r, g, b, a;
      |  ^~~~~~~
      |  u_int8_t
src/primitive.h: In member function ‘color color::gray()’:
src/primitive.h:6:3: error: ‘uint8_t’ was not declared in this scope; did you mean ‘u_int8_t’?
    6 |   uint8_t gry = (r + g + b) / 3
      |   ^~~~~~~
      |   u_int8_t
src/primitive.h:7:20: error: ‘struct color’ has no member named ‘g’
    7 |   aux.r = gry; aux.g = gry; aux.b = gry;
      |                    ^
src/primitive.h:7:24: error: ‘gry’ was not declared in this scope; did you mean ‘gray’?
    7 |   aux.r = gry; aux.g = gry; aux.b = gry;
      |                        ^~~
      |                        gray
src/primitive.h:7:33: error: ‘struct color’ has no member named ‘b’
    7 |   aux.r = gry; aux.g = gry; aux.b = gry;
      |                                 ^
src/primitive.h: In member function ‘color color::invert()’:
src/primitive.h:12:7: error: ‘struct color’ has no member named ‘r’
   12 |   aux.r = 1 - r; aux.g = 1 - g; aux.b = 1 - b;
      |       ^
src/primitive.h:12:15: error: ‘r’ was not declared in this scope
   12 |   aux.r = 1 - r; aux.g = 1 - g; aux.b = 1 - b;
      |               ^
src/primitive.h:12:22: error: ‘struct color’ has no member named ‘g’
   12 |   aux.r = 1 - r; aux.g = 1 - g; aux.b = 1 - b;
      |                      ^
src/primitive.h:12:30: error: ‘g’ was not declared in this scope
   12 |   aux.r = 1 - r; aux.g = 1 - g; aux.b = 1 - b;
      |                              ^
src/primitive.h:12:37: error: ‘struct color’ has no member named ‘b’
   12 |   aux.r = 1 - r; aux.g = 1 - g; aux.b = 1 - b;
      |                                     ^
src/primitive.h:12:45: error: ‘b’ was not declared in this scope
   12 |   aux.r = 1 - r; aux.g = 1 - g; aux.b = 1 - b;
      |                                             ^
src/primitive.h: At global scope:
src/primitive.h:18:13: error: expected ‘)’ before ‘r’
   18 |  rgb(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
      |     ~       ^~
      |             )
src/primitive.h:24:13: error: expected ‘)’ before ‘h’
   24 |  hsv(uint8_t h, uint8_t s, uint8_t v) {}
      |     ~       ^~
      |             )
In file included from src/hyper.h:5,
                 from src/main.cc:1:
src/primitive.h:85:2: error: expected ‘;’ after struct definition
   85 | }
      |  ^
      |  ;
src/primitive.h:95:8: error: ISO C++ forbids declaration of ‘rect3’ with no type [-fpermissive]
   95 |  rect3() { x = 0; y = 0; z = 0; w = 0; h = 0; d = 0; }
      |        ^
src/primitive.h:96:66: error: ISO C++ forbids declaration of ‘rect3’ with no type [-fpermissive]
   96 |  rect3(double x, double y, double z, double w, double h, double d) {
      |                                                                  ^
src/primitive.h:108:16: error: ‘rect3’ is not a type
  108 |  bool encloses(rect3 rect) {
      |                ^~~~~
src/primitive.h:130:2: error: expected ‘;’ after struct definition
  130 | }
      |  ^
      |  ;
src/primitive.h: In member function ‘int rec3::rect3()’:
src/primitive.h:95:54: warning: no return statement in function returning non-void [-Wreturn-type]
   95 |  rect3() { x = 0; y = 0; z = 0; w = 0; h = 0; d = 0; }
      |                                                      ^
src/primitive.h: In member function ‘int rec3::rect3(double, double, double, double, double, double)’:
src/primitive.h:99:2: warning: no return statement in function returning non-void [-Wreturn-type]
   99 |  }
      |  ^
src/primitive.h: In member function ‘bool rec3::encloses(int)’:
src/primitive.h:112:11: error: ‘TL’ was not declared in this scope; did you mean ‘TB’?
  112 |   return (TL and BR);
      |           ^~
      |           TB
src/primitive.h:112:18: error: ‘BR’ was not declared in this scope
  112 |   return (TL and BR);
      |                  ^~
src/primitive.h: In member function ‘vec3 rec3::ebs()’:
src/primitive.h:115:2: warning: no return statement in function returning non-void [-Wreturn-type]
  115 |  }
      |  ^
src/primitive.h: In member function ‘vec3 rec3::ets()’:
src/primitive.h:117:2: warning: no return statement in function returning non-void [-Wreturn-type]
  117 |  }
      |  ^
src/primitive.h: In member function ‘vec3 rec3::ebn()’:
src/primitive.h:119:2: warning: no return statement in function returning non-void [-Wreturn-type]
  119 |  }
      |  ^
src/primitive.h: In member function ‘vec3 rec3::etn()’:
src/primitive.h:121:2: warning: no return statement in function returning non-void [-Wreturn-type]
  121 |  }
      |  ^
src/primitive.h: In member function ‘vec3 rec3::wbs()’:
src/primitive.h:123:2: warning: no return statement in function returning non-void [-Wreturn-type]
  123 |  }
      |  ^
src/primitive.h: In member function ‘vec3 rec3::wts()’:
src/primitive.h:125:2: warning: no return statement in function returning non-void [-Wreturn-type]
  125 |  }
      |  ^
src/primitive.h: In member function ‘vec3 rec3::wbn()’:
src/primitive.h:127:2: warning: no return statement in function returning non-void [-Wreturn-type]
  127 |  }
      |  ^
src/primitive.h: In member function ‘vec3 rec3::wtn()’:
src/primitive.h:129:2: warning: no return statement in function returning non-void [-Wreturn-type]
  129 |  }
      |  ^
src/primitive.h: At global scope:
src/primitive.h:147:13: error: invalid constructor; you probably meant ‘grid<T> (const grid<T>&)’
  147 |  grid(grid g) {
      |             ^
In file included from src/hyper.h:6,
                 from src/main.cc:1:
src/object.h:13:15: warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
   13 |  char* name = "";
      |               ^~
src/object.h: In member function ‘int node::addChild(node*)’:
src/object.h:24:2: warning: no return statement in function returning non-void [-Wreturn-type]
   24 |  }
      |  ^
In file included from src/main.cc:1:
src/hyper.h: At global scope:
src/hyper.h:10:2: error: expected ‘;’ after struct definition
   10 | }
      |  ^
      |  ;
src/main.cc: In function ‘int main(int, char**)’:
src/main.cc:4:17: error: conversion from ‘Hyper*’ to non-scalar type ‘Hyper’ requested
    4 |  Hyper engine = new Hyper;
      |                 ^~~~~~~~~
