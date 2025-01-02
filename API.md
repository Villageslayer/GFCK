
# API 
## Github: [Villageslayer](https://github.com/villageslayer)
## UC: [Villageslayer](https://www.unknowncheats.me/forum/members/3298005.html)
A Diagram:
```
GFCK 
|
+-- Mouse(GFCK*)
|     |
|     +-- move(int x, int y)
|     +-- scroll(int delta) 
|     +-- click(MouseButtons button)
|     +-- press(MouseButtons button)
|     +-- release()
|
+-- Keyboard(GFCK*)
|	|
|	+-- pressAndRelease(Keys key)
|	+-- multiPress(std::vector<Keys> keys)
|	+-- press(Keys key);
|	+-- release();
|	+-- pressAndRelease(Keys key);
|	+-- typeString(const std::string& str);
|	+-- test();

```

## Introduction

## [GFCK -> The Driver Handler](#GFCK)
^^ Handles the Driver Communication and Events. 
For more info Read The Fucking Files.
Functions:
- isOpen
- checkVersion
- open
- close

## [Mouse -> The Mouse API](##Mouse)
Mouse Functions:
- Move
- Scroll
- Click
- Press
- Release



## [Keyboard -> The Keyboard API](#Keyboard)
API for Keyboard Functions
Keyboard Functions:
- Press
- Release
- PressAndRelease
- MultiPress
- TypeString
- Test


# Classes, Enums, Structs
## Classes
> ## GFCK
>> Driver Handler
> ## Mouse
>> Mouse API
> ## Keyboard
>> Keyboard API
## Enums
> ## MouseButtons
>> Mouse Buttons 
> ## Keys
>> Keyboard Keys
## Structs
> ## MOUSE_IO
>> Mouse Data Struct
> ## KEYBOARD_IO
>> Keyboard Data Struct

# GFCK
## Public Methods
>  ## isOpen -> bool
>>	Checks if The Connection has been made 
> ## checkVersion -> bool
>> Checks if the correct Version of GHUB is installed
>> by checking the contents of `C:\\Program Files\\LGHUB\\version`
>> returns true if the version is `13.1.4`.
> ## open -> bool
>> Opens the Connection to the Driver
> ## close -> bool
>> Closes the Connection to the Driver

## Internal Methods
__These Methods are meant for internal use only__
> ## _sendMouse -> Void
>> ### Input : char button, char x, char y, char wheel
>> Packages Input into MOUSE_IO and Sends Mouse Event to the Driver 
> ## _sendKeyboard -> Void
>> ### Input : Keys b0, Keys b1, Keys b2, Keys b3, Keys b4, Keys b5
>> Packages Input into KEYBOARD_IO and Sends Keyboard Event to the Driver
> ## _keyboardUp-> Void
>> Releases all Pressed Keys 

# Mouse
## Public Methods
> ## move -> Void
>> ### Input : int x, int y
>> Moves the Mouse to the Relative Position (x,y)
> ## scroll -> Void
>> ### Input : int delta
>> Scrolls the Mouse Wheel by delta 
>> Positive delta Scrolls Up.
>> Negative delta Scrolls Down
> ## click -> Void
>> ### Input : MouseButtons button
>> Presses and Releases the Given Button with a delay of 120ms
> ## press -> Void
>> ### Input : MouseButtons button
>> Presses the Given Button
> ## release -> Void
>> Releases the last Pressed Button

# Keyboard
## Public Methods
> ## pressAndRelease -> Void
>> ### Input : Keys key
>> Presses and Releases the Given Key
> ## press -> Void
>> ### Input : Keys key
>> Presses the Given Key
> ## multiPress -> Void
>> ### Input : std::vector<Keys> keys
>> Presses the Given Keys
> ## release -> Void
>> Releases **all** Pressed Keys
> ## typeString -> Void
>> ### Input : const std::string& str <- **MUST BE LOWERCASE**
>> Types the Given String 
> ## test -> Void
>> Types`The quick brown fox jumps over the lazy dog` to Test the Keyboard

# Enums
## MouseButtons
> ### LEFT
> ### RIGHT
> ### MIDDLE
> ### LEFT_RIGHT
> ### LEFT_MIDDLE
> ### RIGHT_MIDDLE
> ### ALL
## Keys
see `GFCK.h` for the full list of Keys

# Structs
## MOUSE_IO

> #### char button
> #### char x
> #### char y
> #### char wheel
> #### char unk1

## KEYBOARD_IO
> #### Keys b0
> #### Keys b1
> #### Keys b2
> #### Keys b3
> #### Keys b4
> #### Keys b5