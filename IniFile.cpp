#include "IniFile.h"
#include <fstream>

IniFile::IniFile(string fileName) : fileName(fileName) {
    // ifstream myFile (fileName+".ini", ios_base::out);
    newSection("");
}

bool IniFile::newSection(const string& sectionName) {
    if (content.find(sectionName) != content.end()) {
        map<string, string> emptySectionKeys;
        content[sectionName] = emptySectionKeys;
        return true;
    }
    return false;
}

bool IniFile::newKey(const string& name, const string& value, const string& section) {
    auto itr = content.find(section);
    if (itr != content.end()) {
        itr->second[name] = value;
        return true;
    }
    return false;
}

bool IniFile::renameSection(const string& oldName, const string& newName) {
    //TODO
    return false;
}

bool IniFile::renameKey(const string& oldName, const string& newName, const string& section) {
    //TODO
    return false;
}

bool IniFile::editKeyValue(const string& name, const string& newValue, const string& section) {
    auto itr = content.find(section);
    if (itr != content.end()) {
        itr->second[name] = newValue ;
        // FIXME the key must exist!!
        return true;
    }
    return false;
}

bool IniFile::deleteSection(const string& sectionName) {
    auto itr = content.find(sectionName);
    if (itr != content.end()) {
        //FIXME move keys to null section
        content.erase(itr);
        return true;
    }
    return false;
}

bool IniFile::eraseSection(const string& sectionName) {
    auto itr = content.find(sectionName);
    if (itr != content.end()) {
        content.erase(itr);
        return true;
    }
    return false;
}

bool IniFile::eraseKey(const string& name, const string& section) {
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
