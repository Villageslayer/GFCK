#include "Mouse.h"
/*
## Github: [Villageslayer](https://github.com/villageslayer)
## UC: [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html)
*/

// Constructor
Mouse::Mouse(GFCK* gfck) : gfck(gfck) {
	// Check Connection
if (!gfck->isOpen())
{
	gfck->open();}

}
// Destructor
Mouse::~Mouse() {
	// Release Mouse Buttons
	gfck->_sendMouse(0, 0, 0, 0);
	gfck->close();
}
// Mouse Click
void Mouse::click(MouseButtons button) {
	gfck->_sendMouse((char)button, 0, 0, 0);
	Sleep(120);
	gfck->_sendMouse(0, 0, 0, 0);
}
// Mouse Press and Hold
void Mouse::press(MouseButtons button) {
	gfck->_sendMouse((char)button, 0, 0, 0);
}
// Mouse Release
void Mouse::release(MouseButtons button) {
	gfck->_sendMouse(0, 0, 0, 0);
}
// Mouse Move Relative
void Mouse::move(int x, int y) {
	gfck->_sendMouse(0, (char)x, (char)y, 0);
}
// Mouse Scroll -> Untested
void Mouse::scroll(int wheel) {
	gfck->_sendMouse(0, 0, 0, (char)wheel);
}
/*
## Github: [Villageslayer](https://github.com/villageslayer)
## UC: [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html)
*/
