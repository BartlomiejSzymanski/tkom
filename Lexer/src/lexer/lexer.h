#include"token.h"
#include<istream>
#include<cstdio>
#include<stdlib.h>
#include<optional>
#include<variant>


#ifndef LEXER_H
#define LEXER_H

class Lexer{
    private:
    // std::optional<Token> _token; // do wyrzucenia
    std::variant<std::string, int, double, bool> _token;
    std::istream & _source_stream; 
    std::optional<char> _character;
    int _column;
    // można trzymać position jako <row, col>
    //linia w /n /r
    //column  

    public:

    int const MAX_COL = 20;

    std::optional<char> getCharacter();
    int getColumn();
    Lexer(std::istream & source);
    ~Lexer();

    std::variant<std::string, int, double, bool> nextToken();
    void nextCharacter();
    bool tryBuildNumber();

    // bool tryBuildComment();
    // bool tryBuildWord();
    // bool tryBuildString();
    // bool tryBuildSimpleToken();
};

#endif 