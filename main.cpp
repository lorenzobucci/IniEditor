#include <iostream>
#include "IniFile.h"


int main() {
    IniFile example("C:\\Users\\Lorenzo\\Desktop\\rdpwrap.ini");
    example.newSection("Settings");
    example.newKey("audio", "off", "Settings");
    example.newKey("video", "on", "Settings");
    example.newKey("audio2", "on", "Setting");
    example.save();
    return 0;

}