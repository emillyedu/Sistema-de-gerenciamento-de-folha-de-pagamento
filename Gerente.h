#ifndef GERENTE_H
#define GERENTE_H
#include "GerenciaFuncionario.h"

/** 
 *  Esta classe herda da classe abstrata "GerenciaFuncionario". É utilizada para calcular o aumento de salário
 *  de um funcionário da designação Gerente.
 *  \class
*/
class Gerente:public GerenciaFuncionario
{
public:
    Gerente();
    ~Gerente();

    /** 
     *  Um método sobrescrito que realiza o cálculo do aumento de salário para funcionários da designação Gerente.
     *  Possui um parâmetro.
     *  \param salario variável do tipo double, representando o salário do Gerente.
     *  \return double, retorna o novo salário do Gerente após o aumento.
     *  \author Êmilly Eduarda
    */
    double calculaSalario(double salario);

private:

};

#endif
