# GFCK 
---
# Made by Villageslayer
## Github: [Villageslayer](https://github.com/villageslayer)
## UC: [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html)
---
- ## [Installation](https://www.youtube.com/watch?v=FgNEciqHZFE) <- Youtube Turorial
---
## [Usage:](#usage)

### [Mouse](##Mouse) 
> - [Example](###Example)
> - [Buttons](###Buttons)

### [Keyboard](##Keyboard)
> - [Example](###Example-Use)
> - [Keys](###Keys)
---
---
## Introduction
I was bothered by no Lib existing.

So I made one.

# Usage
## Mouse
### Example
```C++
#include "Mouse.h"
int main() {
	GFCK gfck // Req for Driver Handling 
	Mouse mouse(&gfck); // Init Mouse
	// Mouse Functions
	
	mouse.move(100, 100); //(x,y) relative
	
	mouse.scroll(1); // Scroll up
	mouse.scroll(-1); // Scroll down
	
	mouse.click(MouseButtons::LEFT); // Click sleeps for 120ms
	//OR
	mouse.press(MouseButtons::LEFT); // Press
	Sleep(100); // Custom sleep
	mouse.release(); // Release
```

See API.md for more info.
### Buttons
```C++
enum class MouseButtons : UINT8 {
    LEFT = 1,
    RIGHT = 2,
    MIDDLE = 4,
	LEFT_RIGHT = LEFT | RIGHT,
	LEFT_MIDDLE = LEFT | MIDDLE,
	RIGHT_MIDDLE = RIGHT | MIDDLE,
	ALL = LEFT | RIGHT | MIDDLE
};
```

See API.md for more info.
## Keyboard
### Example Use
```C++
#include "Keyboard.h"
int main() {
	GFCK gfck // Req for Driver Handling 
	Keyboard keyboard(&gfck); // Init Keyboard
	// Keyboard Functions
	keyboard.pressAndRelease(Keys::A); // Press and Release Single Key

	keyboard.multiPress(std::vector<Keys>{Keys::A, Keys::B, Keys::C}); // Press Multiple Keys)
	Sleep(100); // Custom sleep
	keyboard.release(); // Release All Keys

	keyboard.typeString("hello world"); // Type from String -> Lowercase ONLY

	keyboard.test(); // Test Keyboard by Typing a Test Sentence
}
```

See API.md for more info.
### Keys
Basic Use:
`Keys::key` -> `Keys::a`

*All Letters are **Lowercase** and **Single**.*
```C++
enum class Keys : UINT8 {
    a = 0x4,
    b = 0x5,
    c = 0x6,
    d = 0x7,
    e = 0x8,
    f = 0x9,
    g = 0xA,
    h = 0xB,
    i = 0xC,
    j = 0xD,
    k = 0xE,
    l = 0xF,
    m = 0x10,
    n = 0x11,
    o = 0x12,
    p = 0x13,
    q = 0x14,
    r = 0x15,
    s = 0x16,
    t = 0x17,
    u = 0x18,
    v = 0x19,
    w = 0x1A,
    x = 0x1B,
    y = 0x1C,
    z = 0x1D
    // ~Snip~ See GFCK.h for full list
};
```

See API.md for more info.

## Credits
- [ekknod](https://github.com/ekknod) <- For the Logitech CVE
- [0123asdf](https://www.unknowncheats.me/forum/members/2977297.html) <- For the Keyboard Base
- [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html) <- The Lib, API and Docs