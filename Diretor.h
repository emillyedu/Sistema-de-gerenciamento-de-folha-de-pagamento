#ifndef DIRETOR_H
#define DIRETOR_H
#include "GerenciaFuncionario.h"


class Diretor:public GerenciaFuncionario
{
public:
    Diretor();
    ~Diretor();
    double calculaSalario(double salario);
private:

};

#endif