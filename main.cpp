#include "Funcionario.h"
#include "Operador.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Gerente.h"
#include "Menu.h"

#include <iostream>

int main(){
    srand(time(NULL));
    Menu menu;
    Funcionario funcionario;
    
    // menu.cmdPrincipal();
    // funcionario.fotografarUsuario("123");
    funcionario.buscaPorData();

    return 0;
}
