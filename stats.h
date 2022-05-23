typedef struct Stats
{
	float avg;
	float max;
	float min;
}Stats_s; 

Stats_s compute_statistics(const float* numberset, int setlength);

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats_s computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;
