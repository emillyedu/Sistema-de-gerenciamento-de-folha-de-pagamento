#ifndef PRESIDENTE_H
#define PRESIDENTE_H
#include "GerenciaFuncionario.h"

/** 
 *  Esta classe herda da classe abstrata "GerenciaFuncionario". É utilizada para calcular o aumento de salário
 *  de um funcionário da designação Presidente.
 *  \class
*/
class Presidente:public GerenciaFuncionario
{
public:
    Presidente();
    ~Presidente();

    /** 
     *  Um método sobrescrito que realiza o cálculo do aumento de salário para funcionários da designação Presidente.
     *  Possui um parâmetro.
     *  \param salario variável do tipo double, representando o salário do Presidente.
     *  \return double, retorna o novo salário do Presidente após o aumento.
     *  \author Êmilly Eduarda
    */
    double calculaSalario(double salario);

private:

};

#endif
