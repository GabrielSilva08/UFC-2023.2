#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int b1, b2, q,  digit, e, dec = 0, j = 0, n[500];
    string i;
    cout << "Digite a base numérica do número a ser inserido (b1): ";
    cin >> b1;
    cout << "Digite o inteiro não-negativo a ser convertido: ";
    cin >> i;
    cout << "Digite a base para qual deseja-se converter(b2): ";
    cin >> b2;
    e = i.size() - 1;
    for(int l = 0; l < i.size() ; l++){
        if(i[l] >= 'A'){
            digit = (int) i[l] - 'A' + 10;
        }else{
            digit = (int) i[l] - '0';
        }
        dec += digit * pow(b1, e);
        e--;
    }
    q = dec;
    while(q >= b2){
        n[j] = q % b2;
        q /= b2;
        j++;
    }
    n[j] = q;
    cout << "O equivalente de " << i << "(base " << b1 << ") na base " << b2 << ", é ";
    for(int k = j; k >= 0; k--){
        if(n[k] >= 10){
            cout << (char) (n[k] + 55);
        }else{
            cout << n[k];
        }        
    }
    cout << ".\n";
    return 0;
}