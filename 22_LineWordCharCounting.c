/* Page 22 of The C Programming Language
 * a bare-bones version of the UNIX wc, counts lines, words, characters
 * by Jean 20170619
 */
#include <stdio.h>

void main()
{	/* a bare-bones version of the UNIX wc, counts lines, words, characters*/
	int nl, nw, nc;
	enum CursorState{ IN , OUT };
	enum CursorState state;
	int c;	
	nl = nw = nc = 0;
	state = IN;

	while( (c = getchar()) != EOF ){
		++nc;
		if( c == '\n' ){
			++nl;	
		}
		if( c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
		}else if(state == OUT){
			++nw;
			state = IN;
		}
	
	}	
	printf(" %d\t%d\t%d \n ", nl, nw, nc );	

}
