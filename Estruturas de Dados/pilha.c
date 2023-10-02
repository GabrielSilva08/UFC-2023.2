#include <stdio.h>
#define N 5 //Tamanho da pilha


typedef struct {
    int stack[N], topo;
} pilha; //Tipo pilha

void pilhaInit(pilha *S); //Inicializa pilha S -> O(1)
int pilhaCheia(pilha *S); //Consulta se a pilha S está cheia -> O(1)
int pilhaVazia(pilha *S); //Consulta se a pilha S está vazia -> O(1)
void push(pilha *S, int x); //Inserção do valor "x" na pilha S -> O(1)
int pop(pilha *S); //Remoção do valor presente no topo de S -> O(1)
int top(pilha *S); //Consulta o elemento no topo da pilha S -> O(1)

int main(){
    pilha A, B;
    //Ex1: Pilha A
    pilhaInit(&A); //[]
    push(&A, 1); // [1]
    push(&A, 2); // [1, 2]
    push(&A, 3); // [1, 2, 3]
    push(&A, 4); // [1, 2, 3, 4]
    push(&A, 5); //[1, 2, 3, 4, 5]
    printf("Pilha A: ");
    while(!pilhaVazia(&A)){ //Desempilhamento da pilha A
        printf("%d ", top(&A));
        pop(&A);
    }
    printf("\n");
    
    //Ex2: Pilha B
    pilhaInit(&B);
    for(int i = 0; i < 6; i++)
        push(&B, i*2);
    printf("Pilha B: ");
    while(!pilhaVazia(&B)) //Desempilhamento da pilha A
        printf("%d ", pop(&B));
    return 0;
}

void pilhaInit(pilha *S){
    S->topo = 0;
    return;
}

int pilhaCheia(pilha *S){
    if(S->topo == N)
        return 1; //Pilha cheia (true)
    return 0; //Pilha possui espaço (false)
}

int pilhaVazia(pilha *S){
    if(S->topo == 0)
        return 1; //Pilha vazia (true)
    return 0; //Pilha não vazia (false)
}

void push(pilha *S, int x){
    if(pilhaCheia(S)) //Verifica se a pilha já está cheia
        return; //Overflow
    S->stack[S->topo] = x; //Insere o valor x no topo
    (S->topo)++; //Incrementa topo
    return;
}

int pop(pilha *S){ //Retorna o elemento deletado
    if(pilhaVazia(S)) //Verifica se a pilha está vazia
        return; //Underflow
    (S->topo)--;
    int aux = S->stack[S->topo];
    return aux;
}

int top(pilha *S){
    return S->stack[(S->topo)-1];   
}