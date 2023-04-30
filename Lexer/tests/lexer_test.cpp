#include<catch2/catch_test_macros.hpp>

#include"lexer.h"

#include<istream>
#include<sstream>
#include<iostream>

#if 1


TEST_CASE("Read one character from stream ", "[nextCharacter]"){
    std::string s("a");
    std::stringbuf s_buf(s);

    std::istream input_stream(&s_buf);
    Lexer lexer =  Lexer(input_stream);

    REQUIRE(lexer.getCharacter() == 'a');

}


TEST_CASE("Empty stream returns no char", "[nextCharacter]" ) {
    
    std::string s("");
    std::stringbuf s_buf(s);

    std::istream input_stream(&s_buf);
    Lexer lexer =  Lexer(input_stream);

    REQUIRE( lexer.getCharacter() == false );
}


TEST_CASE("Handle null termination", "[nextCharacter]"){
    std::string s("1234");
    std::stringbuf s_buf(s);

    std::istream input_stream(&s_buf);
    Lexer lexer =  Lexer(input_stream);
    for (int i = 0 ; i < 5 ;i++){
        lexer.nextCharacter();
    }

    REQUIRE( lexer.getCharacter() == false );
}

TEST_CASE("Correct column on first token", "[nextCharacter]"){
    std::string s("Hello world!");
    std::stringbuf s_buf(s);

    std::istream input_stream(&s_buf);
    Lexer lexer =  Lexer(input_stream);
    for (int i = 0 ; i < 4 ;i++){
        lexer.nextCharacter();
    }
    REQUIRE(lexer.getColumn() == 4);

}

TEST_CASE("Correct column after nextToken()", "[nextCharacter]"){
    std::string s("Hello world!");
    std::stringbuf s_buf(s);

    std::istream input_stream(&s_buf);
    Lexer lexer =  Lexer(input_stream);
    for (int i = 0 ; i < 4 ;i++){
        lexer.nextCharacter();
    }
    lexer.nextToken();
    REQUIRE(lexer.getColumn() == 0);
}

TEST_CASE("Maximum column exceded", "[nextCharacter]"){
    std::string s("Hello world!");
    std::stringbuf s_buf(s);

    std::istream input_stream(&s_buf);
    Lexer lexer =  Lexer(input_stream);
    for (int i = 0 ; i <= lexer.MAX_COL ; i++){ // inside constructor is nextCharacter()x1 + MAX_COL > MAX_COL
        lexer.nextCharacter();
    }
    lexer.nextToken();
    REQUIRE(lexer.getColumn() == 0);

}










// tryBuildNumber
TEST_CASE("Build int", "[tryBuildNumber]"){}
TEST_CASE("Build float", "[tryBuildNumber]"){}
TEST_CASE("Handle integer overflow","[tryBuildNumber]"){}


/*
test tryBuildNumber:
- max integer size    231234871693471269581625
- co jeśli cyfra jest zerem i będzie kropka    0.2342313
- co jeśli będzie MAX_INT . coś 234121251251251452345234.
- rozmiar floata  314.4123412  4314231234234.534523 34523523523452345.5

*/ 
#endif