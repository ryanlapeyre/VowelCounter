#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
#include <stdbool.h> 
#define WORDLENGTH 50

struct totalVowels
{
    int aLetters;
    int eLetters;
    int iLetters;
    int oLetters;
    int uLetters;
    int totalVowelCount;
};


struct totalVowels performVowelCheck(struct totalVowels , char* inputWord);
int main (void)

{
    char* inputWord = malloc(sizeof(char) * WORDLENGTH);
    struct totalVowels totalVowelsRemote = { 0 , 0 , 0, 0, 0, 0 };
    printf("Please input the word that you wish to check for vowels:");
    scanf("%s" , inputWord);
    totalVowelsRemote = performVowelCheck(totalVowelsRemote, inputWord);
    printf("The total amount of vowels in the word is %d. ", totalVowelsRemote.totalVowelCount);
    printf("There are %d A(s), %d E(s), %d I(s), %d O(s), %d U(s).\n" , totalVowelsRemote.aLetters, totalVowelsRemote.eLetters, totalVowelsRemote.iLetters, 
            totalVowelsRemote.oLetters, totalVowelsRemote.uLetters );

    free(inputWord);
    return 0;
}
struct totalVowels performVowelCheck(struct totalVowels totalVowelsRemote , char* inputWord)
{
    int counter = 0;
    char currentCharacter = 0;
    for(; *(counter + inputWord) != '\0'; counter++)
    {   

        if( isalpha( *( inputWord + counter ) ) ) 
        {
            currentCharacter =  tolower(*( inputWord + counter));
        }


        switch(currentCharacter)
        {

            case 'a':
                totalVowelsRemote.aLetters++;
                totalVowelsRemote.totalVowelCount++;        
                break;

            case 'e':
                totalVowelsRemote.eLetters++;
                totalVowelsRemote.totalVowelCount++;  
                break;

            case 'i':
                totalVowelsRemote.iLetters++;
                totalVowelsRemote.totalVowelCount++;  
                break;

            case 'o':

                totalVowelsRemote.oLetters++;
                totalVowelsRemote.totalVowelCount++;  
                break;

            case 'u':
                totalVowelsRemote.uLetters++;
                totalVowelsRemote.totalVowelCount++;  
                break;

            default :
                continue;
                break;
        }
    }
    return totalVowelsRemote;
}
