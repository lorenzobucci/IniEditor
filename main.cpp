#include <iostream>
#include "IniFile.h"

int main() {

    IniFile prova;

    prova.newSection("Settings");
    prova.newSection("Foo");
    prova.newKey("audio","off","Settings");
    prova.newKey("video","on","Settings");
    prova.newKey("audio2","on","Settings");
    prova.getSectionList();
    prova.getKeyList("Settings");
    prova.getKeyValue("audio2","Settings");

    prova.renameSection("Settings", "Multimedia");
    prova.getSectionList();

    prova.renameKey("audio2","hdaudio","Settings");
    prova.getKeyList("Settings");

    prova.editKeyValue("audio","on","Settings");
    prova.getKeyValue("audio","Settings");

    prova.deleteSection("Settings");
    prova.getSectionList();

    prova.eraseSection("Foo");
    prova.getSectionList();

    prova.eraseKey("hdaudio");
    prova.getKeyList();

}