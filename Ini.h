#ifndef INIEDITOR_INIEDITOR_H
#define INIEDITOR_INIEDITOR_H


#include <iostream>
#include <map>

using namespace std;

class Ini {

public:
    explicit Ini(string fileName = "default");
    void newSection (string sectionName);
    bool newKey (string name, string value, string section = nullptr);

private:
    string fileName;
    map <string, map <string,string> > content = { { nullptr, { { nullptr, nullptr } } } };


};


#endif
