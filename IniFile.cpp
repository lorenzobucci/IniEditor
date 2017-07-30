#include "IniFile.h"
#include <fstream>

IniFile::IniFile(string fileName) : fileName(fileName) {
    // ifstream myFile (fileName+".ini", ios_base::out);
    newSection("");
}

bool IniFile::newSection(const string& sectionName) {
    if (!findSection(sectionName)) {
        map<string, string> emptySectionKeys;
        content[sectionName] = emptySectionKeys;
        return true;
    }
    return false;
}

bool IniFile::newKey(const string& name, const string& value, const string& section) {
    if (findKey(name, section)) {
        (content[section])[name] = value;
        return true;
    }
    return false;
}

bool IniFile::renameSection(const string& oldName, const string& newName) {
    if (findSection(oldName)) {
        if (newSection(newName)) {
            for (auto itr2 = content[oldName].begin(); itr2 != content[oldName].end(); itr2++)
                newKey(itr2->first, itr2->second, newName);
            content.erase(oldName);
            return true;
        }
    }
    return false;
}

bool IniFile::renameKey(const string& oldName, const string& newName, const string& section) {
    if (findKey(oldName)) {
        if (newKey(newName,(content[section])[oldName],section)) {
            content[section].erase(oldName);
            return true;
        }
    }
    return false;
}

bool IniFile::editKeyValue(const string& name, const string& newValue, const string& section) {
    if (findKey(name,section)) {
        (content[section])[name] = newValue;
        return true;
    }
    return false;
}

bool IniFile::deleteSection(const string& sectionName) {
    return renameSection(sectionName,"");
}

bool IniFile::eraseSection(const string& sectionName) {
    if (findSection(sectionName)) {
        content.erase(sectionName);
        return true;
    }
    return false;
}

bool IniFile::eraseKey(const string& name, const string& section) {
    if (findKey(name, section)) {
        content[section].erase(name);
        return true;
    }
    return false;
}

bool IniFile::findSection(const string &sectionName) {
    auto itr = content.find(sectionName);
    if (itr != content.end()){
        return true;
    }
    return false;
}

bool IniFile::findKey(const string &name, const string &section) {
    if (findSection(section)){
        if (content[section].find(name) != content[section].end())
            return true;
    }
    return false;
}
