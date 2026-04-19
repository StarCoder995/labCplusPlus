#include "..\classes\MestreDosVetores.h"
#include<iostream>
#include<stdlib.h>
#include<chrono>
#include<thread>
int main(){
    const int tamanho = 200;
    std::chrono::time_point<std::chrono::steady_clock> inicio = std::chrono::steady_clock::now();
    int listaOrdenavel[tamanho], listaOrdenada[tamanho];
    for(int i = 0; i < tamanho; i++){
        listaOrdenavel[i] = std::rand() % 200 + 1;
        listaOrdenada[i] = i + 1;
    }
    std::chrono::duration<long double> tempoDePreenchimento = std::chrono::duration<long double,std::micro>(std::chrono::steady_clock::now() - inicio);
    std::cout<<std::fixed;
    std::cout<<"Tempo de preenchimento do vetor desordenado de 200 itens: "<<tempoDePreenchimento.count()<<" segundos\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<"Comparando tempos de processamento dos algoritmos de sorting do vetor Desordenado: \n";
    compararTempoDeExecucao(listaOrdenavel,tamanho);
}