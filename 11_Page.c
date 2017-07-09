/* 
 * by Jean 20170604
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

float FtoC( float );

void main()
{	
	float c=0;
#if 0
	if( ( c = (  getchar() - '0')) > -300 && c < 300 ) {//just getchar is not right, isdigit(()here is not proper
#endif
	scanf("%f", &c );/*why read a number in &c , but the value is 0, the reason is when declare c it shoud by float, not double */
	printf( "the Fahreheit tmeprature is %6.2f, \n the Celsius Temperature is %6.3f \n ", c, FtoC( c ) );
	printf( " %-10.2f --> \n  \t  \t %10.2f \n" , c , FtoC( c ) );
#if 0
	}else{
		printf ( "erro");
	}
#endif
}


float FtoC ( float Ft )
{/*translate the Fahrenheit temperature to Celcius*/
	float  Ct;
	Ct = ( 5.0 / 9.0 )*( Ft - 32 );// both 5.0 and 9.0 is necessary, thus / can not truncate the result
	return Ct;
}
