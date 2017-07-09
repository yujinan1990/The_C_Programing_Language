/* Check a C program fro rudimentary syntax errors like unmatched parentheses, brackets, and braces. 
 * exercise 1-24 Page 34 of The C
 * by Jean 20170708
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 1024

enum {
	CODE, /*nothing of the following */
	COMMENT, /* inside a comment */
	QUOTE1, /* inside ' ' */
	QUOTE2, /* inside " " */
	}; //enum
	
int
main()
{
	int ch;
	int state = CODE;
	char stack[ MAX_STACK ];
	size_t top = 0; /* point to the top of stack */
	size_t line = 1;
	int error = 0; /* for OK message */

	while( ( ch = getchar() ) != EOF ){
		if( ch == '\n' ){
			line++;
		} //fi

		switch (state){
			case CODE:
				if( ch == '\''){
					state = QUOTE1;
				}else if( ch == '"' ){
					state = QUOTE2;
				}else if( ch == '/' ){
					int second = getchar();
					if( second = '*' ){
						state = COMMENT;
					}else{
						ungetc( second , stdin );
					}
				}else if( ch == '(' || ch == '[' || ch == '{' ){
					if( top < MAX_STACK ){
						stack[top++] = ch;
					}else{
					printf( "stack too small!\n ");
					return EXIT_FAILURE;
					}
				}else if( ch == ')' || ch == ']' || ch == '}' ){
					if( top == 0){
						printf( " Line %ul: Closing '%c' found without counterpart. \n ", (unsigned long) line, ch);
						error = 1;
					}else{
						char open = stack[--top];
						if( ( ch == ')' && open != '(' ) || ( ch == ']' && open != '[') || ( ch == '}' && open != '{')){
							printf( "Line %ul, closing '%C'  doesn't match opening '%c'. \n ", (unsigned long) line, ch,open);
							error = 1;
						} //fi
					}
				}
				break;
			case QUOTE1:
				if( ch == '\\'){
					(void)getchar(); /* an escaped char inside ''throw it away; */
				}else if( ch == '\''){
					state = CODE; 
				}
				break;
			case QUOTE2:
				if( ch == '\\'){
					(void)getchar(); /* an escaped char inside "" throw it away; */
				}else if( ch == '"'){
					state = CODE;
				}
				break;
		} //switch
	} //while

	if( state == COMMENT ){
		printf( "Code stop inside comment!\n ");
	}else if( state == QUOTE1){
		printf( "Code ends inside single quotes !\n ");
	}else if( top == 0 && error == 0){
		printf( "Code seems to be OK!\n");
	}
	if( top > 0){
		size_t i;
		for( i = 0; i < top ; i++ ){
			printf( "opening %c found without counterpart. \n ", stack[i]);
		}//for
	} //fi
	
	return 0;
} //main
