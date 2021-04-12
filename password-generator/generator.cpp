#include "generator.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

std::string PasswordGenerator::generate() {
    /* initialize random seed: */
    srand (time(NULL));

    std::string password = "";

    std::vector<char> characterList;

    // make one big array
    if (letters_) addToCharacterList(LETTERS_ARRAY_, characterList);
    if (numbers_) addToCharacterList(NUMBERS_ARRAY_, characterList);
    if (special_symbols_) addToCharacterList(SPECIAL_SYMBOLS_, characterList);
    if (punctuation_) addToCharacterList(PUNCTUATION_, characterList);


    for (int i = 0; i < length_; i++) {
        const int characterListSize = characterList.size();
        int randomChar = rand() % characterListSize; 

        char chosenCharacter = characterList[randomChar];

        if (isalpha(chosenCharacter)) {
            if (mix_case_) {
                if (randomChar % 2 == 0) chosenCharacter =toupper(chosenCharacter);
            }
        }

        password += chosenCharacter;

    }
    return password;
}

// Toggles if letters are allowed.
// NOTE: If set to false, numbers MUST be set to true.
void PasswordGenerator::toggleLetters() {
    letters_ = !letters_;
    if (!letters_) {
        numbers_ = true;
        std::cout << "Numbers automatically have been set because letters has been set to false." << std::endl;
    } 
    std::cout << "Letters have been set to " << letters_ << std::endl;
}

// Toggles the case of the letters.
// NOTE: Only applies if letters have been set.
void PasswordGenerator::toggleCase() {
    if (letters_) {
        mix_case_ = !mix_case_;
        std::cout << "Case has been set to " << mix_case_ << std::endl;
    } else {
        std::cout << "Error: Cannot toggle case when letters has not been set." << std::endl;
    }
}

// Toggles if numbers can be used in password.
// NOTE: Only toggles if letters are allowed.
void PasswordGenerator::toggleNumbers() {
    if (!letters_) {
        std::cout << "Cannot toggle numbers since letters is false. Numbers must be set." << std::endl;
    } else {
        numbers_ = !numbers_;
        std::cout << "Numbers have been set to: " << numbers_ << std::endl;
    }
}

// Toggles if special symbols can be used in the password.
void PasswordGenerator::toggleSpecialSymbols() {
    special_symbols_ = !special_symbols_;
    std::cout << "Special symbols has been set to: " << special_symbols_ << std::endl;
}

// Toggles if punctuation can be used in the password.
void PasswordGenerator::togglePunctuation() {
    punctuation_ = !punctuation_;
    std::cout << "Punctuation has been set to: " << punctuation_ << std::endl;
}

// Sets the length of the password.
void PasswordGenerator::setPasswordLength() {

    bool passwordLengthMeetsQualifications = false;
    while (!passwordLengthMeetsQualifications) {
        std::cout << "Enter the length of your password: ";
        int userLength = 0;
        std::cin >> userLength;

        // special cases checks
        const bool onlyNumbersSelected = !letters_ && !special_symbols_ && !punctuation_ && numbers_;
        const bool onlyNumbersAndPunctSelected = !letters_ && !special_symbols_ && punctuation_ && numbers_;

        if (onlyNumbersSelected && userLength >= 13 && userLength <= MAX_PASSWORD_LENGTH_) {
            length_ = userLength;
            passwordLengthMeetsQualifications = true;
            return;
        } else if (onlyNumbersAndPunctSelected && userLength >= 12 && userLength <= MAX_PASSWORD_LENGTH_) {
            length_ = userLength;
            passwordLengthMeetsQualifications = true;
            return;
        } else if (userLength >= MIN_PASSWORD_LENGTH_ && userLength <= MAX_PASSWORD_LENGTH_) {
            length_ = userLength;
            passwordLengthMeetsQualifications = true;
            return;
        } else {
            std::cout << "The password must be in the minimum length (11-64 characters)." << std::endl;
        }

    }
    
}

// Adds a list of characters to characterList. 
void PasswordGenerator::addToCharacterList(std::vector<char>& characters, std::vector<char>& characterList) {
    // loop through characters and place each in characterList.
    for (int i = 0; i < characters.size(); i = i + 1 ) {
        characterList.push_back(characters[i]);
    }
}