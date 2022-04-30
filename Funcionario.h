#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib> //função rand
#include <time.h> // time(0)

using namespace std;

class Funcionario{
public:
    Funcionario();
    void criarArquivo();
    void lerArquivo();
    void exibirArquivo();

    string retornaEndereco(string cep);
    string forEndereco(string api[], int line, int tam);

    void separadorColuna(string colunaAtual[], int del[]);
    void colunas();

    void addFuncionario();

    void excluirRegistro();
    void calculaFolhaSalarial();
    float geraDiasTrabalhados(float m);
    float geraHorasExtras(float m);

protected:
    fstream arquivo;
    string linhas[100];
    string codigo[5], nome[100], end[150], telefone[15], data[15], desig[30],salario[50],sup[100],acad[100],formacao[100];
};

#endif