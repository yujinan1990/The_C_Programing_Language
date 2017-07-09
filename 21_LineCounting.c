/* Page21 of The C Programing Language
 * read the standin and count the number of lines
 * 20170613 by Jean
 */
#include <stdio.h>

void main()
{/*line counting*/
	int ch; // type isn't char thus to hold EOF
	int n;
	for( n = 0; (ch =  getchar()) != EOF ; ( ch == '\n' ) ? (++n) : () )// WRONG  why?
		;
	#if 0
	n = 0;
	while( (ch = getchar()) != EOF ){
		if( ch == '\n')
			n++;
	}
	#endif

	printf("the input  line number is %d \n " , n );
}
