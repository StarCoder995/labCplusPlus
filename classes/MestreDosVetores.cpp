#include "MestreDosVetores.h"
#include<iostream>
#include<thread>
#include<chrono>
#include<iomanip>
void mostrarVetor(int vetor[], int tamanhoDoVetor,std::string tipoDeOrnenacao ){
    std::cout<<"Vetor Ordenado por"<< tipoDeOrnenacao<< " :\n";
    for(int i = 0; i < tamanhoDoVetor; i++){
        std::cout<<vetor[i]<<" ";
    }
    std::cout<<"\n";
}

void selectionSort(int vetor[], int tamanhoDoVetor){
    int helper;
    std::chrono::time_point<std::chrono::steady_clock> inicio = std::chrono::steady_clock::now();
    for (int i = 0; i < tamanhoDoVetor - 1; ++i) {
        int menorAtual = i;
        
        for (int j = i + 1; j < tamanhoDoVetor; ++j) {
            if (vetor[j] < vetor[menorAtual]) {
                menorAtual = j; 
            }
        }
        helper = vetor[i];
        vetor[i] = vetor[menorAtual];
        vetor[menorAtual] = helper;
    }
    std::chrono::duration<long double> tempoTotal = std::chrono::duration<long double,std::nano>(std::chrono::steady_clock::now() - inicio);
    std::cout<<std::fixed;
    std::cout<<"Tempo de processamento | Selection Sort :"<<std::setprecision(20)<< tempoTotal.count() <<" segundos\n";
    mostrarVetor(vetor,10,"Selection Sort");

}

void bubbleSort(int vetor[], int tamanhoDoVetor){
    int helper;
    std::chrono::time_point<std::chrono::steady_clock> inicio = std::chrono::steady_clock::now();
    for (int i = 0; i < tamanhoDoVetor - 1; ++i) {
        for (int j = 0; j < tamanhoDoVetor - 1 -i; ++j) {
            if (vetor[j] > vetor[j + 1]) {
                helper = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = helper;
            }
        }
    }
    std::chrono::duration<long double> tempoTotal = std::chrono::duration<long double,std::nano>(std::chrono::steady_clock::now() - inicio);
    std::cout<<std::fixed;
    std::cout<<"Tempo de processamento | BubbleSort :"<<std::setprecision(20)<< tempoTotal.count() <<" segundos\n";
    mostrarVetor(vetor,10,"Bubble Sort");
}

void compararTempoDeExecucao(int vetor[], int tamanhoDoVetor){
    int outroVetor[100000];
    for(int i = 0; i < tamanhoDoVetor; i++){
        outroVetor[i] = vetor[i];
    }
    std::thread selection(selectionSort,vetor,tamanhoDoVetor);
    selection.detach();
    std::thread bubble(bubbleSort,outroVetor,tamanhoDoVetor);
    bubble.detach();
    std::this_thread::sleep_for(std::chrono::seconds(30));
}