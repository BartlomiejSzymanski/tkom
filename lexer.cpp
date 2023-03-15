#include<stdio.h>
#include<stdlib.h>

struct Token
{
   int dupa;
};

Token dupa(Token&);


class ILexer{
    private:
    virtual bool setToken() = 0;

    public:
    Token token;
    virtual ~Lexer() = default;
    virtual Token getToken() = 0;
    virtual Token next() = 0;

};


class CommentFilter : ILexer{
    private:
    bool setToken(Token t) override{
        if (this->token = t){
            return true;
        }
        else return false;
    }

    public:
    Token next(){
        while(Lexer.next().getToken()->type ==   TokenType.Comment){
            //do nothing?
        }
        this->setToken(Lexer.token);
    }

    

}



//prawdziwy i właściwy Lexer 
class Lexer : ILexer{
    private:
    //Position Position; // -> 
    Token tryBuildNumber(){
        if(char.isDigit(character)){
            return false;
        }
        
    }
    public:
    Token next(){
        while(Char.IsWhite(Character)){
            //do nothing with it
        }
         // after white chars are rejected here is the point where token starts 
        // tokenPos;


        if (tryBuildNumber() // or tryToBuildSimpleTokens
        || tryBuildIdentOrKeyword() //
        || tryBuildComment() // tryBuildOperOrComment
        || tryBuildString()) return Token; // return succesfuly built token 
        else{
            
        }
    }
     

}


//void onLexerError()  -zaciąga błąd i np:
                    // dorzucić do kolekcji, kolejki błędów, przetłumaczyć na message. Wszystko poza logiką leksera
//można też stworzyć class ErrorManager     

//tokenizacja ma się odbywać leniwie
