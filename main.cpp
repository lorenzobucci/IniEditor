#include <iostream>
#include "IniFile.h"

int main() {

    IniFile prova;
    prova.newSection("Settings");
    prova.newKey("audio","off","Settings");
    prova.newKey("video","on","Settings");
    prova.newKey("audio2","on","Setting");

}