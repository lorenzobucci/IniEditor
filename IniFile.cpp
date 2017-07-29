#include "IniFile.h"
#include <fstream>

IniFile::IniFile(string fileName) : fileName(fileName) {
    // ifstream myFile (fileName+".ini", ios_base::out);
    newSection("");
}

bool IniFile::newSection(string sectionName) {
    if (content.find(sectionName) != content.end()) {
        map<string, string> emptySectionKeys;
        content[sectionName] = emptySectionKeys;
        return true;
    }
    return false;
}

bool IniFile::newKey(string name, string value, string section) {
    auto itr = content.find(section);
    if (itr != content.end()) {
        itr->second[name] = value;
        return true;
    }
    return false;
}

bool IniFile::renameSection(string oldName, string newName) {
    //TODO
    return false;
}

bool IniFile::renameKey(string oldName, string newName, string section) {
    //TODO
    return false;
}

bool IniFile::editKeyValue(const string name, string& newValue, const string section) {
    auto itr = content.find(section);
    if (itr != content.end()) {
        itr->second[name] = newValue ;
        // FIXME the key must exist!!
        return true;
    }
    return false;
}

bool IniFile::deleteSection(string sectionName) {
    auto itr = content.find(sectionName);
    if (itr != content.end()) {
        //FIXME move keys to null section
        content.erase(itr);
        return true;
    }
    return false;
}

bool IniFile::eraseSection(string sectionName) {
    auto itr = content.find(sectionName);
    if (itr != content.end()) {
        content.erase(itr);
        return true;
    }
    return false;
}

bool IniFile::eraseKey(string name, string section) {
    auto itr = content.find(section);
    if (itr != content.end()) {
        auto itr2 = itr->second.find(name);
            if (itr2 != itr->second.end()) {
                itr->second.erase(itr2);
                return true;
            }
    }
    return false;
}
