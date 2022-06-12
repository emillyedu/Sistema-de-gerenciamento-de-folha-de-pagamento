#include "Presidente.h"
#include "Operador.h"
#include "Diretor.h"
#include "Gerente.h"
#include "GerenciaFuncionario.h"
#include "GerenciaArquivo.h"

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib> 
#include <time.h> 
#include <iomanip> 

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

using namespace std;

class Funcionario:public GerenciaArquivo{
public:
    Funcionario();

    void exibeRegistroFunc();
    void exibeListaFunc();
    void exibeListaTipo();
    void exibeFolhaSalarialFuncionario();
    void exibeFolhaSalarialEmpresa();

    void addFuncionario();
    void excluirRegistro();
    void aumentoDeSalarios();
    void calculaFolhaSalarial();
    void calculaDescontos(double sa[]);
    void modificarFuncionario();
    void limpaArraySalario();

protected:
    double salarioBruto[TAM],inss[TAM],irrf[TAM],salarioLiquido[TAM], salarioEmpresa;

};

#endif
