#ifndef INIEDITOR_INIEDITOR_H
#define INIEDITOR_INIEDITOR_H


#include <iostream>
#include <map>

using namespace std;

class Ini {

public:
    explicit Ini(string fileName = "default");

private:
    string fileName;
    multimap <string, map> content;


};


#endif
