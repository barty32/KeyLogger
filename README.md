# KeyLogger
A keystroke logger for Windows, written in 25 lines of C code

Logs keystrokes into a file called KeyLog.txt in format "timestamp> virtualKeyCode | scanCode | asciiCharacter".
This is done by installing a Low level keyboard hook using Windows API.
