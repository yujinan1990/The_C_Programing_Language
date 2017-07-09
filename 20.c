/* Page 20 of The C Progrmaing Language
 * getchar() putchar() and print the value of EOF
 * by Jean 20170611 
 */

#include <stdio.h>

void main() 
{/* copy input to output , print the value of EOF */
	int c; // c must be big enough to hold EOF
	while( ( c = getchar() ) != EOF )
		putchar(c);
	printf("the value of EOF is %d " , EOF);
}
