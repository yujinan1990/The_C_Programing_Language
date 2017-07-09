/* Page 21 of The C Programing Lanuage
 * a character written between single quotes represents an integer value equal to the numerical  value of the character in the machine's character set
 * by Jean 20160611
 */

#include <stdio.h>

void main()
{/* put the character value based on due character set*/
	char ch;
	ch = 'A';
	printf(" %d " , ch );// use %d fomat to print char, will print its ASCII value
	printf(" %d" , ch - '\0' );// the value of character '\0' in ASII is 0
}
