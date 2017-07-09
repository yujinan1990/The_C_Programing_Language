/* Page21 of The C Programing Language
 * read the standin and count the number of blanks and tabss
 * 20170613 by Jean
 */
#include <stdio.h>

void main()
{/*line counting*/
	int ch; // type isn't char thus to hold EOF
	int nb;
	int nt;
	#if 0
	for( n = 0; (ch =  getchar()) != EOF ; ( ch == '\n' ) ? (++n) : () )// WRONG  why?
		;
	#endif
	//#if 0
	nb = nt = 0;
	while( (ch = getchar()) != EOF ){
		if( ch == '\b'){
			nb++;
		}else if( ch == '\t'){
			nt++ ;
		}
	}
	//#endif

	printf("the input  line number is %-10d %10d\n " , nt, nb );
}
