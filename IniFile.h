#ifndef INIEDITOR_INIEDITOR_H
#define INIEDITOR_INIEDITOR_H


#include <iostream>
#include <map>

using namespace std;

class IniFile {

public:
    explicit IniFile(string fileName = "default");
    bool newSection (string sectionName);
    bool newKey (string name, string value, string section = nullptr);
    bool renameSection (string oldName, string newName);
    bool renameKey (string oldName, string newName, string section = nullptr);
    bool editKeyValue (string name, string& newValue, string section = nullptr);
    bool deleteSection (string sectionName);
    bool eraseSection (string sectionName);
    bool eraseKey (string name, string section = nullptr);


private:
    string fileName;
    map <string, map <string,string> > content;


};


#endif
