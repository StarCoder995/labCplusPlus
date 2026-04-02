#ifndef ALUNO_H
#define ALUNO_H
#include<iostream>

class Aluno{
    private:
        std::string listaDeDisciplinas[5];
        std::string numeroDeMatricula;

    public:
        Aluno();
        Aluno(std::string listaDeDisciplinas[5],std::string numeroDeMatricula);

        void mostrarListaDeDisciplinas();
        void mostrarNumeroDeMatricula();
        
};
#endif