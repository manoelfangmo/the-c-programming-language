
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Max char %d\n", CHAR_MAX);
    printf("Min char %d\n", CHAR_MIN);
    printf("Max signed Char  %d\n", SCHAR_MAX);
    printf("Min signed char %d\n", SCHAR_MIN);
    printf("Max  unsigned char %d\n", UCHAR_MAX);

    printf("Max short %hd\n", SHRT_MAX);
    printf("Min short %hd\n", SHRT_MIN);
    printf("Max  unsigned short %hu\n", USHRT_MAX);

    printf("Max int %d\n", INT_MAX);
    printf("Min int %d\n", INT_MIN);
    printf("Max unsigned int %u\n", UINT_MAX);

    printf("Max long %ld\n", LONG_MAX);
    printf("Min long %ld\n", LONG_MIN);
    printf("Max unsigned  long %lu\n", ULONG_MAX);
}