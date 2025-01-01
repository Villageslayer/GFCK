#include <ntstatus.h>
#include <windows.h>
#include <winternl.h>
#include "mouse.h"
#pragma comment(lib, "ntdll.lib")

GFCK::GFCK() : g_input(NULL), g_found_mouse(false) {}

GFCK::~GFCK() {
    close();
}

bool GFCK::callmouse(MOUSE_IO* buffer) {
    IO_STATUS_BLOCK block;
    return NtDeviceIoControlFile(g_input, 0, 0, 0, &block, 0x2a2010, buffer, sizeof(MOUSE_IO), 0, 0) == 0L;
}

NTSTATUS GFCK::device_initialize(PCWSTR device_name) {
    UNICODE_STRING name;
    OBJECT_ATTRIBUTES attr;

    RtlInitUnicodeString(&name, device_name);
    InitializeObjectAttributes(&attr, &name, 0, NULL, NULL);

    NTSTATUS status = NtCreateFile(&g_input, GENERIC_WRITE | SYNCHRONIZE, &attr, &g_io, 0,
        FILE_ATTRIBUTE_NORMAL, 0, 3, FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT, 0, 0);

    return status;
}

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

bool GFCK::close() {
    if (g_input != NULL) {
        NTSTATUS status = NtClose(g_input);
        g_input = NULL;
        return NT_SUCCESS(status);
    }
    return false; // Handle was already NULL
}

void GFCK::move(char button, char x, char y, char wheel) {
    MOUSE_IO io;
    io.unk1 = 0;
    io.button = button;
    io.x = x;
    io.y = y;
    io.wheel = wheel;

    if (!callmouse(&io)) {
        close();
        open();
    }
}

bool GFCK::keyboardDown(Keyboard b0, Keyboard b1, Keyboard b2, Keyboard b3, Keyboard b4, Keyboard b5) {
    struct KEYBOARD_IO {
        UINT8 unknown0;
        UINT8 unknown1;
        Keyboard button0;
        Keyboard button1;
        Keyboard button2;
        Keyboard button3;
        Keyboard button4;
        Keyboard button5;
    };
    static_assert(sizeof(KEYBOARD_IO) == 8, "Size of KEYBOARD_IO must be 8 bytes");

    KEYBOARD_IO buffer{ {},{},b0,b1,b2,b3,b4,b5 };

    IO_STATUS_BLOCK block;
    return NT_SUCCESS(NtDeviceIoControlFile(g_input, 0, 0, 0, &block, 0x2A200C, &buffer, sizeof(KEYBOARD_IO), 0, 0));
}
void GFCK::keyboardUp() {
	keyboardDown({}, {}, {}, {}, {}, {});
}