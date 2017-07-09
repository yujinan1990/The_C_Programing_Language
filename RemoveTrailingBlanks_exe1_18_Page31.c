/* remove the trailing balnks
 * Page31 of The C
 * by Jean 20170702
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 1000

int advance( int pointer)
{
	if( pointer < MAXQUEUE - 1 )
		return pointer + 1;
	else
		return 0;
}

int main( void )
{
	char blank[ MAXQUEUE ];
	int head, tail; /* head,tail, advance(), seems to creat a loop queue */
	int nonspace;
	int retval;
	int c;
	int spaceJustPrinted;

	retval = spaceJustPrinted = nonspace = head = tail = 0;

	while( (c = getchar()) != EOF ){
		if( c ==  '\n' ){
			head = tail = 0;
			if( spaceJustPrinted == 1 )
				retval = EXIT_FAILURE;
			if( nonspace ){
				putchar('\n');
				spaceJustPrinted = 0; 
				nonspace = 0;
			} //fi
		}else if( c == ' ' || c == '\t'){
			if( advance(head) == tail ){
				putchar( blank[tail] );
				tail = advance( tail );
				nonspace = 1;
				retval = EXIT_FAILURE;
			} //fi
			blank[head] = c;
			head = advance( head );
		}else{
			while( head != tail){
				putchar( blank[tail] );
				tail = advance(tail);
			} //while
			putchar( c );
			nonspace = 1;
		}
	} //while
	return retval;
}
