/* Page21 of The C Programing Language
 * read the standin and count the number of characters
 * 20170613 by Jean
 */
#include <stdio.h>

void main()
{/*character counting*/
	// int ch; // type isn't char thus to hold EOF
	long n;
	for( n = 0;  getchar() != EOF ; n++ )
		;
	#if 0
	n = 0;
	while( getchar() != EOF )
		n++;
	#endif

	printf("the input character number is %ld \n " , n );
}
