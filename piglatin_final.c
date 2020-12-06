#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
bool isVowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true; 
    }
    else {
        return false; 
    }
}

char *word_to_pig_latin(const char *word) {
    // your code here!
    char* newWord = calloc((strlen(word)+4), sizeof(char));
    strcpy(newWord, word);

    //first we make the first letter lowercase if it is uppercase
    if(isupper(word[0])) {
        newWord[0] = tolower(word[0]);
    }
    
    //if it is a vowel, add way
    if(isVowel(newWord[0])) {
        //makes more room for "way" and null
        if(isupper(word[0])) {
            newWord[0] = toupper(newWord[0]);   
        }
        return strcat(newWord, "way");
    }

    //if it isnt a vowel, 
    else {
        //creates new string with correct size, here, we need "ay" and the null

        //This makes sure that y doesn't get counted as a vowel if it is first in the word
        int j = 0;
        do {
            //keeps going until it finds vowel or y, j is the number it stops at
            j ++;
        } while(!isVowel(word[j]) && word[j] != 'y');

        //This will be the last part of the piglatin word, including the consonants and the "ay"
        
        char *lastpart = calloc(j+3, sizeof(char));
        //Copies j amount of characters from beginning
        strncpy(lastpart, word, j); 
        strcat(lastpart, "ay");
        lastpart[0] = tolower(lastpart[0]);

        //copy the vowels into the piglatin word
        int k = 0;
        for(int i = j; word[i]; i ++, k++) {
            newWord[k] = word[i];
        }
        newWord[k] = '\0';

        strcat(newWord, lastpart);

        if(isupper(word[0])) {
            newWord[0] = toupper(newWord[0]);
        }
        
        return newWord;
    }
}

void test_pig_latin() {
    const char *cases[][2] = {
        { "exit", "exitway" },
        { "Yellow", "Ellowyay" },
        { "scram", "amscray" },
        { "blue", "ueblay" },
        { "Type", "Ypetay" },
        { "igloo", "iglooway" },
        { "Float", "Oatflay" },
        { "bandanda",  "andandabay" },
        { "Apple", "Appleway" },
        
        // feel free to add more cases above this line,
        // but leave the { NULL, NULL } line intact.
        { NULL, NULL }
    };
    
    size_t i = 0;
    int failed_cases = 0, passed_casses = 0;
    while(1) {
        const char *original = cases[i][0];
        const char *expected_latin = cases[i][1];
        
        if(!original || !expected_latin) {
            break;
        }
        
        char *actual_latin = word_to_pig_latin(original);
        
        if(!actual_latin || strcmp(expected_latin, actual_latin) != 0) {
            printf("Test case failed: expected '%s' -> '%s', but got '%s'\n", original, expected_latin, actual_latin);
            
            failed_cases++;
        }
        else {
            passed_casses++;
        }
        
        free(actual_latin);
        
        i++;
    }
    
    printf("%d/%d cases passed\n", passed_casses, failed_cases + passed_casses);
}

int main(int argc, char *argv[]) {
    test_pig_latin();
    
    return 0;
}

