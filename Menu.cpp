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
    cout << "[7] Fotografia\n";
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

void Menu::menuFotos(){
    cout << "\n-------------------------- FOTOS --------------------------\n\n";

    cout << "[1] Renovar foto do funcionario\n";
    cout << "[2] Exibir foto do funcionario\n";
    cout << "[0] Sair\n";

    cout << "\n------------------------------------------------------------\n\n";
}


void Menu::cmdPrincipal(){
    Funcionario funcionario;
    int opcao;
    bool teste;

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
                
                cout << "\n-------------------------------------------------------------\n";

                cout << "\nAumento salarial concedido!" << endl;

                cout << "\n-------------------------------------------------------------\n";

                cout << "\n\n";
                system("pause");
                
                break;
            case 5:
                teste = funcionario.calculaFolhaSalarial();

                if(teste){
                    cout << "\n-------------------------------------------------------------\n";

                    cout << "\nFolha salarial calculada!" << endl;

                    cout << "\n-------------------------------------------------------------\n";
                    
                    cout << "\n\n";
                    system("pause");
                }else{
                    cout << "\n-------------------------------------------------------------\n";

                    cout << "\nFolha salarial ja havia sido calculada!" << endl;

                    cout << "\n-------------------------------------------------------------\n";
                    
                    cout << "\n\n";
                    system("pause");
                }
                
                break;
            case 6:
                cmdFolhaSal();
                break;
            case 7:
                cmdFotos();
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
            cout << "\n-------------------------------------------------------------\n";

            cout << "\nAtendimento finalizado!" << endl;

            cout << "\n-------------------------------------------------------------\n";
            
            break;
        }
        
    }

}

void Menu::cmdFotos(){
    Funcionario funcionario;
    int opcao;
    string cod, codigo;

    while(1){
        system("cls");
        menuFotos();
        
        cout << "Agora escolha outra opcao: ";
        cin >> opcao;
        getchar();
        
        system("cls");
        switch(opcao){
            case 1:
                while(1){
                    cout << "Insira o codigo do funcionario desejado: ";
                    getline(cin, codigo);
                    system("cls");

                    if(codigo.length() == 3){
                        cod = codigo;
                        break;
                    }
                    else if(codigo.length() == 2){
                        cod = "0" + codigo;
                        break;
                    }
                    else if(codigo.length() == 1){
                        cod = "00" + codigo;
                        break;
                    }
                    else{
                        cout << "Codigo maior do que o esperado\n" << endl;
                        continue;
                    }
                }

                funcionario.renovarFoto(cod);

                break;
            case 2:
                funcionario.exibeFoto();
                cout << "\n-------------------------------------------------------------\n";

                cout << "\nFoto exibida!" << endl;

                cout << "\n-------------------------------------------------------------\n";
                
                cout << "\n\n";
                Sleep(5000);
                system("cls");
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

