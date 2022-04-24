#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Funcionario{
public:
    Funcionario();
    string retornaEndereco(string cep);
    void criarArquivo();
    void lerArquivo();

    void addFuncionario();

protected:
    fstream arquivo;
    string linhas[100];
};

#endif