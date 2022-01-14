#include"statistiques.h"
#include<math.h>

double getMoyenne1(double r1){
    return r1;  
}
double getMoyenne2(double r1,double r2){
    return (r1+r2)/2;
}
double getMoyenne3(double r1,double r2,double r3){
    return (r1+r2+r3)/3;
}
double getMoyenne4(double r1,double r2,double r3,double r4){
    return (r1+r2+r3+r4)/4;
}
double getEcart1(double r1){
    return 0;
}
double getEcart2(double r1,double r2){
    double moy=getMoyenne2(r1,r2);
    return sqrt((pow(r1-moy,2)+pow(r2-moy,2))/2);
}
double getEcart3(double r1,double r2,double r3){
    double moy=getMoyenne3(r1,r2,r3);
    return sqrt((pow(r1-moy,2)+pow(r2-moy,2)+pow(r3-moy,2))/3);    
}
double getEcart4(double r1,double r2,double r3,double r4){
    double moy=getMoyenne4(r1,r2,r3,r4);
    return sqrt((pow(r1-moy,2)+pow(r2-moy,2)+pow(r3-moy,2)+pow(r4-moy,2))/4);        
}