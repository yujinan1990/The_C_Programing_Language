/*Page22 of The C Promgraming Language
 *copy input to outpout, replacing each tab by \t, each backspace by \b, and each backslash by \\.
 * by Jean 20170614
 */
#include <stdio.h>

void main()
{/*copy input to outpout, replacing each tab by \t, each backspace by \b, and each backslash by \\ */
	int ch, mark;
	while( ( ch = getchar() ) != EOF ){
		mark = 0;
		if( ch == '\t' ){
			putchar('\\');
			putchar('\t');
			mark = 1;
		}if( ch == '\b' ){ // why no elseif
			putchar('\\');
			putchar('\b');
			mark = 2;
		}if( ch == '\\' ){
			putchar('\\');
			putchar('\\');
			mark =3;	
		}if( mark = 0 ){
			putchar ( ch );
		}
		
	}	

}
