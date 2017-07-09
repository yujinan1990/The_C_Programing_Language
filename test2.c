/* 
 * by Jean 20170604
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

double FtoC( double );

void main()
{	
	double c=0;
	int d=0;
#if 0
	if( ( c = (  getchar() - '0')) > -300 && c < 300 ) {//just getchar is not right, isdigit(()here is not proper
#endif
	scanf(" %f %d", &c, &d );
		printf( "c = %f, d = %d \n ", c , d ); 
		printf( "the Celsius Temperature is %f \n ", FtoC( d ) );
#if 0
	}else{
		printf ( "erro");
	}
#endif
}


double FtoC ( double Ft )
{/*translate the Fahrenheit temperature to Celcius*/
	int Ct;
	Ct = ( 5.0 / 9 )*( Ft - 32 );
	printf(" %d \n ",Ct );
	return Ct;
}
