#include "MestreDosVetores.h"
#include<iostream>
#include<thread>
#include<chrono>
void mostrarVetor(int vetor[], int tamanhoDoVetor){
    std::cout<<"Vetor:\n";
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
    std::chrono::duration<double> tempoTotal = std::chrono::duration<double,std::nano>(std::chrono::steady_clock::now() - inicio);
    std::cout<<"Tempo de processamento :"<< tempoTotal.count() <<" microsegundos\n";
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
    std::chrono::duration<double> tempoTotal = std::chrono::duration<double,std::nano>(std::chrono::steady_clock::now() - inicio);
    std::cout<<"Tempo de processamento :"<< tempoTotal.count() <<" microsegundos\n";
}

void compararTempoDeExecucao(int vetor[], int tamanhoDoVetor){
    int outroVetor[10];
    for(int i = 0; i < tamanhoDoVetor; i++){
        outroVetor[i] = vetor[i];
    }
    std::thread selection(selectionSort,vetor,tamanhoDoVetor);
    selection.detach();
    std::thread bubble(bubbleSort,outroVetor,tamanhoDoVetor);
    bubble.detach();
    std::this_thread::sleep_for(std::chrono::seconds(3));
}