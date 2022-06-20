#include "Presidente.h"
#include "Operador.h"
#include "Diretor.h"
#include "Gerente.h"
#include "GerenciaFuncionario.h"
#include "GerenciaArquivo.h"

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib> 
#include <time.h> 
#include <iomanip> 

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

using namespace std;

/** 
 *  Esta classe herda de "GerenciaArquivo". É utilizada para outras operações relacionadas
 *  aos funcionários.
 *  \class
*/
class Funcionario:public GerenciaArquivo{
public:
    Funcionario();

    /** 
     *  Método que, ao inserir o código de um determinado funcionário, os usuários podem acessar
     *  todas as informações fornecidas relacionadas a esse funcionário. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void exibeRegistroFunc();

    /** 
     *  Método que exibe o registro de todos os funcionários . Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void exibeListaFunc();

    /** 
     *  Método utilizado para exibir o registro de todos os funcionários de uma determinada designação.
     *  Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void exibeListaTipo();

    /** 
     *  Método que, a partir do código ou nome de um determinado funcionário, exibe a folha 
     *  salarial desse mesmo funcionário. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Lucas Bitu
    */
    void exibeFolhaSalarialFuncionario();

    /** 
     *  Um método que exibe a folha salarial mensal ou anual da empresa. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Lucas Bitu
    */
    void exibeFolhaSalarialEmpresa();

    /** 
     *  Método utilizado para tirar uma foto do funcionário, no momento em que este estiver sendo adicionado
     *  na empresa. Possui um parâmetro.
     *  \param cod string com o código do funcionário.
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda e Lucas Bitu
    */
    void fotografarUsuario(string cod);


    /** 
     *  Um método utilizado para renovar a foto do funcionário. Possui um parâmetro.
     *  \param cod string com o código do funcionário.
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda e Lucas Bitu
    */
    void renovarFoto(string cod);

    /** 
     *  Método utilizado para exibir a foto do funcionário. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda e Lucas Bitu
    */
    void exibeFoto();

    /** 
     *  Este método adiciona um novo funcionário na empresa, recebendo todos os seus dados e armazenando estes no
     *  arquivo csv. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void addFuncionario();

    /** 
     *  Tal método realiza a busca parcial de funcionários da empresa, podendo ser uma busca por nome, data de ingresso
     *  ou endereço. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void buscarFuncionario();

    /** 
     *  Método utilizado para excluir os dados, de um determinado funcionário da empresa, do arquivo csv.
     *  Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Lucas Bitu
    */
    void excluirRegistro();

    /** 
     *  Método que concede aumento de salário para todos os funcionários da empresa, de acordo com a designação
     *  dos mesmos. Operador: 5% de aumento; Gerente: 10% de aumento; Diretor: 20% de aumento; Presidente: 30%
     *  de aumento. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void aumentoDeSalarios();

    /** 
     *  Tal método realiza o cálculo de salário de todos os funcionários para um determinado mês. Não possui parâmetros.
     *  \return bool, falso caso ja tenha sido calculada antes e true caso contrário.
     *  \author Lucas Bitu
    */
    bool calculaFolhaSalarial();

    /** 
     *  Tal método é responsável por realizar a modificação dos dados de funcionários da empresa, salvando essas
     *  modificações no arquivo csv. É possível modificar o código, nome, endereço, telefone, data de ingresso,
     *  salário e designação dos funcionários. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void modificarFuncionario();

protected:

};

#endif
