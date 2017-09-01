#include <iostream>
#include "IniFile.h"


int main() {
    IniFile example("rdpwrp.ini","C:\\Users\\Lorenzo\\Desktop");
    example.newSection("Settings");
    example.newSection("Foo");
    example.newKey("a","off");
    example.newKey("audio","off","Settings");
    example.newKey("video","on","Settings");
    example.newKey("audio2","on","Settings");
    example.save();
    return 0;

}