#include <cstdlib>
#include <cstring>
#include "IniFile.h"

IniFile::IniFile(const string &fileName, const string &folder, bool newFile) {
    newSection("");

    filePath = folder + "\\" + fileName;
    if (newFile) {
        file.open(filePath, fstream::out);
        if (!file.is_open())
            exit(2);
    } else {
        file.open(filePath, fstream::in);
        if (!file.is_open())
            exit(2);

        string lastSection = "";
        for (int line = 1; !file.eof(); line++) {
            string lineStr;
            getline(file, lineStr);
            char *cLineStr = &lineStr[0u];

            if (strchr(cLineStr, 91) != nullptr) {
                char *cstr = strtok(cLineStr, "[]");
                newSection(cstr);
                lastSection = cstr;
            } else if (strchr(cLineStr, 61) != nullptr) {
                char *ckey = strtok(cLineStr, "=");
                char *cvalue = strtok(nullptr, "=");
                newKey(ckey, cvalue, lastSection);
            }
        }
    }
}

IniFile::~IniFile() {
    file.close();
}

bool IniFile::newSection(const string &sectionName) {
    if (!findSection(sectionName)) {
        map<string, string> emptySectionKeys;
        content[sectionName] = emptySectionKeys;
        return true;
    }
    return false;
}

bool IniFile::newKey(const string &name, const string &value, const string &section) {
    if (findSection(section) && !findKey(name, section)) {
        content.at(section)[name] = value;
        return true;
    }
    return false;
}

bool IniFile::renameSection(const string &oldName, const string &newName) {
    if (findSection(oldName) && !oldName.empty()) {
        if (newSection(newName)) {
            for (auto itr2 = content.at(oldName).begin(); itr2 != content.at(oldName).end(); itr2++)
                newKey(itr2->first, itr2->second, newName);
            eraseSection(oldName);
            return true;
        }
    }
    return false;
}

bool IniFile::renameKey(const string &oldName, const string &newName, const string &section) {
    if (findKey(oldName, section)) {
        if (newKey(newName, content.at(section).at(oldName), section)) {
            content.at(section).erase(oldName);
            return true;
        }
    }
    return false;
}

bool IniFile::editKeyValue(const string &name, const string &newValue, const string &section) {
    if (findKey(name, section)) {
        content.at(section).at(name) = newValue;
        return true;
    }
    return false;
}

bool IniFile::moveKey(const string &name, const string &oldSection, const string &newSection) {
    if (findKey(name, oldSection)) {
        if (!findKey(name, newSection))
            newKey(name, content.at(oldSection).at(name), newSection);
        else
            editKeyValue(name, content.at(oldSection).at(name), newSection);
        eraseKey(name, oldSection);
        return true;
    }
    return false;
}

bool IniFile::deleteSection(const string &oldSection, const string &destSection) {
    if (findSection(oldSection) && findSection(destSection) && !oldSection.empty()) {
        for (const auto &key : content.at(oldSection))
            moveKey(key.first, oldSection, destSection);
        eraseSection(oldSection);
        return true;
    }
    return false;
}

bool IniFile::eraseSection(const string &sectionName) {
    if (findSection(sectionName) && !sectionName.empty()) {
        content.erase(sectionName);
        return true;
    }
    return false;
}

bool IniFile::eraseKey(const string &name, const string &section) {
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
    if (findSection(section)) {
        if (content.at(section).find(name) != content.at(section).end())
            return true;
    }
    return false;
}

string IniFile::getKeyValue(const string &name, const string &section) const {
    if (findKey(name, section))
        return content.at(section).at(name);
    return nullptr;
}

vector<string> &IniFile::getKeyList(const string &sectionName) const {
    if (findSection(sectionName)) {
        auto *keyList = new vector<string>;
        for (const auto &key : content.at(sectionName))
            keyList->push_back(key.first);
        return *keyList;
    }
}

vector<string> &IniFile::getSectionList() const {
    auto *sectionList = new vector<string>;
    for (const auto &section : content)
        sectionList->push_back(section.first);
    return *sectionList;
}

void IniFile::save() {

    file.close();
    file.open(filePath, fstream::out);
    if (!file.is_open())
        exit(2);

    if (!content.at("").empty()) {
        for (const auto &key : content.at(""))
            file << key.first << "=" << key.second << "\n";
        file << "\n";
    }

    for (const auto &section : content) {
        if (!section.first.empty()) {
            file << "[" << section.first << "]" << "\n";
            for (const auto &key : content.at(section.first))
                file << key.first << "=" << key.second << "\n";
            file << "\n";
        }
    }

}
