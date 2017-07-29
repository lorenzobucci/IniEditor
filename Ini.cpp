#include "Ini.h"
#include <fstream>

Ini::Ini(string fileName) : fileName(fileName) {
    ifstream myFile (fileName+".ini", ios_base::out);
}

bool Ini::newSection(string sectionName) {
    map <string, string> emptySectionKeys;
    content.emplace(sectionName, emptySectionKeys );
}

bool Ini::newKey(string name, string value, string section) {
    auto itr = content.find(section);
    if( itr != content.end() ) {
        itr->second.emplace(name, value);
        return true;
    }
    return false;
}
