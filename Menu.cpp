#include "Menu.h"
#include <iostream>
#include <string>
#include <windows.h>

Menu::Menu()
{

}

Menu::~Menu()
{

}


void Menu::menuPrincipal(){
    cout << "\n------ SISTEMA DE GERENCIAMENTO DE FOLHA DE PAGAMENTO ------\n\n";

    cout << "[1] Buscar funcionario\n";
    cout << "[2] Consultar funcionarios\n";
    cout << "[3] Modificar dados\n";
    cout << "[4] Conceder aumento salarial\n";
    cout << "[5] Calcular folha salarial\n";
    cout << "[6] Imprimir folha salarial\n";
    cout << "[0] Sair\n";

    cout << "\n------------------------------------------------------------\n\n";

}

void Menu::menuExibir(){
    cout << "\n------------------ CONSULTAR FUNCIONARIOS ------------------\n\n";

    cout << "[1] Consultar registro de funcionario\n";
    cout << "[2] Consultar lista de funcionarios\n";
    cout << "[3] Consultar lista de funcionarios por tipo\n";
    cout << "[0] Sair\n";

    cout << "\n------------------------------------------------------------\n\n";

}

void Menu::menuModificar(){
    cout << "\n---------------------- MODIFICAR DADOS ---------------------\n\n";

    cout << "[1] Adicionar funcionario\n";
    cout << "[2] Modificar dados do funcionario\n";
    cout << "[3] Excluir funcionario\n";
    cout << "[0] Sair\n";

    cout << "\n------------------------------------------------------------\n\n";

}


void Menu::menuFolhaSal(){
    cout << "\n------------------ IMPRIMIR FOLHA SALARIAL -----------------\n\n";

    cout << "[1] Imprimir folha salarial do FUNCIONARIO\n";
    cout << "[2] Imprimir folha salarial da EMPRESA\n";
    cout << "[0] Sair\n";

    cout << "\n------------------------------------------------------------\n\n";

}

void Menu::menuBuscar(){
    cout << "\n-------------------------- BUSCAR --------------------------\n\n";

    cout << "[1] Buscar funcionario pelo NOME\n";
    cout << "[2] Buscar Funcionario por INTERVALO DE TEMPO\n";
    cout << "[2] Buscar Funcionario pelo ENDERECO\n";
    cout << "[0] Sair\n";

    cout << "\n------------------------------------------------------------\n\n";
}


void Menu::cmdPrincipal(){
    Funcionario funcionario;
    int opcao;

    system("cls");

    cout << "\n---------- Bem vindo ao Sistema de Gerenciamento ------------\n\n";
    Sleep(5000);

    while(1){
        system("cls");

        menuPrincipal();
        
        cout << "Escolha uma das opcoes: ";
        cin >> opcao;
        getchar();

        system("cls");
        switch(opcao){
            case 1:
                funcionario.buscarFuncionario();
                break;
            case 2:
                cmdExibir();
                break;
            case 3:
                cmdModificar();
                break;
            case 4:
                funcionario.aumentoDeSalarios();
                
                cout << "\n-------------------------------------------------------------\n\n";

                cout << "\nAumento salarial concedido!" << endl;

                cout << "\n-------------------------------------------------------------\n";

                cout << "\n\n";
                system("pause");
                
                break;
            case 5:
                funcionario.calculaFolhaSalarial();

                cout << "\n-------------------------------------------------------------\n\n";

                cout << "\nFolha salarial calculada!" << endl;

                cout << "\n-------------------------------------------------------------\n";
                
                cout << "\n\n";
                system("pause");
                
                break;
            case 6:
                cmdFolhaSal();
                break;
            case 0:
                break;
            default:
                cout << "\n-------------------------------------------------------------\n\n";

                cout << "\nOpcao invalida!" << endl;

                cout << "\n-------------------------------------------------------------\n";
                
                cout << "\n\n";
                system("pause");
                break;
        }

        if(opcao == 0){
            cout << "\n-------------------------------------------------------------\n";

            cout << "\nAtendimento finalizado!" << endl;

            cout << "\n-------------------------------------------------------------\n";
            
            break;
        }
        
    }

}

void Menu::cmdExibir(){
    Funcionario funcionario;
    int opcao;

    while(1){
        system("cls");
        menuExibir();
        
        cout << "Agora escolha outra opcao: ";
        cin >> opcao;
        getchar();
        
        system("cls");
        switch(opcao){
            case 1:
                cout << "\n-------------------------------------------------------------\n";

                funcionario.exibeRegistroFunc();

                cout << "\n-------------------------------------------------------------\n";

                cout << "\n\n";
                system("pause");
                break;
            case 2:
                cout << "\n-------------------------------------------------------------\n";

                funcionario.exibeListaFunc();

                cout << "\n-------------------------------------------------------------\n";
                
                cout << "\n\n";
                system("pause");
                break;
            case 3:
                cout << "\n-------------------------------------------------------------\n";

                funcionario.exibeListaTipo();

                cout << "\n-------------------------------------------------------------\n";
                
                cout << "\n\n";
                system("pause");
                break;
            case 0:
                break;
            default:
                cout << "\n-------------------------------------------------------------\n";

                cout << "\nOpcao invalida!" << endl;

                cout << "\n-------------------------------------------------------------\n";
                
                cout << "\n\n";
                system("pause");
                break;
        }

        if(opcao == 0){
            break;
        }

    }
}
void Menu::cmdModificar(){
    Funcionario funcionario;
    int opcao;

    while(1){
        system("cls");
        menuModificar();
        
        cout << "Agora escolha outra opcao: ";
        cin >> opcao;
        getchar();

        system("cls");
        switch(opcao){
            case 1:
                funcionario.addFuncionario();
                break;
            case 2:
                funcionario.modificarFuncionario();
                break;
            case 3:
                funcionario.excluirRegistro();
                break;
            case 0:
                break;
            default:
                cout << "\n-------------------------------------------------------------\n\n";

                cout << "\nOpcao invalida!" << endl;

                cout << "\n-------------------------------------------------------------\n";
                
                cout << "\n\n";
                system("pause");
                break;
        }

        if(opcao == 0){
            break;
        }
    }
}
void Menu::cmdFolhaSal(){
    Funcionario funcionario;
    int opcao;
    
    while(1){
        system("cls");
        menuFolhaSal();
        
        cout << "Agora escolha outra opcao: ";
        cin >> opcao;
        getchar();

        system("cls");
        switch(opcao){
            case 1:

                funcionario.exibeFolhaSalarialFuncionario();

                break;
            case 2:

                funcionario.exibeFolhaSalarialEmpresa();

                break;
            case 0:
                break;
            default:
                system("cls");
                cout << "\n-------------------------------------------------------------\n\n";

                cout << "\nOpcao invalida!" << endl;

                cout << "\n-------------------------------------------------------------\n";
                
                cout << "\n\n";
                system("pause");
                break;
        }

        if(opcao == 0){
            break;
        }
        
    }
}
