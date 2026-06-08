#include"../classes/FilaDoJoao.hpp"
#include<iostream>
#include<typeinfo>
#include<locale.h>
using namespace std;
int main(){
    setlocale(LC_ALL,"Portuguese");
    int op;
    string nomeDaFila,escolha = "s";
    string val;
    Fila<string> filas;
    do{
        cout<<"Bem vindo, o que deseja fazer?\n 1 - Criar uma Fila | 2 - Imprimir uma fila | 3 - Adicionar um item a uma fila\nDigite sua escolha: "<<flush;
        cin>>op;
        switch(op){
            case 1:
                cout<<"Vamos criar uma fila agora\nDigite o nome dela: ";
                cin.ignore();
                getline(cin,nomeDaFila);
                cout<<"Digite o primeiro valor: ";
                cin>>val;
                filas.criarFila(nomeDaFila,val);
                break;
            case 2:
                cout<<"Vamos imprimir uma fila agora\nDigite o nome dela: ";
                cin.ignore();
                getline(cin,nomeDaFila);
                filas.imprimirFila(nomeDaFila);
                break;
            case 3:
                cout<<"Vamos adicionar um item a uma fila agora\nDigite o nome dela: ";
                cin.ignore();
                getline(cin,nomeDaFila);
                cout<<"Digite o valor: ";
                cin>>val;
                filas.inserirNaFila(nomeDaFila,val);
                break;
            default:
                break;
    }
    }while(escolha == "s");
    cout<<"\nOperações Encerradas!";
    
    

}