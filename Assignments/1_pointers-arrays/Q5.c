/* CS261- Assignment 1 - Q.5*/
/* Name: Jacob Karcz
 * Date: 9.29.2016
 * Solution description: Function modifies user input word to alternate cases,
 *                       begining with upper case.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
    int i;
    for(i = 0; word[i]!='\0'; i++ ) {
        if( i % 2 == 0) { //convert these to upper
            if( word[i] >= 'a' && word[i] <= 'z') {
                word[i] = toUpperCase(word[i]);
            }
        }
        else { //convert these to lower
            if( word[i] >= 'A' && word[i] <= 'Z' ) {
                word[i] = toLowerCase(word[i]);
            }
        }
    }
}


int main(){
    /*Read word from the keyboard using scanf*/
    char word[50];
    printf("Enter a word to manipulate with StIcKy CaPs\n");
    scanf("%s", word);
    
    /*Call sticky*/
    sticky(word);
          
    /*Print the new word*/
    printf("Here is your entry with StIcKy CaPs: %s\n\n", word);
          
    return 0;
}
