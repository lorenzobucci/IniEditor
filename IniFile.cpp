#include "IniFile.h"
#include <fstream>

IniFile::IniFile(string fileName) : fileName(fileName) {
    ifstream myFile (fileName+".ini", ios_base::out);
}

bool IniFile::newSection(string sectionName) {
    map <string, string> emptySectionKeys;
    content.emplace(sectionName, emptySectionKeys );
}

bool IniFile::newKey(string name, string value, string section) {
    auto itr = content.find(section);
    if( itr != content.end() ) {
        itr->second.emplace(name, value);
        return true;
    }
    return false;
}
