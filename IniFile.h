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


private:
    string fileName;
    map <string, map <string,string> > content;


};


#endif
