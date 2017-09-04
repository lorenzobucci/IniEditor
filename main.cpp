#include <iostream>
#include "IniFile.h"
#include "windows.h"


int main() {
    string dir = getenv("USERPROFILE");
    IniFile example("Example.ini", dir + "\\Desktop", true);
    example.newSection("Settings");
    example.renameSection("Settings","Mul");
    example.newKey("audio", "off", "Settings");
    example.newKey("video", "on", "Settings");
    example.newKey("audio2", "on", "Setting");
    example.save();
    return 0;

}