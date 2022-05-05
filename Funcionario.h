#include "Presidente.h"
#include "Operador.h"
#include "Diretor.h"
#include "Gerente.h"
#include "GerenciaFuncionario.h"

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib> //função rand
#include <time.h> // time(0)


#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

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
    double geraDiasTrabalhados(double m);
    double geraHorasExtras(double m);

    double aumentoDeSalarios();

    string getCodigo(int i);
    string getNome(int i);
    string getEnd(int i);
    string getTelefone(int i);
    string getData(int i);
    string getDesig(int i);
    string getSalario(int i);
    string getSup(int i);
    string getAcad(int i);
    string getFormacao(int i);
    string getLinhas(int i);
    fstream getArquivo();

protected:
    fstream arquivo;
    string linhas[100];
    string codigo[100], nome[100], end[100], telefone[100], data[100], desig[100],salario[100],sup[100],acad[100],formacao[100];
};

#endif