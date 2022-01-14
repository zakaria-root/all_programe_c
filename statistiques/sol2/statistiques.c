#include"statistiques.h"
#include<math.h>
#include<stdarg.h>


double getMoyenne(int nbr, ...){
    int i;
    double som = 0;
    va_list(args);
    va_start(args,nbr);
        for ( i = 0; i < nbr; i++)
        {
            som += va_arg(args,double);
        }
    va_end(args); 
    
    return som/nbr;
}


double getEcart(double moy,int nbr,...){
    int i;
    double ecart = 0;
    va_list(args);
    va_start(args,nbr);
    for (i = 0; i < nbr; i++)
    {
        ecart += pow(va_arg(args, double) - moy, 2);  
    }
    va_end(args);
    return sqrt(ecart/nbr);
    
}
