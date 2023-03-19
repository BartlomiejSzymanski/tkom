#include<fstream>
#include<cstdio>
#include<stdlib.h>
#include<iostream>

#ifndef SCANNER_H
#define SCANNER_H

class Scanner{
    private:
    std::ifstream input_file;
    unsigned source_offset;
    
    
    public:
    Scanner(char const * filename);
    ~Scanner();
    char const next();


};
#endif 