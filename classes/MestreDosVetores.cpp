#include "MestreDosVetores.h"
#include<iostream>
#include<time.h>
#include<thread>
#include<chrono>

namespace chrono = std::chrono;

void mostrarVetor(auto vetor[], int tamanhoDoVetor){
    std::cout<<"Vetor:\n";
    for(auto& const i : vetor[]){
        std :: cout << "i"<<" ";
    }
    std::cout<<"\n";
}

void selectionSort(auto vetor[], int tamanhoDoVetor){
    int helper;
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
}

void bubbleSort(auto vetor[], int tamanhoDoVetor){
    int helper;
    for (int i = 0; i < tamanhoDoVetor - 1; ++i) {
        for (int j = 0; j < tamanhoDoVetor - 1 -i; ++j) {
            if (vetor[j] > vetor[j + 1]) {
                helper = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = helper;
            }
        }
    }
}

void compararTempoDeExecucao(auto vetor[], int tamanhoDoVetor){
    chrono::steady_clock inicio = chrono::now();
    std::thread selection(selectionSort,vetor,tamanhoDoVetor);
    selection.detach();
    std::thread bubble(bubbleSort,vetor,tamanhoDoVetor);
    bubble.detach();
}