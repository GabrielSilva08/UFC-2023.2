#include <stdio.h>

double fahOf(double C){ //Fahrenheit of
    return C*1.8+32;    
}

double kelOf(double C){ //Kelvin of
    return C+273;
} 

int main(){
    int opcao; //Variável que guardarar a opção de temperatura/repetir
    double temp; //Variável que guardarar o valor da temperatura
    while(1){
        printf("Qual o valor da temperatura? (°C) ");
        scanf("%lf", &temp);
        printf("Para qual temperatura deseja converter?\n\n[0] - Fahrenheit\n[1] - Kelvin \n\nSua opção: ");
        scanf("%d", &opcao);
        if(opcao == 0){
            printf("%.2lf°C equivale a %.2lf°F\n\n", temp, fahOf(temp));
        }else if(opcao == 1){
            printf("%.2lf°C equivale a %.2lf K\n\n", temp, kelOf(temp));
        }else{
            printf("Temperatura inexistente.\n\n");
        }
        printf("Deseja continuar?\n\n[0] - Sim\n[1] - Não\n\nSua opção: ");
        scanf("%d", &opcao);
        if(opcao != 0){
            break;
        }
    }
    return 0;
}
