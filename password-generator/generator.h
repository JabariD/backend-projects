#ifndef PASSWORD_GENERATOR
#define PASSWORD_GENERATOR

#include <iostream>
#include <vector>


class PasswordGenerator {
    public:
        // Generates a password based on user parameters.
        std::string generate();

        void setPasswordLength();

        void toggleLetters();
        void toggleCase();
        void toggleNumbers();
        void togglePunctuation();
        void toggleSpecialSymbols();


    private:
        int length_;

        const int MIN_PASSWORD_LENGTH_ = 11; // if all numbers min length is 13. if numbers and punctuation min length is 12.
        const int MAX_PASSWORD_LENGTH_ = 64; 

        bool letters_ = true;
        std::vector<char> LETTERS_ARRAY_ = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        bool mix_case_;

        bool numbers_ = true; // if numbers selected and NOT letters mix_case_ does not apply
        std::vector<char> NUMBERS_ARRAY_ = {'0','1','2','3','4','5','6','7','8','9'};


        bool special_symbols_ = true;
        std::vector<char> SPECIAL_SYMBOLS_ = {'&', '/', '%', '$', '@', '#', '^', '*', '(', ')', '+', '=', '~', '|', '}', '{', '~'};

        bool punctuation_ = true;
        std::vector<char> PUNCTUATION_ = {'.', ',', ':', ';', '?', '!'};

        void addToCharacterList(std::vector<char>& characters, std::vector<char>& characterList);

};

#endif

