#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double funcao_fx(double x) {
    return (8*(pow(x , 4))-14*(pow(x , 3))-9*(pow(x , 2))+11*(x)-1);
}

double funcao_dfx(double x) {
    return (32*(pow(x , 3)) - 42*(pow(x , 2 )) - 18*(x) + 11);
}

double truncar(double valor, int casas) {
    double fator = pow(10.0, casas);
    return trunc(valor * fator) / fator;
}

void newtonRaphson(double x0) { 
    const double CONVERGENCIA = 0.000001; // Critério de convergência -> 1 x 10^-6
    const int MAX_ITERACOES = 100; // "Conter um critério de parada caso o problema não encontre convergência" -> Nesse código, o máximo de iterações será 100

    double xn = x0; // x0 = primeira estimativa
    int iter = 0; // Iteração = 0

    cout << fixed << setprecision(6);

    cout << "Iteracao\t xn\t\t funcao_f(xn)" << endl;
    cout << "X" << iter << "\t\t" << " " << xn << "\t" << " " << funcao_fx(xn) << endl;  // Imprime inicial e a f(x0)

  //"Conter um laço do tipo enquanto ... faça" -> Em "while"; E "Conter o critério de convergência adotado no problema -> Em (funcao_fx(xn) > CONVERGENCIA || funcao_fx(xn) < -CONVERGENCIA)"
    while ((funcao_fx(xn) > CONVERGENCIA || funcao_fx(xn) < -CONVERGENCIA) && iter < MAX_ITERACOES) {
        double fx = funcao_fx(xn);
        double dfx = funcao_dfx(xn);

        if (dfx == 0) { // "Checar casos de derivada nula a cada iteração" -> Em "dfx == 0"
            cout << "Erro: Derivada nula na iteracao " << iter << ". Metodo falhou." << endl;
            return;
        }

        xn = xn - fx / dfx; // Passo iterativo de Newton-Raphson
        iter++; // Aumenta uma iteração

        cout << "X" << iter << "\t\t" << " " << truncar(xn,6) << "\t" << " " << funcao_fx(xn) << endl;  // Imprime apos atualizacao de cada iteração
    }

    if (funcao_fx(xn) <= CONVERGENCIA && funcao_fx(xn) >= -CONVERGENCIA) {
        cout << endl;
        cout << "Raiz estimada:   " << truncar(xn, 6)  << endl; // "Imprimir na tela a raíz estimada e o número de iterações utilizados"
        cout << "Iterações:" <<"\t" <<" " << iter << endl;
    } else {
        cout << "Erro: Metodo nao convergiu apos " << MAX_ITERACOES << " iteracoes." << endl; //"E caso não encontre convergência, imprimir uma mensagem de erro indicando qual o motivo da falha. -> Em 'Erro << MAX_ITERACOES (100)'
    }
}

int main() {
    double x0;
    cout << "Estimativa inicial x0: ";
    cin >> x0;

    newtonRaphson(x0);

    return 0;
}