/* Exercise 1-12 of The C Programing Lauguage on page 23
 * prints inputs one word per line
 * by Jean 20170620
 */

#include <stdio.h>

int main()
{	/*read stdin and put each per line */
	int c;
	int inspace;
	
	inspace = 0;

	while( ( c = getchar() ) != EOF ){
		if( c == '\t' || c == ' ' || c == '\n'){	//' ' not " "
			if( inspace == 0 ){
				inspace = 1;
				putchar('\n');
			}else{
				;// good, if the cursor is in space, the next getchar is white means they are contineous space which we should ignore
			}//if
		}else{
			inspace = 0;
			putchar( c );
		}
	}//while
	
	return 0;

}
