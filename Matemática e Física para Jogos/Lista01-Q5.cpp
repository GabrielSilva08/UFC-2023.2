#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int d, b, q, n[500], i = 0; //número decimal (d) | base numérica (b) | quociente da divisão corrente (q) | número convertido (n[]) | variável contadora de divisões (i).
    cout << "Digite o número decimal a ser convertido (d): ";
    cin >> d;
    cout << "Digite a base para qual deseja-se converter(b): ";
    cin >> b;
    q = d;
    while(q >= b){ //divisões sucessivas e armazenamento dos restos.
        n[i] = q % b;
        q /= b;
        i++;
    }
    n[i] = q;
    cout << "O equivalente de " << d << " na base " << b << ", é ";
    for(int j = i; j >= 0; j--){ //Um tratamento é feito caso o "dígito" seja superior a 10.
        if(n[j] >= 10){
            cout << (char) (n[j] + 55);
        }else{
            cout << n[j];
        }        
    }
    cout << ".\n";
    return 0;
}
