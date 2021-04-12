#include <iostream>
#include "generator.h"


int main() {
    PasswordGenerator pg;
    pg.setPasswordLength();
    pg.toggleLetters();
    pg.toggleCase();
    pg.toggleLetters();
    pg.toggleNumbers();
    pg.toggleSpecialSymbols();
    pg.toggleLetters();
    pg.togglePunctuation();
    std::cout << pg.generate();



    std::cout << std::endl;

    return 0;
}