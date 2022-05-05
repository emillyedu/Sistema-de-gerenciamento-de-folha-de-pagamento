#ifndef PRESIDENTE_H
#define PRESIDENTE_H
#include "GerenciaFuncionario.h"

class Presidente:public GerenciaFuncionario
{
public:
    Presidente();
    ~Presidente();
    double calculaSalario(double salario);
private:

};

#endif