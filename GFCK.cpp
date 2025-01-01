// GFCK.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "mouse.h"

int main()
{
	GFCK gfck;
    std::cout << "Created\n";
	gfck.open();
	std::cout << "Opened\n";
	Sleep(2000);
	std::cout << "Typing\n";
	gfck.move(1, 0, 0, 0);
	Sleep(120);
	gfck.move(0, 0, 0, 0);
	Sleep(2000);
	gfck.keyboardDown({ Keyboard::a }, {}, {}, {}, {}, {});
	gfck.keyboardDown({ Keyboard::s }, {}, {}, {}, {}, {});
	gfck.keyboardUp();
	gfck.keyboardDown({ Keyboard::s }, {}, {}, {}, {}, {});
	gfck.keyboardUp();
	Sleep(2000);
	gfck.close();
	std::cout << "Closed\n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
