#ifndef OPERADOR_H
#define OPERADOR_H
#include "GerenciaFuncionario.h"

class Operador:public GerenciaFuncionario
{
public:
    Operador();
    ~Operador();
    double calculaSalario(double salario);


private:

};

#endif