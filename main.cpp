#include "scanner.h"


int main(void){

    Scanner scanner = Scanner("test.txt");
    
    while (true){
        char character = scanner.next();

        if (character == EOF) break;
        else std::cout<< character << std::endl;

    }   


    
}