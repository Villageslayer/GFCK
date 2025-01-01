#pragma once
#include <Windows.h>
#include <winnt.h>
#include <winternl.h>




enum class Keyboard : UINT8 {
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
    z = 0x1D,
    n1 = 0x1E,
    n2 = 0x1F,
    n3 = 0x20,
    n4 = 0x21,
    n5 = 0x22,
    n6 = 0x23,
    n7 = 0x24,
    n8 = 0x25,
    n9 = 0x26,
    n0 = 0x27,
    enter = 0x28,
    esc = 0x29,
    back_space = 0x2A,
    tab = 0x2B,
    space = 0x2C,
    minus = 0x2D,
    equal = 0x2E,
    square_bracket_left = 0x2F,
    square_bracket_right = 0x30,
    back_slash = 0x31,
    back_slash_ = 0x32,
    column = 0x33,
    quote = 0x34,
    back_tick = 0x35,
    comma = 0x36,
    period = 0x37,
    slash = 0x38,
    cap = 0x39,
    f1 = 0x3A,
    f2 = 0x3B,
    f3 = 0x3C,
    f4 = 0x3D,
    f5 = 0x3E,
    f6 = 0x3F,
    f7 = 0x40,
    f8 = 0x41,
    f9 = 0x42,
    f10 = 0x43,
    f11 = 0x44,
    f12 = 0x45,
    snapshot = 0x46,
    scroll_lock = 0x47,
    pause = 0x48,
    insert = 0x49,
    home = 0x4A,
    page_up = 0x4B,
    del = 0x4C,
    end = 0x4D,
    page_down = 0x4E,
    right = 0x4F,
    left = 0x50,
    down = 0x51,
    up = 0x52,
    numlock = 0x53,
    numpad_div = 0x54,
    numpad_mul = 0x55,
    numpad_minus = 0x56,
    numpad_plus = 0x57,
    numpad_enter = 0x58,
    numpad_1 = 0x59,
    numpad_2 = 0x5A,
    numpad_3 = 0x5B,
    numpad_4 = 0x5C,
    numpad_5 = 0x5D,
    numpad_6 = 0x5E,
    numpad_7 = 0x5F,
    numpad_8 = 0x60,
    numpad_9 = 0x61,
    numpad_0 = 0x62,
    numpad_dec = 0x63,
    apps = 0x65,
    f13 = 0x68,
    f14 = 0x69,
    f15 = 0x6A,
    f16 = 0x6B,
    f17 = 0x6C,
    f18 = 0x6D,
    f19 = 0x6E,
    f20 = 0x6F,
    f21 = 0x70,
    f22 = 0x71,
    f23 = 0x72,
    f24 = 0x73,
    rwin = 0x8C,
    f24_ = 0x94,
    lctrl = 0xE0,
    lshift = 0xE1,
    lalt = 0xE2,
    lwin = 0xE3,
    rctrl = 0xE4,
    rshift = 0xE5,
    ralt = 0xE6,
    rwin_ = 0xE7
};

class GFCK {
public:
    GFCK();
    ~GFCK();
    bool open();
    bool close();
    void move(char button, char x, char y, char wheel);
    bool keyboardDown(Keyboard b0, Keyboard b1, Keyboard b2, Keyboard b3, Keyboard b4, Keyboard b5);
    void keyboardUp();

private:
    struct MOUSE_IO {
        char button;
        char x;
        char y;
        char wheel;
        char unk1;
    };

    HANDLE g_input;
    IO_STATUS_BLOCK g_io;
    bool g_found_mouse;

    bool callmouse(MOUSE_IO* buffer);
    NTSTATUS device_initialize(PCWSTR device_name);
};

