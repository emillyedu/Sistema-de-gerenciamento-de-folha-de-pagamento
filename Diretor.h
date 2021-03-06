#ifndef DIRETOR_H
#define DIRETOR_H
#include "GerenciaFuncionario.h"

/** 
 *  Esta classe herda da classe abstrata "GerenciaFuncionario". É utilizada para calcular o aumento de salário
 *  de um funcionário da designação Diretor.
 *  \class
*/
class Diretor:public GerenciaFuncionario
{
public:
    Diretor();
    ~Diretor();

    /** 
     *  Método sobrescrito que calcula o aumento de salário para funcionários da designação Diretor.
     *  Possui um parâmetro.
     *  \param salario variável do tipo double.
     *  \return double, retorna o novo salário do Diretor após o aumento.
     *  \author Êmilly Eduarda
    */
    double calculaSalario(double salario);

private:

};

#endif
