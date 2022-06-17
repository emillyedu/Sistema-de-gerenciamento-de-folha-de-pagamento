#ifndef GERENCIAFUNCIONARIO_H
#define GERENCIAFUNCIONARIO_H

/*! Classe abstrata utilizada para gerenciar o salário dos funcionários.
 *  \class
*/
class GerenciaFuncionario
{
public:
    GerenciaFuncionario();
    ~GerenciaFuncionario();

    /*! Tal método, ...  . Possui um parâmetro.
     *  \param salario ...
     *  \return double, ...
     *  \author ???
    */
    virtual double calculaSalario(double salario) = 0;

private:

};

#endif
