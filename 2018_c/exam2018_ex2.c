#include <stdio.h>
#include <stdlib.h>
    
    int compareFile(char fileName1[], char fileName2[]){
        FILE *f1 = fopen(fileName1, "r");
        FILE *f2 = fopen(fileName2, "r");
        char c1;
        char c2;
        if (f1 == NULL || f2 == NULL)
        {
            /* Unable to open file hence exit */
            printf("\nUnable to open file.\n");
            printf("Please check whether file exists and you have read privilege.\n");
            return 0;
        }else
        {
            while (((c1 = fgetc(f1))  != EOF) && ((c2 = fgetc(f2)) != EOF))
            {
                if (c1 != c2 )
                    return 0;
            }
        }
        fclose(f1);
        fclose(f2);
        return 1;
    }
int main(){
    char fileName1[20];
    char fileName2[20];
    printf("enter the name of the first file : ");
    scanf("%s",&fileName1);
    printf("enter the name of the secand file : ");
    scanf("%s",&fileName2);

    if (compareFile(fileName1,fileName2))
    printf("both files are the same \n ");
    else
    {
        printf("the two files are different \n ");
    }
        
    return 0;
}

