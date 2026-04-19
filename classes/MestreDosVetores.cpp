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
    std::chrono::time_point<std::chrono::steady_clock> inicioSelection = std::chrono::steady_clock::now();
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
    std::chrono::duration<long double,std::micro> tempoTotalSelection = std::chrono::duration<long double,std::micro>(std::chrono::steady_clock::now() - inicioSelection);
    std::cout<<std::fixed;
    std::cout<<"Tempo de processamento | Selection Sort :"<<std::setprecision(10)<< tempoTotalSelection.count() <<" microsegundos\n";

}

void bubbleSort(int vetor[], int tamanhoDoVetor){
    int helper;
    std::chrono::time_point<std::chrono::steady_clock> inicioBubble = std::chrono::steady_clock::now();
    for (int i = 0; i < tamanhoDoVetor - 1; ++i) {
        for (int j = 0; j < tamanhoDoVetor - 1 -i; ++j) {
            if (vetor[j] > vetor[j + 1]) {
                helper = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = helper;
            }
        }
    }
    std::chrono::duration<long double,std::micro> tempoTotalBubble = std::chrono::duration<long double,std::micro>(std::chrono::steady_clock::now() - inicioBubble);
    std::cout<<std::fixed;
    std::cout<<"Tempo de processamento | BubbleSort :"<<std::setprecision(10)<< tempoTotalBubble.count() <<" microsegundos\n";
}

void insertionSort(int vetor[], int tamanhoDoVetor){
    int helper;
    std::chrono::time_point<std::chrono::steady_clock> inicioInsertion = std::chrono::steady_clock::now();
    for (int i = 1; i < tamanhoDoVetor; ++i) {
        helper = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > helper) {
            vetor[j + 1] = vetor[j];
            --j;
        }
        vetor[j + 1] = helper;
    }
    std::chrono::duration<long double,std::micro> tempoTotalInsertion = std::chrono::duration<long double,std::micro>(std::chrono::steady_clock::now() - inicioInsertion);
    std::cout<<std::fixed;
    std::cout<<"Tempo de processamento | Insertion Sort :"<<std::setprecision(10)<< tempoTotalInsertion.count() <<" microsegundos\n";
}

void compararTempoDeExecucao(int vetor[], int tamanhoDoVetor){
    int vetorBubble[200], vetorInsertion[200];
    for(int i = 0; i < tamanhoDoVetor; i++){
        vetorBubble[i] = vetor[i];
        vetorInsertion[i] = vetor[i];
    }
    std::thread selection(selectionSort,vetor,tamanhoDoVetor);
    selection.join();
    std::thread bubble(bubbleSort,vetorBubble,tamanhoDoVetor);
    bubble.join();
    std::thread insertion(insertionSort,vetorInsertion,tamanhoDoVetor);
    insertion.join();
    std::this_thread::sleep_for(std::chrono::seconds(10));
}