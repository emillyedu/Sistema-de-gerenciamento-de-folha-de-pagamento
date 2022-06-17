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

/*! Esta classe herda da classe "GerenciaArquivo". É utilizada, também, para outras operações relacionadas
 *  aos funcionários.
 *  \class
*/
class Funcionario:public GerenciaArquivo{
public:
    Funcionario();


    /*! Por meio deste método, ao inserir o número de código de um determinado funcionário, os usuários podem acessar
     *  todas as informações fornecidas relacionadas a esse funcionário. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Lucas Bitu
    */
    void exibeRegistroFunc();

    /*! Método que exibe o registro de todos os funcionários . Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Lucas Bitu
    */
    void exibeListaFunc();

    /*! Método utilizado para exibir o registro de todos os funcionários de uma determinada designação.
     *  Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Lucas Bitu
    */
    void exibeListaTipo();

    /*! Método que; a partir do código ou nome de um determinado funcionário, informado pelo usuário; exibe a folha 
     *  salarial desse mesmo funcionário. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Lucas Bitu
    */
    void exibeFolhaSalarialFuncionario();

    /*! Um método que exibe a folha salarial mensal ou anual da empresa. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Lucas Bitu
    */
    void exibeFolhaSalarialEmpresa();

    /*! Um método utilizado para tirar uma foto do funcionário, no momento em que este estiver sendo adicionado
     *  na empresa. Possui um parâmetro.
     *  \param cod uma variável do tipo string que recebe o código do funcionário para cada foto ficar salva
     *  para cada funcionário de forma correta. 
     *  \return void, não possui retorno.
     *  \author ???
    */
    void fotografarUsuario(string cod);

    /*! Este método adiciona um novo funcionário na empresa, recebendo todos os seus dados e armazenando estes no
     *  arquivo csv. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly
    */
    void addFuncionario();

    /*! Tal método é responsável por realizar a busca parcial de funcionários da empresa, podendo ser uma busca por
     *  nome, data de ingresso ou endereço. Para isso, faz uso dos métodos auxiliares presentes na classe "GerenciaArquivo".
     *  Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void buscarFuncionario();

    /*! Um método utilizado para excluir, do arquivo csv, os dados de um determinado funcionário da empresa, a partir
     *  do código desse funcionário. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Lucas Bitu
    */
    void excluirRegistro();

    /*! Método que concede aumento de salário para todos os funcionários da empresa, de acordo com a designação
     *  dos mesmos. Operador: 5% de aumento; Gerente: 10% de aumento; Diretor: 20% de aumento; Presidente: 30%
     *  de aumento. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author ???
    */
    void aumentoDeSalarios();

    /*! Tal método realiza o cálculo de salário de todos os funcionários para um determinado mês. É solicitado ao
     *  usuário: o mês e a folha salarial à qual se refere. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Lucas Bitu
    */
    void calculaFolhaSalarial();

    /*! Tal método é responsável por realizar a modificação dos dados de funcionários da empresa, salvando essas
     *  modificações no arquivo csv. É possível modificar o código, nome, endereço, telefone, data de ingresso,
     *  salário e designação dos funcionários. Para isso, faz uso dos métodos auxiliares presentes na classe
     *  "GerenciaArquivo". Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void modificarFuncionario();

protected:

};

#endif
