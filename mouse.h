#pragma once
#include "GFCK.h"

/*
## Github: [Villageslayer](https://github.com/villageslayer)
## UC: [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html)
*/
class GFCK;
class Mouse {
public:
    Mouse(GFCK* gfck);
    ~Mouse();
    void click(MouseButtons button);
    void press(MouseButtons button);
    void release(MouseButtons button);
    void move(int x, int y);
    void scroll(int wheel);

private:
    GFCK* gfck;
};
/*
## Github: [Villageslayer](https://github.com/villageslayer)
## UC: [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html)
*/
