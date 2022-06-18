#ifndef GERENCIAFUNCIONARIO_H
#define GERENCIAFUNCIONARIO_H

/** 
 *  Classe abstrata utilizada para ser herdada e auxiliar a gerenciar o salário dos funcionários de diferentes
 *  designações.
 *  \class
*/
class GerenciaFuncionario
{
public:
    GerenciaFuncionario();
    ~GerenciaFuncionario();

    /** 
     *  Tal método realiza o cálculo do aumento de salário, que é diferente, para as diferentes designações de
     *  funcionários. Isso, quando o método é sobrescrito nas classes filhas. Possui um parâmetro.
     *  \param salario variável do tipo double, representando o salário de um funcionário(a).
     *  \return double, retorna o novo salário do funcionário(a) após o aumento.
     *  \author Êmilly Eduarda
    */
    virtual double calculaSalario(double salario) = 0;

private:

};

#endif
