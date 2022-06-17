#ifndef OPERADOR_H
#define OPERADOR_H
#include "GerenciaFuncionario.h"

/*! Esta classe herda da classe abstrata "GerenciaFuncionario". É utilizada para calcular o aumento de salário
 *  de um funcionário da designação Operador.
 *  \class
*/
class Operador:public GerenciaFuncionario
{
public:
    Operador();
    ~Operador();

    /*! Tal método sobrescrito realiza o cálculo do aumento de salário para funcionários da designação Operador.
     *  Possui um parâmetro.
     *  \param salario variável do tipo double, representando o salário do Operador.
     *  \return double, retorna o novo salário do Operador após o aumento.
     *  \author Lucas Bitu
    */
    double calculaSalario(double salario);

private:

};

#endif
