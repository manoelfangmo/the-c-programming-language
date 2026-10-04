#include <stdio.h>

/* print Fahrenheit-Celsius table

or fahr = 0, 20, ..., 300 */
int main()

{

    float fahr, celsius;

    float lower, upper, step;

    lower = 0; /* lower limit of temperature scale */

    upper = 300;
    /* upper limit */

    step = 20; /* step size */

    fahr = lower;

    printf("Fahrenheit to Celsius\n");

    while (fahr <= upper)
    {

        celsius = 5.0 * (fahr - 32.0) / 9.0;

        printf("%3.0f\t%6.2f\n", fahr, celsius);

        fahr = fahr + step;
    }
}