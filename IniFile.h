#ifndef INIEDITOR_INIEDITOR_H
#define INIEDITOR_INIEDITOR_H


#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

class IniFile {

public:
    explicit IniFile(const string& fileName, const string& folder = "");
    explicit IniFile(const string& filePath);

    virtual ~IniFile();

    void save();

    bool newSection (const string& sectionName);
    bool newKey (const string& name, const string& value, const string& section = "");

    bool renameSection (const string& oldName, const string& newName);
    bool renameKey (const string& oldName, const string& newName, const string& section = "");
    bool editKeyValue (const string& name, const string& newValue, const string& section = "");
    bool moveKey (const string& name, const string& oldSection, const string& newSection);

    bool deleteSection (const string& oldSection, const string& destSection = "");
    bool eraseSection (const string& sectionName);
    bool eraseKey (const string& name, const string& section = "");

    string getKeyValue (const string& name, const string& section = "") const;
    vector<string>& getKeyList (const string& sectionName = "") const;
    vector<string>& getSectionList () const;


private:
    map <string, map <string,string> > content;

    bool findSection (const string& sectionName) const;
    bool findKey (const string& name, const string& section = "") const;

    fstream file;

};


#endif
