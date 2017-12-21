/* CS261- Assignment 2 - stackapp.c */
/* Name: Jacob Karcz
 * Date: 10.04.2016
 * Solution description: Stack-based program that checks if the opening and closing 
 *                       braces on a string are balanced. The string arguement should be
 *                       typed into the terminal directly following the command to run.
 */

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post: return 1 (T) if string is balanced, otherwise returns 0 (F)
*/
int isBalanced(char* s)
{
    struct DynArr *stack = newDynArr(100);
    char c;
    c = nextChar(s);
    
    while (c != '0') {
        if ( ( c == '(' ) || ( c == '[' ) || ( c == '{' ) )
            pushDynArr(stack, c); //push openeing braces to the stack
        else if ( ( c == ')' ) || ( c == ']' ) || ( c == '}' ) ) {
            if (c == ')' && !isEmptyDynArr(stack) && topDynArr(stack) == '(')
                popDynArr(stack); //pop matching ')' from the stack
            else if (c == ']' && !isEmptyDynArr(stack) &&  topDynArr(stack) == '[')
                popDynArr(stack); //pop matching ']' from the stack
            else if (c == '}' && !isEmptyDynArr(stack) &&  topDynArr(stack) == '{')
                popDynArr(stack); //pop matching '}' from the stack
            else {
                deleteDynArr(stack);
                return 0; // no matching opening brace
            }
        }
        c = nextChar(s); //bring in the next char
    }
    
    if (!isEmptyDynArr(stack)) {
        deleteDynArr(stack);
        return 0; // some opening braces are missing a buddy
    }
    else {
        deleteDynArr(stack);
        return 1; // all braces are paired off
    }
}

/* Receives a string arguement to pass to isBalanced(char*s) and prints out the result
	param: 	a string arguement to check for opening/closing braces
	pre: a string to test
	post: prints out whther or not the string's parentheses and braces are balanced
 */
int main(int argc, char* argv[]){
	
	char *s = argv[1];
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

