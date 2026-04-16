#include "../classes/MestreDosVetores.h"
#include<iostream>
#include<stdlib.h>
#include<chrono>
int main(){
    const int tamanho = 100000;
    std::chrono::time_point<std::chrono::steady_clock> inicio = std::chrono::steady_clock::now();
    int listaOrdenavel[tamanho];
    for(int i = 0; i < tamanho; i++){
        //listaOrdenavel[i] = std::rand() % 100000 + 1;
        listaOrdenavel[i] = 100000 - i;

    }
    std::chrono::duration<long double> tempoDePreenchimento = std::chrono::duration<long double,std::micro>(std::chrono::steady_clock::now() - inicio);
    std::cout<<std::fixed;
    std::cout<<"Tempo de preenchimento do vetor de cem mil espaços: "<<tempoDePreenchimento.count()<<" segundos\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    compararTempoDeExecucao(listaOrdenavel,tamanho);
}