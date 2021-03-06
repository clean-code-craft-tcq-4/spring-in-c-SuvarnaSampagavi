#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include "emailAlerter.h"
#include "ledAlerter.h"

#include <stdlib.h>
#include <math.h>

TEST_CASE("reports average, minimum and maximum") {
    float numberset[] = {1.5, 8.9, 3.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);

    //size of nums in the array=4*4=16, size of each element in array=4
        printf("\n%ld", sizeof(numberset));  //16
        printf("\n%ld", sizeof(numberset[0])); //4
        printf("\n%ld", sizeof(setlength)); // Number of elements in the array, 4

    Stats_s computedStats = compute_statistics(numberset, setlength);
    float epsilon = 0.001;

    /* Check for computed avg, min and max against the actual values, if same then test is passed else fail*/
    //abs gets the absolute(or positive) value of the difference between two numbers
    printf("\nComputed Avg:%f, Computed Max:%f, Computed Min:%f", computedStats.avg, computedStats.max, computedStats.min );
    //printf(REQUIRE(abs(computedStats.avg - 4.525) < epsilon));
    //printf(REQUIRE(abs(computedStats.max - 8.9) < epsilon)));
    //printf(REQUIRE(abs(computedStats.min - 1.5) < epsilon));

/*    REQUIRE(abs(computedStats.avg  - 4.525) < epsilon);
    REQUIRE(abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(abs(computedStats.min - 1.5) < epsilon);*/

    abs(computedStats.avg - 4.525) < epsilon? printf("\n Computed average is correct"):printf("\n Computed average is incorrect");
    abs(computedStats.max - 8.9) < epsilon? printf("\n Computed Max value is correct"):printf("\n Computed Max value is incorrect");
    abs(computedStats.min - 1.5) < epsilon? printf("\n Computed Min value is correct"):printf("\n Computed Min value is incorrect");
}

TEST_CASE("average is NaN for empty array") {
    //Defining an empty array with setlength zero
    const float *numberset = {0};
    int setlength = 0;
    
    Stats_s computedStats = compute_statistics((const float *)&numberset, setlength);
    //Stats_s computedStats = compute_statistics(0, 0);
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    printf("\nComputed Avg:%f",  computedStats.avg);
    
    //Design the REQUIRE statement here.
    //REQUIRE(isnan(computedStats.avg));
    //REQUIRE(isnan(computedStats.max));
    //REQUIRE(isnan(computedStats.min));
    
    isnan(computedStats.avg)? printf("\nAverage is NaN for empty array"):printf("\n Average is not NaN for empty array");
    
    //Use https://stackoverflow.com/questions/1923837/how-to-use-nan-and-inf-in-c
}

TEST_CASE("raises alerts when max is greater than threshold") {
    // create additional .c and .h files
    // containing the emailAlerter, ledAlerter functions
    alerter_funcptr alerters[] = {emailAlerter, ledAlerter};

    float numberset[] = {99.8, 34.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    Stats_s computedStats = compute_statistics(numberset, setlength);

    const float maxThreshold = 10.2;
    check_and_alert(maxThreshold, alerters, computedStats);

    // need a way to check if both emailAlerter, ledAlerter were called
    // you can define call-counters along with the functions, as shown below
    REQUIRE(emailAlertCallCount == 1);
    REQUIRE(ledAlertCallCount == 1);
}
