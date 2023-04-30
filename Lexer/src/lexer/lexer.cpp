#include"lexer.h"
#include<iostream>
#include<optional>
#include<limits>
#include<variant>

Lexer::Lexer(std::istream & source) : _source_stream(source){
    _token = false;
    nextCharacter();
    }

Lexer::~Lexer(){
}

int Lexer::getColumn(){
    return _column;
}
std::optional<char> Lexer::getCharacter(){
    return _character;
}

void Lexer::nextCharacter(){  // 
    char character;
    _source_stream.get(character);
    if( !_source_stream.eof() ){
        _character = character;
    }
    else{
        _character = false;
    } 
    

    // tutaj column 
    // _source_stream.eof();
    //funkcja sprawdzająca stan źródła
}

std::variant<std::string,int, double, bool> Lexer::nextToken(){
    return false;

}


// refaktoring, poszczególne
bool Lexer::tryBuildNumber(){
    // if (!std::isdigit(_character)) return false;

    // int digit = _character - '0';
    // int token_value = 0;
    
    // if (digit != 0){

    //     while (std::isdigit(_character)){ // digit 1-9

    //         digit = _character - '0'; 
    //         try{
    //             //czy to int czy unsigned int
    //             if ((std::numeric_limits<int>::max()  - (digit))/10 > token_value){token_value = token_value*10 + digit;}
    //             else throw _character; 
    //             //std::numeric_limits<float>::max() 
    //             // value;
    //             // digit;
    //             //value *10 +digit <= 100
    //             /*
    //             value <= (100 - digit)/10
    //             */
     
    //         }
    //         // tutaj nie throw , tylko od razu wykonać kod
    //         catch (char character){
    //             std::cout << "Temporary solution" <<std::endl;
    //         // tutaj tworzymy nowy obiekt błędu, musimy mieć handlera
    //         }
    //         nextCharacter();
    //     }
    //     _token = std::make_unique<Token>(new Token(token_value)); // WYRZUCIĆ
    // }
    //     if (_character == '.'){
    //         nextCharacter();

    //         //if (token_value > ) std::cout << "ERROR, temporary solution" << std::endl;
    //         // We float_32 significand ma 23 bity. Czyli trzeba sprawdzić
    //         // FLT_MAX == 3.4*10^38

    //         float decimal_value;

    //         while (std::isdigit(_character)){
    //             try{
    //                 double digit_position = 0.1;


    //                 // im większa liczba tym mniejsza dokładność
    //                 // int . -> 
    //                 // 
    //                                               // (14.323 - 0.006)*10 = 143.17            
    //                 if (token_value  < (std::numeric_limits<double>::max()  - digit*digit_position)*10){ // tego nie jestem pewien 
    //                     // na platformie x86 nie używa się float, oszczędzamy 4 bajty na liczbie
    //                     // Używać float tylko jesli float jest szybszy niż double, ale double jest tak samo wydajny jak float
    //                     // 
    //                     digit_position = digit_position/10;
    //                     token_value += digit * digit_position;
    //                 }
    //                 else throw _character; 
    //             }

    //             catch (char character){
    //                 std::cout << "Temporary solution" <<std::endl;
    //                 // tutaj tworzymy nowy obiekt błędu, musimy mieć handlera
    //             }
    //             nextCharacter();

    //         }


    //     }
    //     else

    //     if (_character == 'e' || _character == 'E'){
    //         bool minus = false;
    //         nextCharacter();

    //         if (_character == '-'){
    //             minus = true;
    //             nextCharacter();
    //         }
    //         else if (_character == '+'){
    //             minus = false;
    //             nextCharacter();
    //         }
    //         if ( !std::isdigit(_character) ){
    //             //ERROR
    //         }
    //         while(std::isdigit(_character)){
    //             digit = _character - '0'; 
    //             try{
    //                 if ((INT32_MAX - (digit))/10 > token_value){token_value = token_value*10 + digit;}
    //                 else throw _character; 
    //             }
    //             catch (char character){
    //                 std::cout << "Temporary solution" <<std::endl;
    //             // tutaj tworzymy nowy obiekt błędu, musimy mieć handlera
    //             }
    //             nextCharacter();
    //         }

    //         //Token(exponent)
    //     }
    
    //_token = new Token(token_value); // position
    return false;
}
// bool Lexer::tryBuildComment(){}
// bool Lexer::tryBuildString(){}
// bool Lexer::tryBuildWord(){}
// bool Lexer::tryBuildSimpleToken(){}






