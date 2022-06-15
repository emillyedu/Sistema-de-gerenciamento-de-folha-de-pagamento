#include "Funcionario.h"
#include "Operador.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Gerente.h"
#include "Menu.h"

#include <iostream>


int main(){
    srand(time(NULL));
    Funcionario funcionario;
    Menu menu;
    string str;
    
    menu.cmdPrincipal();
    //funcionario.fotografarUsuario("emilly");

    return 0;
}
