#pragma once
#include "GFCK.h"
#include <vector>
class GFCK;

class Keyboard {
public:
	Keyboard(GFCK* gfck);
	~Keyboard();
	void press(Keys key);
	void release();
	void multiPress(std::vector<Keys> keys);
	void pressAndRelease(Keys key);
	void typeString(const std::string& str);
	void test();
private:
	GFCK* gfck;
};

/*
## Github: [Villageslayer](https://github.com/villageslayer)
## UC: [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html)
*/
/*
## Github: [Villageslayer](https://github.com/villageslayer)
## UC: [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html)
*/
