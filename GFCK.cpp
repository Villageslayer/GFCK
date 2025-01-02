#include <ntstatus.h>
#include <windows.h>
#include <winternl.h>
#include "GFCK.h"
#include <fstream>
#include <string>
#include <iostream>
#pragma comment(lib, "ntdll.lib")

/*
## Github: [Villageslayer](https://github.com/villageslayer)
## UC: [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html)
*/

/*
########################################
PUBLIC FUNCTIONS
########################################
*/


// # Connection Handling

// Open the Connection 
bool GFCK::open() {
    NTSTATUS status = 0;

    if (g_input == NULL) {
        wchar_t buffer0[] = L"\\??\\ROOT#SYSTEM#0002#{1abc05c0-c378-41b9-9cef-df1aba82b015}";

        status = device_initialize(buffer0);
        if (NT_SUCCESS(status)) {
            g_found_mouse = true;
        }
        else {
            wchar_t buffer1[] = L"\\??\\ROOT#SYSTEM#0001#{1abc05c0-c378-41b9-9cef-df1aba82b015}";
            status = device_initialize(buffer1);
            if (NT_SUCCESS(status)) {
                g_found_mouse = true;
            }
        }
    }
    return NT_SUCCESS(status);
}
// Close the Connection
bool GFCK::close() {
    if (g_input != NULL) {
        NTSTATUS status = NtClose(g_input);
        g_input = NULL;
        return NT_SUCCESS(status);
    }
    return false; // Handle was already NULL
}


// # Checks

// Check if the Connection is Open
bool GFCK::isOpen() {
    return g_found_mouse;
}
// Check Version 
bool GFCK::checkVersion() {
    const std::string filePath = "C:\\Program Files\\LGHUB\\version";
    const std::string version = "13.1.4";
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find(version) != std::string::npos) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}


// # Input Handling -> Backend Functions use Respective API

// Send Mouse Input -> Backend Function use Mouse API in Mouse.h
void GFCK::_sendMouse(char button, char x, char y, char wheel) {
    MOUSE_IO io;
    io.unk1 = 0;
    io.button = button;
    io.x = x;
    io.y = y;
    io.wheel = wheel;

    if (!callMouse(&io)) {
        close();
        open();
    }
}
// Send Keyboard Input -> Backend Function use Keyboard API in Keyboard.h
void GFCK::_sendKeyboard(Keys b0, Keys b1, Keys b2, Keys b3, Keys b4, Keys b5) {

    static_assert(sizeof(KEYBOARD_IO) == 8, "Size of KEYBOARD_IO must be 8 bytes");

    KEYBOARD_IO buffer{ {},{},b0,b1,b2,b3,b4,b5 };

    if (!callKeyboard(&buffer)) {
        close();
        open();
    }

}
// Release all Keyboard Keys -> Backend Function use API
void GFCK::_keyboardUp() {
    _sendKeyboard({}, {}, {}, {}, {}, {});
}



/* 
########################################
PRIVATE FUNCTIONS
########################################
*/

// Constructor
GFCK::GFCK() : g_input(NULL), g_found_mouse(false) {

    if (!checkVersion()) {
        std::cerr << "Required version not found." << std::endl;
        // Handle the case where the version is not found
        // For example, you could set a flag or throw an exception
        throw std::runtime_error("Required version not found.");
    }
}

// Destructor
GFCK::~GFCK() {
    close();
}



// # Driver Communication


// Private Device Initialize
NTSTATUS GFCK::device_initialize(PCWSTR device_name) {
    UNICODE_STRING name;
    OBJECT_ATTRIBUTES attr;

    RtlInitUnicodeString(&name, device_name);
    InitializeObjectAttributes(&attr, &name, 0, NULL, NULL);

    NTSTATUS status = NtCreateFile(&g_input, GENERIC_WRITE | SYNCHRONIZE, &attr, &g_io, 0,
        FILE_ATTRIBUTE_NORMAL, 0, 3, FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT, 0, 0);

    return status;
}

// Private Call Mouse 
bool GFCK::callMouse(MOUSE_IO* buffer) {
    IO_STATUS_BLOCK block;
    return NtDeviceIoControlFile(g_input, 0, 0, 0, &block, 0x2a2010, buffer, sizeof(MOUSE_IO), 0, 0) == 0L;
}
// Private Call Keyboard
bool GFCK::callKeyboard(KEYBOARD_IO* buffer) {
    IO_STATUS_BLOCK block;
    return NtDeviceIoControlFile(g_input, 0, 0, 0, &block, 0x2A200C, buffer, sizeof(KEYBOARD_IO), 0, 0);
}

/*
## Github: [Villageslayer](https://github.com/villageslayer)
## UC: [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html)
*/

// # End of File