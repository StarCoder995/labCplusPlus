#ifndef MESTREDOSVETORES_H
#define MESTREDOSVETORES_H
#include<iostream>
#include<thread>
#include<chrono>
#include<iomanip>
using namespace std::chrono;
    template <typename T>
    void mostrarVetor(T vetor[], int tamanhoDoVetor);

    //Selection Sort
    template <typename T>
    void selectionSort(T vetor[], int tamanhoDoVetor){
    T helper;
    time_point<steady_clock> inicioSelection = steady_clock::now();
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
    duration<long double> tempoTotalSelection = duration<long double>(steady_clock::now() - inicioSelection);
    std::cout<<std::fixed<<"Tempo de processamento | Selection Sort :"<<std::setprecision(10)<< tempoTotalSelection.count() <<" microsegundos\n";
    }

    //BubbleSort
    template <typename T>
    void bubbleSort(T vetor[], int tamanhoDoVetor){
     T helper;
    time_point<steady_clock> inicioBubble = steady_clock::now();
    for (int i = 0; i < tamanhoDoVetor - 1; ++i) {
        for (int j = 0; j < tamanhoDoVetor - 1 -i; ++j) {
            if (vetor[j] > vetor[j + 1]) {
                helper = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = helper;
            }
        }
    }
    duration<long double> tempoTotalBubble = duration<long double>(steady_clock::now() - inicioBubble);
    std::cout<<std::fixed;
    std::cout<<"Tempo de processamento | BubbleSort :"<<std::setprecision(10)<< tempoTotalBubble.count() <<" microsegundos\n";
    }

    //Insertion Sort
    template <typename T>
    void insertionSort(T vetor[], int tamanhoDoVetor){
        T helper;
        time_point<steady_clock> inicioInsertion = steady_clock::now();
        for (int i = 1; i < tamanhoDoVetor; ++i) {
            helper = vetor[i];
            int j = i - 1;
            while (j >= 0 && vetor[j] > helper) {
                 vetor[j + 1] = vetor[j];
                --j;
            }
            vetor[j + 1] = helper;
    }
        duration<long double> tempoTotalInsertion = duration<long double>(steady_clock::now() - inicioInsertion);
        std::cout<<std::fixed;
        std::cout<<"Tempo de processamento | Insertion Sort :"<<std::setprecision(10)<< tempoTotalInsertion.count() <<" segundos\n";
    }

    template <typename T>
    void compararTempoDeExecucao(T vetor[], int tamanhoDoVetor){
    T vetorBubble[100000], vetorInsertion[100000];
    for(int i = 0; i < tamanhoDoVetor; i++){
        vetorBubble[i] = vetor[i];
        vetorInsertion[i] = vetor[i];
    }
    std::thread selection(selectionSort<T>,vetor,tamanhoDoVetor);
    selection.join();
    std::thread bubble(bubbleSort<T>,vetorBubble,tamanhoDoVetor);
    bubble.join();
    std::thread insertion(insertionSort<T>,vetorInsertion,tamanhoDoVetor);
    insertion.join();
    std::this_thread::sleep_for(seconds(10));
    }
    


#endif