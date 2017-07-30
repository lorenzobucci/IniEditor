#ifndef INIEDITOR_INIEDITOR_H
#define INIEDITOR_INIEDITOR_H


#include <iostream>
#include <map>

using namespace std;

class IniFile {

public:
    explicit IniFile(string fileName = "default");

    bool newSection (const string& sectionName);
    bool newKey (const string& name, const string& value, const string& section = nullptr);

    bool renameSection (const string& oldName, const string& newName);
    bool renameKey (const string& oldName, const string& newName, const string& section = nullptr);
    bool editKeyValue (const string& name, const string& newValue, const string& section = nullptr);

    bool deleteSection (const string& sectionName);
    bool eraseSection (const string& sectionName);
    bool eraseKey (const string& name, const string& section = nullptr);


private:
    string fileName;
    map <string, map <string,string> > content;

    bool findSection (const string& sectionName);
    bool findKey (const string& name, const string& section = nullptr);


};


#endif
