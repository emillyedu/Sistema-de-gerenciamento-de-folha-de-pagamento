#include "Funcionario.h"
#include "Operador.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Gerente.h"

#include <iostream>


int main(){
    srand(time(NULL));
    Funcionario funcionario;
    
    funcionario.exibeFolhaSalarialEmpresa();
    
    return 0;
}
