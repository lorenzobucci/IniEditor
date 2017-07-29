#include <iostream>
#include "Ini.h"

int main() {

    Ini prova;
    prova.newSection("Settings");
    prova.newKey("audio","off","Settings");
    prova.newKey("video","on","Settings");
    prova.newKey("audio2","on","Setting");

}