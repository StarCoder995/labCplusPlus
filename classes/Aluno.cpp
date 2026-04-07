#include "Aluno.h"
#include<iostream>

Aluno::Aluno() : numeroDeMatricula("") {
    for(int i = 0; i < 5; i++){
        this->listaDeDisciplinas[i] = "";
    }
}

Aluno::Aluno(std::string l[], std::string n) : numeroDeMatricula(n) {
    for(int i = 0; i < 5; i++){
        this->listaDeDisciplinas[i] = l[i];
    }
}

void Aluno::mostrarListaDeDisciplinas(){
    std::cout<<"\n";
    for(int i = 0; i < 5; i++){
        std::cout<<this->listaDeDisciplinas[i]<<"\n";
}
}

void Aluno::mostrarNumeroDeMatricula(){
   std::cout<<"Matricula do aluno: "<<this->numeroDeMatricula;
}