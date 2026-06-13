#include <stdio.h>
#include <stdlib.h>

	float sum(float operant1, float operant2)
{
	return operant1+operant2;
}


int main()
{
	
	float metavliti1, metavliti2, metavliti5, metavliti6 ;
    float apotelesma;
    float apot_dier;
    float apot_afair;
    float apot_pol;
    
	metavliti1 = 25;
    metavliti2 = 0.2356;
    metavliti5 = 25.2314;
    metavliti6 = 6.55234;
    
	printf("hello\n\n");
	
	printf("timh metavlitis %f\n",metavliti1);
	
		apotelesma = metavliti1 + metavliti2;
	
	printf("to apotelesma ths prosthesis einai : %f\n",apotelesma);
	
		apot_dier = metavliti1/metavliti2;
	
	printf("to apotelesma ths diaireshs einai : %f\n",apot_dier);
	
		apot_afair = metavliti1-metavliti2;
	
	printf("to apotelesma ths afaireshs einai: %f\n",apot_afair);
	
		apot_pol = metavliti1*metavliti2;
	
	printf("to apotelesma toy pollaplasiasmoy einai : %f\n",apot_pol);
	
	printf("to apotelesma ths sum einai : %f\n",sum(metavliti5,metavliti6));
		
	system("PAUSE");
	return 0;
}