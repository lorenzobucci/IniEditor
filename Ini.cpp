#include "Ini.h"
#include <fstream>

Ini::Ini(string fileName) : fileName(fileName) {
    ifstream myFile (fileName+".ini", ios_base::out);
}
