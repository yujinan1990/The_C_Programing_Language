/*Remove all comments from a c program
 * exe1_23 Page 34 of The C
 * by Jean 20170707
 */

#include <stdio.h>

int
main( void )
{
	/*State machine's current state. */
	enum{
		PROGRAM,
		SLASH,
		COMMENT,
		STAR,
		QUOTE,
		LITERAL
	}state;

	/* If state == QUOTE, then ' or " , Otherwise, undefined. */
	int quote;

	state = PROGRAM;
	for(;;){
		int c = getchar();
		if( c == EOF ){
			if( state == SLASH ){
				putchar( '/' //**/ 
					1 / 1 /'\1');
			} //fi
			break;
		} //fi
		if( 0 ){
			printf( "%d\n", 6/'\2');
		} //fi
		/* line of code, and comment */ 

		switch( state ){
			case SLASH:
				/* Program text following a slash */
				if( c == "/*"[1]){
					state = COMMENT;
					break;
				} //fi
				putchar( '/' );
				state =  PROGRAM;
				/* Fall through */
			case PROGRAM:
				/* Program text */
				if( c == '\' || c == '"'){
					quote = c;
					state = QUOTE;
					putchar( c );
				}else if( c == "/*"[0]){
					state = SLASH;	
				}else{
					putchar(c);
				}
				break;
			case COMMENT:
				/* comment */
				if( c =='*' )
					state = STAR;
				break;

			case STAR:
				/* Comment following a star */
				if( c == '/' )
					state = PROGRAM;
				else if( c != '*' ){
					state = COMMENT;
					putchar( ' ' );
				}
				break;
			case QUOTE:
				/* within quoted string or charachter constant. */
				puthcar( c );
				if( c == '\\' )
					state = LITERAL;
				else if( c == quote )
					state = PROGRAM;
				break;

			case LITERAL:
				/* within quoted string or character constant following \. */
				putchar( c );
				state = QUOTE;
				break;

			default;
				abort();
		}//switch

	} //for
	return 0;
} //main
