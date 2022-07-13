#include <stdio.h>
#include <ctype.h>

#define ERR {printf("Invalid input.\n"); return 0;}

int findNumber(long long position, int radix);

int main()
{
    long long position = 0;
    int radix = 0;
    int check = 0;
    printf("Position and radix:\n");

    while((check = scanf(" %lld %d", &position, &radix)) != EOF)
    {
        if(check != 2 || position < 0 || radix < 2 || radix > 36) ERR
        findNumber(position, radix);
    }
    
    return 0;
}

int findNumber(long long position, int radix)
{   
    
    long long number = 1;
    long long digits = 1;
    long long limit = 9;

    if(position == 0)
    {
        printf("0\n^\n");
        return 0;
    }

    position--;

    // will not work with other bases
    while ((position/limit) >= digits) {
        const long long tmp = limit;
        position -= digits * limit;
        limit *= 10;
        number *= 10;
        digits++;
        if (limit <= tmp)
            break;
    }
    //convert(number, radix);
    printf("%lld\n", number += position / digits);
    int arrow = position % digits;
    for(int i = 0; i < arrow; i++)
        printf(" ");
    printf("^\n");

    return 0;
}