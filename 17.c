/* Page 17 fo The C Programing Language
 * symbolic constant
 * by Jean 20170611 
 */

#include <stdio.h>

#define LOWER -20
#define UPPER 300
#define STEP 20

void main()
{/* print Fahrenheit - Celcius table */
	int fahr;
	for( fahr = LOWER; fahr <= UPPER; fahr += STEP ){
		printf( "%-3d \t %6.3f \n " , fahr, (5.0/9.0) * (fahr - 32) );
	}
}
