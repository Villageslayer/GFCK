// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Mouse.h" // Include Mouse Header
#include "Keyboard.h" // Include Keyboard Header

/*
## Github: [Villageslayer](https://github.com/villageslayer)
## UC: [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html)
*/




int main() {
	bool testKey = false;
	bool testMouse = false;
	int choice;
	GFCK gfck;
	printf("[X]Init Starting[X]\n\n");
	printf("[X]Starting Mouse init\n");
	Mouse mouse(&gfck);
	printf("[+]Mouse init Succesful\n\n");
	Sleep(100);
	printf("[X]Starting Keyboard init\n");
	Keyboard keyboard(&gfck);
	printf("[+]Keyboard init Succesful \n\n");
	printf("[X]Init Complete[X]\n\n");
	printf("Test\n 1:Mouse \n 2:Keyboard \n 3:Both\n");
	std::cin >> choice;

	switch (choice) {
	case 1:
		testMouse = true;
		break;
	case 2:
		testKey = true;
		break;
	case 3:
		testKey = true;
		testMouse = true;
		break;
	default:
		printf("Invalid Choice\n");
		break;
	}

	if (testKey) {
		printf("[~]Press any Key To start Keyboard Testing[~]\n");
		getchar(); // Waits for a key press

		printf("[X]Keyboard Test Starting[X]\n");
		Sleep(2000);
		keyboard.test();
		printf("[+]Keyboard Test Finished[+]\n");

		printf("[~]Press any Key To Continue[~]\n");
		getchar(); // Waits for a key press
	}
	if (testMouse) {
		printf("[~]Press any Key To start Mouse Testing[~]\n");
		getchar(); // Waits for a key press

		printf("[X]Mouse Test Starting[X]\n");
		Sleep(2000);
		printf("[+]Moving \n");
		Sleep(500);
		mouse.move(100, 100);
		printf("[+]Clicking \n");
		Sleep(500);
		mouse.click(MouseButtons::LEFT);
		mouse.click(MouseButtons::RIGHT); // here to stop highlighting
		printf("[+]Scrolling UP \n");
		Sleep(500);
		mouse.scroll(1);
		printf("[+]Scrolling Down\n");
		Sleep(500);
		mouse.scroll(-1);
		printf("[+]Done[+]\n");

		printf("[~]Press any Key To Continue[~]\n");
		getchar(); // Waits for a key press
	}
	Sleep(1000);
	printf("[X]Closing Connection[X]\n\n");
	gfck.close();
	

	return 0;
}




/*
## Github: [Villageslayer](https://github.com/villageslayer)
## UC: [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html)
*/
