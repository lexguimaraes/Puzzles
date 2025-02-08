#include <stdio.h>
int pai(int ind){
    if (ind < 0)return -1;
    return (ind-1)/2;
}

void max_heapfy(int *vet, int ind, int n){
    int e = ind*2 +1,d = ind*2+2,maior = ind;
    if(e < n && vet[e] > vet[ind])maior = e;
    if(d < n && vet[d] > vet[maior])maior = d;
    if(maior != ind){
        int temp = vet[maior];
        vet[maior] = vet[ind];
        vet[ind] = temp;
        max_heapfy(vet,maior,n);
    }
}

void build_max_heap(int *vet, int n){
    int ult_pai = pai(n-1);
    for(int i = ult_pai;i>=0;i--){
        max_heapfy(vet,i,n);
    }
}

void heap_sort(int* vet, int n){
    build_max_heap(vet,n);
    for(int i = n-1;i>0;i--){
        int temp = vet[i];
        vet[i] = vet[0];
        vet[0] = temp;
        max_heapfy(vet,0,i);
    }
}

int devagar(int* pessoas, int n){
    int tempo = 0;
    tempo += pessoas[1];
    tempo += pessoas[0];
    tempo += pessoas[n-1];
    tempo+= pessoas[1];
    return tempo;
}

int rapido(int* pessoas, int n){
    int tempo = 0;
    tempo += pessoas[n-1];
    tempo += pessoas[0];
    tempo += pessoas[n-2];
    tempo += pessoas[0];
    return tempo;
}




int func(int* pessoas, int n){
    heap_sort(pessoas,n);
    int tfinal = 0;
    while(n>3){
        int t1 = rapido(pessoas,n);
        int t2 = devagar(pessoas,n);
        int temp = t1;
        if(t2<temp)temp = t2;
        tfinal +=temp;
        n-=2;
    }
    if (n == 1)tfinal += pessoas[0];
    if (n == 2)tfinal +=pessoas[1];
    if (n == 3)tfinal += pessoas[0] + pessoas[1] + pessoas[2];
    return tfinal;
}





int main(void) {
    int pessoas[] = {1,4,5,8,9,12};
    printf("TEMPO: %d\n",func(pessoas, 6));
    return 0;
}
