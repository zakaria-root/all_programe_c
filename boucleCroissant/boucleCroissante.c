#include<stdio.h>
typedef struct {
    int d,f,i;
}param_t;

void boucleCroissante(int d,int f,int i){
    if(d <= f){
        printf("%d,",d);
        boucleCroissante(d+i,f,i);
    }
}

void boucleCroissanteBis(param_t list){
    if(list.d<=list.f){
        printf("%d,",list.d);
        list.d+=list.i;
        //param_t list2={list.d+list.i,list.f,list.i};
        boucleCroissanteBis(list);
    }
}
void boucleCroissanteBis2(param_t *adrList){
    if(adrList->d<=adrList->f){
        printf("%d,",adrList->d);
        adrList->d+=adrList->i;
        //param_t list2={list.d+list.i,list.f,list.i};
        boucleCroissanteBis2(adrList);
    }
}

void boucleCroissante2(int d, int f, int i){
    
    if(d>f)return;
    printf("%d,",d);

    boucleCroissante2(d+i,f,i);
}

void boucleCroissanteIter(int d,int f,int i){
    int j;
    for(j=d;j<=f;j+=i)
        printf("%d,",j);
}

int main(){
    param_t list={5,14,2},list2=list;
    puts("1er appel : ");
    boucleCroissante(5,14,2);
    puts("\n2eme appel:");
    boucleCroissante2(5,14,2);
    puts("\n3eme appel : ");
    boucleCroissanteIter(5,14,2);
    puts("\n4eme appel : ");
    boucleCroissanteBis(list);
    puts("\n5eme appel : ");
    boucleCroissanteBis2(&list2);
    return 0;
}