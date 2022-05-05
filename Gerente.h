#ifndef GERENTE_H
#define GERENTE_H
#include "GerenciaFuncionario.h"

class Gerente:public GerenciaFuncionario
{
public:
    Gerente();
    ~Gerente();
    double calculaSalario(double salario);
private:

};

#endif