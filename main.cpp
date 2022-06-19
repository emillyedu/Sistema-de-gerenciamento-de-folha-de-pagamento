#include "Funcionario.h"
#include "Operador.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Gerente.h"
#include "Menu.h"

#include <iostream>
#include<stdio.h>

int main(){
    srand(time(NULL));
    Menu menu;
    Funcionario funcionario;
    
    menu.cmdPrincipal();

    
    return 0;
}
