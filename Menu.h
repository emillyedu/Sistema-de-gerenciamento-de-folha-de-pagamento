#include <iostream>
#include <string>
#include "Funcionario.h"

#ifndef MENU_H
#define MENU_H

using namespace std;

/** 
 *  Classe utilizada para gerenciar o menu do programa, tornando possível uma melhor interação do usuário com o
 *  Sistema de Gerenciamento de Folha de Pagamento.
 *  \class
*/
class Menu{
public:
    Menu();
    ~Menu();

    /** 
     *  Este método é o menu principal do sistema, apresentando as opções para o usuário escolher qual/quais
     *  operações realizar com os funcionários da empresa, ou simplesmente sair do programa. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void menuPrincipal();

    /** 
     *  Método que constitui o menu de exibição do sistema, apresentando as opções para operações relativas à exibição
     *  dos dados. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void menuExibir();

    /** 
     *  Tal método é o menu de modificação de dados do sistema, apresentando opções que dizem respeito à modificação
     *  de dados dos funcionários. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void menuModificar();

    /** 
     *  Tal método constitui o menu de impressão da folha salarial do sistema, apresentando opções relacionadas às
     *  impressões de folhas salariais. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void menuFolhaSal();

    /** 
     *  Tal método é usado para exibir as opções: renovar foto, ou exibir foto. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void menuFotos();

    /** 
     *  Tal método é o menu de impressão e edição de fotos, apresentando as seguintes opções: renovar foto, ou exibir foto. 
     *  Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void cmdFotos();

    /** 
     *  Método responsável por organizar como os diferentes métodos para operações, nos diferentes menus, serão chamados e
     *  apresentados no Prompt de Comando do computador, ao longo da execução do programa. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void cmdPrincipal();

    /** 
     *  Método responsável pela organização de como os diferentes métodos para operações, no menu de exibição do sistema,
     *  serão chamados e apresentados no Prompt de Comando. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void cmdExibir();

    /** 
     *  Um método responsável por organizar como os diferentes métodos para operações, no menu de modificação de dados
     *  do sistema, serão chamados e apresentados no Prompt de Comando. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void cmdModificar();

    /** 
     *  Método responsável por organizar como os diferentes métodos para operações, no menu de impressão da folha
     *  salarial do sistema, serão chamados e apresentados no Prompt de Comando. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void cmdFolhaSal();

private:

};

#endif
