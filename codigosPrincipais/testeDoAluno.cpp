#include "..\\classes\Aluno.h"
#include<iostream>

int main(){
    std::string lista[5] = {
        "Matematica",
        "Portugues",
        "Historia",
        "Geografia",
        "Ciencias"
    };

    Aluno aluno(lista,"202504940042");

    aluno.mostrarNumeroDeMatricula();
}
