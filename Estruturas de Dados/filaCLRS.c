#include <stdio.h>
#define N 5 //Tamanho da fila

typedef struct {
    int queue[N], inicio, fim;
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

int main(){
    fila A, B;
    initFila(&A);
    initFila(&B);
    //Ex1: fila A
    enqueue(&A, 1); // [1]
    enqueue(&A, 2); // [1, 2]
    enqueue(&A, 3); // [1, 2, 3]
    enqueue(&A, 4); // [1, 2, 3, 4]
    enqueue(&A, 5); // [1, 2, 3, 4]
    
    printf("%d", front(&A)); // [(1), 2, 3, 4] -> Retorna 1
    
    dequeue(&A); // [2, 3, 4]

    printf("%d", front(&A)); // [(2), 3, 4] -> Retorna 2    
    
    printf("%d", back(&A)); //[2, 3, (4)] -> Retorna 4
    
    enqueue(&A, 5); //[2, 3, 4, 5]
    
    printf("%d", back(&A)); //[2, 3, 4, (5)] -> Retorna 5

    dequeue(&A); // [3, 4, 5]
    dequeue(&A); // [4, 5]
    
    printf("%d", front(&A)); // [(4), 5] -> Retorna 4
    
    printf("%d", back(&A)); // [4, (5)] -> Retorna 5
    
    //Ex2: fila B
    int i = 1;
    //Enfileiramento da fila B -> [1, 2, 4, 8]
    while(!filaCheia(&B)){
        enqueue(&B, i);
        i *= 2;
    }
    //Desinfileiramento da fila B -> 1 2 4 8
    while(!filaVazia(&B))
        printf("%d ", dequeue(&B));    
    return 0;
}

void initFila(fila *Q){
    Q->inicio = 0;
    Q->fim = 0;
    return;
}

int filaVazia(fila *Q){
    if(Q->inicio == Q->fim) //Verifica se o começo está no fim (0 elementos)
        return 1; //true
    return 0; //false
}

int filaCheia(fila *Q){
    if((Q->inicio == 0 && Q->fim == N-1) || (Q->fim)+1 == Q->inicio) //Verifica se tá cheio no caso inicio < fim ou no caso fim > inicio
        return 1; //true
    return 0; //false
}

void enqueue(fila *Q, int x){
    if(filaCheia(Q)) //Se fila Q estiver cheia
        return; //Overflow
    Q->queue[Q->fim] = x;
    if(Q->fim == N-1)
        Q->fim = 0;
    else
        (Q->fim)++;
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
    return aux;
}

int front(fila *Q){
    return Q->queue[Q->inicio];
}

int back(fila *Q){
    if(Q->fim == 0)
        return Q->queue[N-1];
    return Q->queue[Q->fim - 1];
}