#include "IniFile.h"
#include <fstream>

IniFile::IniFile(string fileName) : fileName(fileName) {
    // ifstream myFile (fileName+".ini", ios_base::out);
    newSection(nullptr);
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
    if (!findKey(name, section) && findSection(section)) {
        content.at(section)[name] = value;
        return true;
    }
    return false;
}

bool IniFile::renameSection(const string& oldName, const string& newName) {
    if (findSection(oldName)) {
        if (newSection(newName)) {
            for (auto itr2 = content.at(oldName).begin(); itr2 != content.at(oldName).end(); itr2++)
                newKey(itr2->first, itr2->second, newName);
            content.erase(oldName);
            return true;
        }
    }
    return false;
}

bool IniFile::renameKey(const string& oldName, const string& newName, const string& section) {
    if (findKey(oldName)) {
        if (newKey(newName,content.at(section).at(oldName),section)) {
            content.at(section).erase(oldName);
            return true;
        }
    }
    return false;
}

bool IniFile::editKeyValue(const string& name, const string& newValue, const string& section) {
    if (findKey(name,section)) {
        content.at(section).at(name) = newValue;
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
        content.at(section).erase(name);
        return true;
    }
    return false;
}

bool IniFile::findSection(const string &sectionName) const {
    if (content.find(sectionName) != content.end())
        return true;
    return false;
}

bool IniFile::findKey(const string &name, const string &section) const {
    if (findSection(section)){
        if (content.at(section).find(name) != content.at(section).end())
            return true;
    }
    return false;
}

string IniFile::getKeyValue(const string &name, const string &section) const {
    if(findKey(name, section))
        return content.at(section).at(name);
    return nullptr;
}

vector<string>& IniFile::getKeyList(const string &sectionName) const {
    auto *keyList = new vector <string>;
    for (auto itr = content.at(sectionName).begin(); itr != content.at(sectionName).end(); itr++)
        keyList->push_back(itr->first);
    return *keyList;
}

vector<string>& IniFile::getSectionList() const {
    auto *sectionList = new vector <string>;
    for (auto itr = content.begin(); itr != content.end(); itr++)
        sectionList->push_back(itr->first);
    return *sectionList;
}
