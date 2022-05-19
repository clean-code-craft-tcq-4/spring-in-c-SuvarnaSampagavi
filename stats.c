#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    
    int index = 0;
    float sum = 0;
    float large, small;
    large = small = numberset[0];

    //Finding Average
    for(i = 0; i < setlength; i++)
    {
        sum = sum + numberset[i];
    }
    s.average = sum/setlength;
    
    // Finding Max and Min
    for(i = 1; i < setlength; i++)
    {
    	if(large < numberset[i])
    	{
    		large = numberset[i];
    	}
    	if(small > numberset[i])
    	{
    		small = numberset[i];
    	}
    }
    s.max = large;
    s.min = small;


    if(numberset == 0)
    {
    	s.average = 0;
    	s.min = 0;
    	s.max = 0;
    }  
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
