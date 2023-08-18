#include <stdio.h>

int main(){
    int opcao; //Variável que guardarar a opção de temperatura
    double temp; //Variável que guardarar o valor da temperatura
    printf("Qual o valor da temperatura? (°C) ");
    scanf("%lf", &temp);
    printf("Para qual temperatura deseja converter?\n\n[0] - Fahrenheit\n[1] - Kelvin \n\nSua opção: ");
    scanf("%d", &opcao);
    if(opcao == 0){
        printf("%.2lf°C equivale a %.2lf°F", temp, 1.8*temp+32);
    }else if(opcao == 1){
        printf("%.2lf°C equivale a %.2lf K", temp, temp+273);
    }else{
        printf("Temperatura inexistente.");
    }
    return 0;
}