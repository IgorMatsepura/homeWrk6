#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


const int ALL_NUMBER_LETTER = 26;           // letter in alphabet
const int WORDS = 3;                        // if letters >3 its word
const int NUMBERLETTER = 100000;            // Number of characters entered

void arrayFull(char input[] , int alphabet[]);      // function add number of letter
void outputLetter(char input[], int alphabet[]);    // function Search letter and count of letter
void outputWords(char input[]);                     // function Search counts words
int verifyMalloc (int sizeMalloc);                  // function verify memory for letter;

int main()
{
int  letterAlphabet[ALL_NUMBER_LETTER];     // array number letter
char letterInput[NUMBERLETTER];             // array of characters entered
int  i,j,sizeLetter;                        // Counters
char* memLetter;                            //init memory for array

    verifyMalloc(NUMBERLETTER);

    for (;;){
        memset(letterAlphabet, 0, sizeof(letterAlphabet));
        printf("Enter some string: ");
        gets(letterInput);
        sizeLetter = strlen(letterInput);

        if (sizeLetter == NULL){
            printf("Please of characters entered...Retry again...\n");
            continue;
        }
        // Search letter and count sum of letter
        arrayFull(letterInput ,letterAlphabet);
        // Symbol output and condition matching
        outputLetter(letterInput ,letterAlphabet);
        // Search words in strings
        if (sizeLetter == NULL || sizeLetter > WORDS){
            outputWords(letterInput);
            continue;
        }
    }
    free(memLetter);
}


void arrayFull(char input[] , int alphabet[]){          // function add number of letter
    int i;                                              // variable
    char letter;                                        // One Letter of array

    for (i = 0; i < strlen(input); i++){
        if (isalpha(input[i]))
        {
            letter = tolower(input[i]);
            alphabet[ letter - 'a' ] ++;
        }
    }
}

void outputLetter(char input[], int alphabet[]){        // function Search letter and count of letter
    int i;
    int j;

    for (i = strlen(input); i > 0 ; i-- ){
        for ( j = 0; j < ALL_NUMBER_LETTER; j++){
            if (alphabet[j] == i)
            {
                printf("%c - %d\n", char(j + int('a')), alphabet[j]);
            }
        }
    }
}

void outputWords(char input[]){                         // function Search counts words
    int i;
    int wordsNumber;

    for (i = 0, wordsNumber = 0; input[i] != '\0';){
        for (;!isalpha(input[i]) && input[i] != '\0'; i++) ;
            if (isalpha(input[i])){
                wordsNumber++;
                for (;isalpha(input[i]); i++);
            }
    }
    printf("The worlds is a string: %d \n"  , wordsNumber);
}


int verifyMalloc (int sizeMalloc){                          //function verify memory for letter;
    char* memLetter;

    memLetter = (char*)malloc(sizeMalloc*sizeof(char));
    if ((char*)malloc(sizeMalloc*sizeof(char))== NULL) {
        printf ("Memory allocation error...");
        return 1;
    }
}
