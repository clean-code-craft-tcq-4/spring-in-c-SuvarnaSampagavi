#include "stats.h"

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>

typedef struct
{
	float avg;
	float max;
	float min;
}Stats;     //computedStats;

Stats compute_statistics(const float* numberset, int setlength) {
    Stats s;

    s.avg = 0;
    s.min = 0;
    s.max = 0;

    int i = 0;
    float sum = 0;
    float largest = numberset[0];
    float smallest = numberset[0];

    for(i=0; i< setlength; i++)
    {
        sum = sum + numberset[i];
    }
    s.avg = sum/setlength;
    for(i = 1; i < setlength; i++)
    {
    	if(largest < numberset[i])
    	{
    		largest = numberset[i];
    	}
    	if(smallest > numberset[i])
    	{
    		smallest = numberset[i];
    	}
    }
    s.max = largest;
    s.min = smallest;
    printf("\n%f, %f, %f", s.avg, s.max, s.min);

    if(numberset == 0)
    {
    	s.avg = 0;
    	s.min = 0;
    	s.max = 0;
    }

    return (s);
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
