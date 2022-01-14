#ifndef _POLY_t
    #define _POLY_t
    #define MAX 100
    typedef struct
    {
        int d;
        float coff;
    }monome_t;
    
    typedef struct 
    {
        monome_t tab[MAX];
        int langeur;
    }poly_t;



#endif