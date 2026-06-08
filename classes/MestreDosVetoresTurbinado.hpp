#ifndef MESTREDOSVETORESTURBINADO_H
#define MESTREDOSVETORESTURBINADO_H
#include<iostream>
#include<thread>
#include<chrono>
#include<iomanip>
using namespace std::chrono;

template <typename T>
void mostrarVetor(T vetor[], int tamanhoDoVetor);

// Merge Sort
template <typename T>
void merge(T vetor[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    
    T* esquerdaArray = new T[n1];
    T* direitaArray = new T[n2];
    
    for (int i = 0; i < n1; i++)
        esquerdaArray[i] = vetor[esquerda + i];
    for (int j = 0; j < n2; j++)
        direitaArray[j] = vetor[meio + 1 + j];
    
    int i = 0, j = 0, k = esquerda;
    
    while (i < n1 && j < n2) {
        if (esquerdaArray[i] <= direitaArray[j]) {
            vetor[k] = esquerdaArray[i];
            i++;
        } else {
            vetor[k] = direitaArray[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        vetor[k] = esquerdaArray[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        vetor[k] = direitaArray[j];
        j++;
        k++;
    }
    
    delete[] esquerdaArray;
    delete[] direitaArray;
}

template <typename T>
void mergeSortRecursivo(T vetor[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        mergeSortRecursivo(vetor, esquerda, meio);
        mergeSortRecursivo(vetor, meio + 1, direita);
        
        merge(vetor, esquerda, meio, direita);
    }
}

template <typename T>
void mergeSort(T vetor[], int tamanhoDoVetor) {
    time_point<steady_clock> inicioMerge = steady_clock::now();
    
    mergeSortRecursivo(vetor, 0, tamanhoDoVetor - 1);
    
    duration<long double> tempoTotalMerge = duration<long double>(steady_clock::now() - inicioMerge);
    std::cout << std::fixed << "Tempo de processamento | Merge Sort :" 
              << std::setprecision(10) << tempoTotalMerge.count() << " segundos\n";
}

// Quick Sort
template <typename T>
int particionar(T vetor[], int baixo, int alto) {
    T pivo = vetor[alto];
    int i = baixo - 1;
    
    for (int j = baixo; j < alto; j++) {
        if (vetor[j] <= pivo) {
            i++;
            T temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    
    T temp = vetor[i + 1];
    vetor[i + 1] = vetor[alto];
    vetor[alto] = temp;
    
    return i + 1;
}

template <typename T>
void quickSortRecursivo(T vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int indicePivo = particionar(vetor, baixo, alto);
        
        quickSortRecursivo(vetor, baixo, indicePivo - 1);
        quickSortRecursivo(vetor, indicePivo + 1, alto);
    }
}

template <typename T>
void quickSort(T vetor[], int tamanhoDoVetor) {
    time_point<steady_clock> inicioQuick = steady_clock::now();
    
    quickSortRecursivo(vetor, 0, tamanhoDoVetor - 1);
    
    duration<long double> tempoTotalQuick = duration<long double>(steady_clock::now() - inicioQuick);
    std::cout << std::fixed << "Tempo de processamento | Quick Sort :" 
              << std::setprecision(10) << tempoTotalQuick.count() << " segundos\n";
}

// Heap Sort
template <typename T>
void heapify(T vetor[], int tamanho, int raiz) {
    int maior = raiz;
    int esquerda = 2 * raiz + 1;
    int direita = 2 * raiz + 2;
    
    if (esquerda < tamanho && vetor[esquerda] > vetor[maior])
        maior = esquerda;
    
    if (direita < tamanho && vetor[direita] > vetor[maior])
        maior = direita;
    
    if (maior != raiz) {
        T temp = vetor[raiz];
        vetor[raiz] = vetor[maior];
        vetor[maior] = temp;
        
        heapify(vetor, tamanho, maior);
    }
}

template <typename T>
void heapSort(T vetor[], int tamanhoDoVetor) {
    time_point<steady_clock> inicioHeap = steady_clock::now();
    
    // Construir o heap máximo
    for (int i = tamanhoDoVetor / 2 - 1; i >= 0; i--)
        heapify(vetor, tamanhoDoVetor, i);
    
    // Extrair elementos do heap um por um
    for (int i = tamanhoDoVetor - 1; i > 0; i--) {
        T temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        
        heapify(vetor, i, 0);
    }
    
    duration<long double> tempoTotalHeap = duration<long double>(steady_clock::now() - inicioHeap);
    std::cout << std::fixed << "Tempo de processamento | Heap Sort :" 
              << std::setprecision(10) << tempoTotalHeap.count() << " segundos\n";
}

template <typename T>
void compararTempoDeExecucao(T vetor[], int tamanhoDoVetor) {
    T vetorMerge[1000], vetorQuick[1000], vetorHeap[1000];
    
    for(int i = 0; i < tamanhoDoVetor; i++) {
        vetorMerge[i] = vetor[i];
        vetorQuick[i] = vetor[i];
        vetorHeap[i] = vetor[i];
    }
    
    std::thread merge(mergeSort<T>, vetor, tamanhoDoVetor);
    merge.join();
    
    std::thread quick(quickSort<T>, vetorMerge, tamanhoDoVetor);
    quick.join();
    
    std::thread heap(heapSort<T>, vetorHeap, tamanhoDoVetor);
    heap.join();
    
    std::this_thread::sleep_for(seconds(5));
}

#endif