//
// Created by Viola Durghalli on 11/4/24.
//

#include "Helper_Functions.h"


int countDigits(int number)
{
    int count = number == 0 ? 1 : 0;
    while(abs(number) > 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

int maxDigits(int a, int b)
{
    if(countDigits(a) > countDigits(b))
        return a;
    else
        return b;
}

