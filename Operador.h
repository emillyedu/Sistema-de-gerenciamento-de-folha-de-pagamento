#ifndef OPERADOR_H
#define OPERADOR_H
#include "GerenciaFuncionario.h"

/** 
 *  Esta classe herda da classe abstrata "GerenciaFuncionario". É utilizada para calcular o aumento de salário
 *  de um funcionário da designação Operador.
 *  \class
*/
class Operador:public GerenciaFuncionario
{
public:
    Operador();
    ~Operador();

    /** 
     *  Método sobrescrito para realizar o cálculo do aumento de salário para funcionários da designação Operador.
     *  Possui um parâmetro.
     *  \param salario variável do tipo double.
     *  \return double, retorna o novo salário do Operador após o aumento.
     *  \author Êmilly Eduarda
    */
    double calculaSalario(double salario);

private:

};

#endif
