#include "Keyboard.h"
#include <unordered_map>


/*
## Github: [Villageslayer](https://github.com/villageslayer)
## UC: [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html)
*/

Keys charToKey(char c) {
	static std::unordered_map<char, Keys> keyMap = {
		{'a', Keys::a}, {'b', Keys::b}, {'c', Keys::c}, {'d', Keys::d},
		{'e', Keys::e}, {'f', Keys::f}, {'g', Keys::g}, {'h', Keys::h},
		{'i', Keys::i}, {'j', Keys::j}, {'k', Keys::k}, {'l', Keys::l},
		{'m', Keys::m}, {'n', Keys::n}, {'o', Keys::o}, {'p', Keys::p},
		{'q', Keys::q}, {'r', Keys::r}, {'s', Keys::s}, {'t', Keys::t},
		{'u', Keys::u}, {'v', Keys::v}, {'w', Keys::w}, {'x', Keys::x},
		{'y', Keys::y}, {'z', Keys::z},
		{'0', Keys::n0}, {'1', Keys::n1}, {'2', Keys::n2}, {'3', Keys::n3},
		{'4', Keys::n4}, {'5', Keys::n5}, {'6', Keys::n6}, {'7', Keys::n7},
		{'8', Keys::n8}, {'9', Keys::n9},
		{' ', Keys::space}
		
	};

	auto it = keyMap.find(c);
	if (it != keyMap.end()) {
		return it->second;
	}
	return Keys::NONE;
}


Keyboard::Keyboard(GFCK* gfck) : gfck(gfck) {
	if (!gfck->isOpen())
	{
		gfck->open();
	}
}
Keyboard::~Keyboard() {
	gfck->_keyboardUp();
	gfck->close();
}
void Keyboard::press(Keys key) {
	gfck->_sendKeyboard(key, {}, {}, {}, {}, {});
}
void Keyboard::release() {
	gfck->_keyboardUp();
}
void Keyboard::pressAndRelease(Keys key) {
	press(key);
	Sleep(120);
	release();
}
void Keyboard::multiPress(std::vector<Keys> keys) {
	if (keys.size() > 6) {
		return;
	}
	Keys b0 = keys.size() > 0 ? keys[0] : Keys::NONE;
	Keys b1 = keys.size() > 1 ? keys[1] : Keys::NONE;
	Keys b2 = keys.size() > 2 ? keys[2] : Keys::NONE;
	Keys b3 = keys.size() > 3 ? keys[3] : Keys::NONE;
	Keys b4 = keys.size() > 4 ? keys[4] : Keys::NONE;
	Keys b5 = keys.size() > 5 ? keys[5] : Keys::NONE;
	gfck->_sendKeyboard(b0, b1, b2, b3, b4, b5);
}
void Keyboard::typeString(const std::string& str) {
	for (char c : str) {
		Keys key = charToKey(c);
		if (key != Keys::NONE) {
			pressAndRelease(key);
		}
	}
}
void Keyboard::test() {
	std::string testSentence = "the quick brown fox jumps over the lazy dog.";
	typeString(testSentence);
}