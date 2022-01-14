#include<stdio.h>
#include<stdlib.h>
#include "statistique.h"
#include<stdarg.h>

double moy(int nbr, ...){
    double s = 0;
    va_list(args);
    va_start(args, nbr);
    for (int i = 0; i < nbr; i++)
    {
        s += va_arg(args, double);
    }
    va_end(args);
    return s / nbr;
}
