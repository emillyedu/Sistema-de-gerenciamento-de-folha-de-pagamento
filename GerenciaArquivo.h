#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#define TAM 100


#ifndef GERENCIAARQUIVO_H
#define GERENCIAARQUIVO_H

using namespace std;

class GerenciaArquivo
{
public:
    GerenciaArquivo();
    ~GerenciaArquivo();

    void clearString(string *str);
    string transformaStringMin(string str);
    bool isNumber(const string& str);

    void criarArquivo();
    void lerArquivo();
    void exibirArquivo();

    void separadorColuna(string colunaAtual[], int del[]);
    void colunas();

    string retornaEndereco(string cep);
    string forEndereco(string api[], int line, int tam);

    double geraDiasTrabalhados(double m);
    double geraHorasExtras(double m);

    void calculaDescontos(double sa[]);
    void limpaArraySalario();
    
    void buscaPorNome();
    void buscaPorData();
    void buscaPorEndereco();
    
    void modificaCodigo(string cod);
    void modificaNome(string cod);
    void modificaEndereco(string cod);
    void modificaTelefone(string cod);
    void modificaData(string cod);
    void modificaSalario(string cod);
    void modificaDesignacao(string cod);
    void modDesigDeOperador(string cod);
    void modDesigDeGerente(string cod);
    void modDesigDeDiretor(string cod);
    void modDesigDePresidente(string cod);
    void modDesigParaOperador(string cod);

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
    
protected:
    fstream arquivo;
    int tamArq;
    string linhas[TAM], Nan = {"Nan"};;
    string codigo[TAM], nome[TAM], end[TAM], telefone[TAM], data[TAM], desig[TAM],salario[TAM],sup[TAM],acad[TAM],formacao[TAM];
    double salarioBruto[TAM],inss[TAM],irrf[TAM],salarioLiquido[TAM], salarioEmpresa;

};

#endif
