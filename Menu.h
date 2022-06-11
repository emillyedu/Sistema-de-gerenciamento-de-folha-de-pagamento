#include <iostream>
#include <string>
#include "Funcionario.h"

#ifndef MENU_H
#define MENU_H

using namespace std;

class Menu{
public:
    Menu();
    ~Menu();
    void menuPrincipal();
    void menuExibir();
    void menuModificar();
    void menuFolhaSal();

    void cmdPrincipal();
    void cmdExibir();
    void cmdModificar();
    void cmdFolhaSal();

private:

};

#endif