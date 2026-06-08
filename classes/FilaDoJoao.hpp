#ifndef FILADOJOAO_HPP
#define FILADOJOAO_HPP
#include<iostream>
#include<map>
using namespace std;
template <typename T>
struct itemDeFila{
    T valorAtual;
    int indice;
    itemDeFila<T>* proximo;
};

template<typename T>
class Fila{
    private:
        map<string, itemDeFila<T>*> filas;
        map<string, itemDeFila<T>*> finsDefilas;
    public:
        Fila( ){
        }
        int contarItens(string nome){
            itemDeFila<T> leitor;
            leitor.proximo = filas.at(nome);
            int numeroDeItens = 0;
            cout<<"Valores atuais na fila:\n";
            do{
                numeroDeItens++;
                leitor.proximo = leitor.proximo->proximo;
            }while(leitor.proximo != NULL);
            return numeroDeItens;
        }
        void criarFila(string nome, T valorInicial){
             itemDeFila<T>* item = new itemDeFila<T>;
             item->indice = 0;
             item->valorAtual = valorInicial;
             item->proximo = NULL;

             filas[nome] = item;
             finsDefilas[nome] = item;
        }

         void inserirNaFila(string nome,T valorInserido){
            itemDeFila<T>* item = new itemDeFila<T>;
             item->indice = contarItens(nome);
             item->valorAtual = valorInserido;
             item->proximo = NULL;

             finsDefilas[nome]->proximo = item;
             finsDefilas[nome] = item;
        }

        void imprimirFila(string nome){
            itemDeFila<T> leitor;
            leitor.proximo = filas.at(nome);
            cout<<"Valores atuais na fila:\n";
            do{
                cout<<"Posicao: "<<leitor.proximo->indice << " | Valor: "<<leitor.proximo->valorAtual<<"\n";
                leitor.proximo = leitor.proximo->proximo;
            }while(leitor.proximo != NULL);
        }
};



#endif