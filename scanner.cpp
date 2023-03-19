#include"scanner.h"


Scanner::Scanner(char const * filename){
    input_file.open(filename);
    if (input_file.eof()){
        input_file.close();
        std::cout << "End of file" << std::endl;
    }

}
Scanner::~Scanner(){
    input_file.close();
}

char const Scanner::next(){
    char character;
    input_file.get(character);

    if (input_file.eof()) return EOF;
    else return character;

}



