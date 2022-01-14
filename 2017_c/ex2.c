#include <stdio.h>
#include <stdlib.h>
    
    int **createArray(int n){
        int **array = (int**) malloc(sizeof(int*)*n);
        for (int i = 0; i < n; i++)
        {
            array[i] = (int*) malloc(sizeof(int)*n);
        }
        return array;
    }

    void insertArray(int **array, int n){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("t[%d][%d] = ",i+1,j+1);
                scanf("%d",&(array[i][j]));
            }
        }
    }

    void display(int **array, int n){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d\t",array[i][j]);
            }
            printf("\n");
        }
    }

    int **sumTowArray(int **array1,int **array2,int n ){
        int **sumArray = createArray(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sumArray[i][j] = array1[i][j] + array2[i][j];
            }
        }
        return sumArray;
    }

    int **MultTowArray(int **array1,int **array2,int n ){
        int **multArray = createArray(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int Sum = 0;
                for (int k = 0; k < n; k++)
                {
                    Sum += array1[i][k] * array2[k][j];
                }
                multArray[i][j] = Sum;
            }
        }
        return multArray;
    }

    int trace(int n ,int **array){
        int tr =0;
        for (int i = 0; i < n; i++)
        {
            tr += array[i][i];
        }
        return tr;
    }

int main(){
    int size;
    printf("enter the size of te array : ");
    scanf("%d",&size);

    int **array1 = createArray(size);
    int **array2 = createArray(size);
    printf("insert the first array :\n");
    insertArray(array1, size);
    printf("insert the first array :\n");
    insertArray(array2, size);
    printf("display the first array :\n");
    display(array1, size);
    printf("display the secand array :\n");
    display(array2, size);
    printf("display the addition of tow array :\n");
    display(sumTowArray(array1,array2,size),size);
    printf("display the multiplication of tow array :\n");
    display(MultTowArray(array1,array2,size),size);
    printf("the trac of first array is : %d\n",trace(size, array1));
    return 0;
}

