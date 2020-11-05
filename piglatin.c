#include <string.h> 
#include <stdio.h>
#include <stdbool.h>

//checks if letter is a vowel
bool isVowel(char c) {
    if(c == "a" || c == "e" || c == "i" || c = "o" || c == "u") {
        return true; 
    }
    else {
        return false; 
    }
}

char *word_to_pig_latin(const char *word) {
    //first we make the first letter lowercase if it is uppercase
    (isupper(word[0]) > 0) ? tolower(word[0]) : (word[0] = word[0]);

    //if it is a vowel, add way
    if(isVowel(word[0]) {
        //makes more room for "way" and null
        word = realloc(word, strlen(word)+4);
        strcat(word, "way");
        return word;
    }

    //if it isnt a vowel, 
    else {
        //creates new string with correct size, here, we need "ay" and the null
        const char *piglatin_word = calloc(strlen(word)+3, sizeof(char));

        //This makes sure that y doesn't get counted as a vowel if it is first in the word
        int j = 0;
        do {
            //keeps going until it finds vowel or y, j is the number it stops at
            j ++;
        } while(isVowel(word[j]) != true && word[j] != "y");

        //This will be the last part of the piglatin word, including the consonants and the "ay"
        
        const char *lastpart = calloc(j+3, sizeof(char));
        //Copies j amount of characters from beginning
        strncopy(lastpart, word, j); 
        strcat(lastpart, "ay");

        const char *firstpart = calloc((strlen(word) - j )+ 1, sizeof(char));

        //now we will copy the vowels into the piglatin word
        for(int i = j, int k = 0; i < strlen(word) && k < strlen(word); i ++, k++) {
            piglatin_word[k] = word[i];
        }

        strcat(piglatin_word, lastpart);
        return piglatin_word;
    }
}

