#include <stdio.h>
#define N 5 //Tamanho da fila

typedef struct {
    int queue[N], inicio, fim, size;
} fila;

//Inicializa fila Q -> O(1)
void initFila(fila *Q);

//Verifica se a fila está vazia -> O(1)
int filaVazia(fila *Q);

//Verifica se a fila Q está cheia -> O(1)
int filaCheia(fila *Q);

//Enfileira elemento "x" na fila Q -> O(1)
void enqueue(fila *Q, int x); 

//Desenfileira o elemento da "frente" (inicio) da fila Q -> O(1)
int dequeue(fila *Q);

//Retorna o elemento da "frente" (inicio) da fila Q -> O(1)
int front(fila *Q);

//Retorna o elemento de "trás" (fim) da fila Q -> O(1)
int back(fila *Q);

//Retorna o tamanho da fila Q -> O(1)
int queueLength(fila *Q);

int main(){
    fila A, B;
    initFila(&A);
    initFila(&B);
    //Ex1: fila A
    enqueue(&A, 1); // [1]
    enqueue(&A, 2); // [1, 2]
    enqueue(&A, 3); // [1, 2, 3]
    enqueue(&A, 4); // [1, 2, 3, 4]
    enqueue(&A, 5); // [1, 2, 3, 4, 5]
    
    printf("%d", front(&A)); // [(1), 2, 3, 4, 5] -> Retorna 1
    
    dequeue(&A); // [2, 3, 4, 5]
    
    printf("%d", front(&A)); // [(2), 3, 4, 5] -> Retorna 2    

    printf("%d", back(&A)); //[2, 3, 4, (5)] -> Retorna 5

    enqueue(&A, 6); //[2, 3, 4, 5, 6]
    
    printf("%d", back(&A)); //[2, 3, 4, 5, 6] -> Retorna 6

    dequeue(&A); // [3, 4, 5, 6]
    dequeue(&A); // [4, 5, 6]
    
    printf("%d", front(&A)); // [(4), 5] -> Retorna 4
    
    printf("%d", back(&A)); // [4, 5, (6)] -> Retorna 6
    
    //Ex2: fila B
    int i = 1;
    //Enfileiramento da fila B -> [1, 2, 4, 8, 16]
    while(!filaCheia(&B)){
        enqueue(&B, i);
        i *= 2;
    }
    //Desinfileiramento da fila B -> 1 2 4 8 16
    while(!filaVazia(&B))
        printf("%d ", dequeue(&B)); 
    return 0;
}

void initFila(fila *Q){
    Q->inicio = 0;
    Q->fim = 0;
    Q->size = 0;
    return;
}

int filaVazia(fila *Q){
    if(Q->size == 0) //Verifica se o tamanho é 0 (0 elementos)
        return 1; //true
    return 0; //false
}

int filaCheia(fila *Q){
    if(Q->size == N) //Verifica se o tamanho é igual ao máximo (Número de elementos = N)
        return 1; //true
    return 0; //false
}

void enqueue(fila *Q, int x){
    if(filaCheia(Q)) //Se fila Q estiver cheia
        return; //Overflow
    if(filaVazia(Q)){ //Se fila Q estiver vazia
        Q->queue[Q->fim] = x;
        (Q->size)++;
        return;
    }
    if(Q->fim == N-1)
        Q->fim = 0;
    else
        (Q->fim)++;
    Q->queue[Q->fim] = x;
    (Q->size)++;
    return;
}

int dequeue(fila *Q){
    int aux;
    if(filaVazia(Q)) //Se fila Q estiver vazia
        return; //Underflow
    aux = Q->queue[Q->inicio];
    if(Q->inicio == N-1)
        Q->inicio = 0;
    else
        (Q->inicio)++;
    (Q->size)--;
    return aux;
}

int front(fila *Q){
    return Q->queue[Q->inicio];
}

int back(fila *Q){
    return Q->queue[Q->fim];
}