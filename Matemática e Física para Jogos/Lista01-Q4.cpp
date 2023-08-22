#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int b, digit, e, dec = 0; //base/Radix (b) | variável temporária que irá guardar o dígito do número (digit) | variável track que irá manter controle das potências (e) | valor decimal de i (dec).
    string i; //inteiro não-negativo(i).
    cout << "Digite a base númerica(b): ";
    cin >> b;
    cout << "Digite o inteiro não-negativo a ser convertido: ";
    cin >> i;
    e = i.size() - 1;
    for(int l = 0; l < i.size() ; l++){ //faz-se um tratamento de cada dígito, e então esse é somado com sua devida potência à variável dec.
        if(i[l] >= 'A'){
            digit = (int) i[l] - 'A' + 10;
        }else{
            digit = (int) i[l] - '0';
        }
        dec += digit * pow(b, e);
        e--;
    }
    cout << "O número " << i << " na base " << b << " é igual a " << dec << " na base 10.\n";
    return 0;
}