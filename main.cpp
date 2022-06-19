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

    // string str;
    // getline(cin, str);
    // if(str.size()==0){
    //     cout << "sem tamanho" << endl;
    // }

    
    return 0;
}
