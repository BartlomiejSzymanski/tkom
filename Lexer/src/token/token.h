#include<stdlib.h>
#include<variant>
#include<string>

#ifndef TOKEN_H
#define TOKEN_H

class Token{
    private:
    std::variant<std::string, int, float, bool> _value;
    //pozycja
    public:
    Token();

};

#endif