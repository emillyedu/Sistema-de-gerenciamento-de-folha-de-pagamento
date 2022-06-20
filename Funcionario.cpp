#include "Funcionario.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <windows.h>

using namespace std;

Funcionario::Funcionario(){
}

void Funcionario::renovarFoto(string cod){
    bool teste;
    
    lerArquivo();
    colunas();

    teste = true;
    for(int i = 0; i < TAM; i++){
        if(cod == getCodigo(i)){
            teste = false;
            break;
        }
    }

    if(teste){
        system("cls");
        cout << "Codigo nao pertence a um funcinario" << endl;
        Sleep(5000);
        system("cls");
    }else{
        fotografarUsuario(cod);
    }
}

void Funcionario::fotografarUsuario(string cod){
    string command;
    char yn;
    
    system("cls");

    while(1){
        system("cls");
        cout << "Esta pronto para tirar sua foto? [s/n]" << endl;
        cin >> yn;

        system("cls");

        if(yn == 's' || yn == 'S'){
            cout << "OK! Prepare-se para a foto :)" << endl;
            Sleep(5000);
            system("cls");
        }
        else if(yn == 'n' || yn == 'N'){
            cout << "Que pena :(" << endl;
            cout << "Iremos aguardar 10 segundos!" << endl;
            Sleep(10000);
            system("cls");
            continue;
        }
        else{
            continue;
        }

        command = "CommandCam /quiet /filename " + cod + ".jpg";
        system(command.c_str());
        cout << "\n-------------------------------------------------------------\n";
        cout << "\nFoto tirada!" << endl;
        cout << "\n-------------------------------------------------------------\n";
        Sleep(5000);

        system("cls");

        command = "move \"./" + cod + ".jpg\" " + "\"./fotos-funcionarios\"";
        system(command.c_str());
        system("cls");
        break;
    }
    system("cls");
    cout << "Deseja ver a sua foto? [s/n]" << endl;
    cin >> yn;
    system("cls");
    if(yn == 's' || yn == 'S'){
        command = "start ./fotos-funcionarios/" + cod +".jpg";
        system((command).c_str());
        cout << "\n-------------------------------------------------------------\n";
        cout << "\nFoto exibida!" << endl;
        cout << "\n-------------------------------------------------------------\n";
        Sleep(5000);

        system("cls");
    }

    system("cls");
    

}

void Funcionario::exibeFoto(){
    string command, cod, codigo;
    bool teste;

    lerArquivo();
    colunas();

    while(1){
        system("cls");
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
    
    teste = true;
    for(int i = 0; i < TAM; i++){
        if(cod == getCodigo(i)){
            command = "start ./fotos-funcionarios/" + cod +".jpg";
            system((command).c_str());
            teste = false;
            break;
        }
    }

    if(teste){
        system("cls");
        cout << "Codigo nao pertence a um funcinario" << endl;
        Sleep(5000);
        system("cls");
    }

}

void Funcionario::exibeRegistroFunc(){
    //Ao inserir o número de código do funcionário, os usuários podem acessar todas as informações 
    //fornecidas relacionadas a um determinado funcionário por meio desta função.
    string cod, codigo;
    int flag = 0;

    lerArquivo();

    while(1){
        cout << "Insira o codigo do funcionario desejado: ";
        getline(cin, cod);
        system("cls");

        if(cod.length() == 3){
            codigo = cod;
            break;
        }
        else if(cod.length() == 2){
            codigo = "0" + cod;
            break;
        }
        else if(cod.length() == 1){
            codigo = "00" + cod;
            break;
        }
        else{
            cout << "Codigo maior do que o esperado\n" << endl;
            continue;
        }
    }

    for(int i = 0; i < TAM; i++){
        if(linhas[i] != ""){
            colunas();
        }
        if(getCodigo(i) == codigo){
            cout << "Codigo............: " << getCodigo(i) << endl;
            cout << "Nome..............: " << getNome(i) << endl;
            cout << "Endereco..........: " << getEnd(i) << endl;
            cout << "Telefone..........: " << getTelefone(i) << endl;
            cout << "Data de ingresso..: " << getData(i) << endl;
            cout << "Designacao........: " << getDesig(i) << endl;
            cout << "Salario...........: " << getSalario(i) << endl;
            if(getSup(i) != Nan){
                cout << "Area de supervisao: " << getSup(i) << endl;
            }
            if(getAcad(i) != Nan){
                cout << "Area academica....: " << getAcad(i) << endl;
            }
            if(getFormacao(i) != Nan){
                cout << "Formacao maxima...: " << getFormacao(i) << endl << endl;     
            }
            flag = 1;
            break;
        }
    }
    
    if(flag == 0){
        cout << "Funcionario nao encontrado\n" << endl;
    }
}

void Funcionario::exibeListaFunc(){
    //Este recurso exibe o registro de todos os funcionários 
    lerArquivo();

    cout << "Codigo,Nome,Designacao" << endl;
    for(int i = 0; i < TAM; i++){
        if(linhas[i] != ""){
            colunas();
        }
        if((getCodigo(i) != "") && (getNome(i) != "") && (getDesig(i) != "")){
            cout << getCodigo(i) << "," << getNome(i) << "," << getDesig(i) << endl;
        }
    }
}

void Funcionario::exibeListaTipo(){
    //Este recurso exibe o registro de todos os funcionários de um determinado tipo
    int c, flag = 0, desig;
    string designacao;

    lerArquivo();

    c = 1;
    while(1){
        cout << "Insira a designacao que deseja observar:\n";
        cout << "(1) Operador\n";
        cout << "(2) Gerente\n";
        cout << "(3) Diretor\n";
        cout << "(4) Presidente\n\n";

        cin >> desig;
        getchar();

        system("cls");

        switch (desig){
        case 1:
            designacao = "operador";
            c = 0;
            break;
        case 2:
            designacao = "gerente";
            c = 0;
            break;
        case 3:
            designacao = "diretor";
            c = 0;
            break;
        case 4:
            designacao = "presidente";
            c = 0;
            break;
        default:
            cout << "Invalido! Tente novamente\n";
            break;
        }

        if(c == 0){
            break;
        }
    }
    
    for(int i = 0; i < TAM; i++){
        if(linhas[i] != ""){
            colunas();
        }
        if(getDesig(i) == designacao){
            flag = 1;
        }
    }

    if(flag == 0){
        cout << "Nao foi encontrado nenhum funcionario\n" << endl;
        return;
    }

    cout << "Codigo,Nome,Designacao" << endl;
    for(int i = 0; i < TAM; i++){
        if(getDesig(i) == designacao){
            cout << getCodigo(i) << "," << getNome(i) << "," << getDesig(i) << endl;
        }
    }
}

void Funcionario::aumentoDeSalarios(){
    Operador operador;
    Gerente gerente;
    Presidente presidente;
    Diretor diretor;
    
    double salarioAum[TAM];

    criarArquivo();
    lerArquivo();

    int count ;
    for(int i = 1, j = 0; i < TAM; i++, j++){
        count = 0;
        if(linhas[i] != ""){
            count = 1;

            colunas();
        
            if(getDesig(j) == "operador"){
                salarioAum[j] = operador.calculaSalario(stod(getSalario(j)));
            }
            else if(getDesig(j)  == "presidente"){
                salarioAum[j] = presidente.calculaSalario(stod(getSalario(j)));
            }
            else if(getDesig(j) == "gerente"){
                salarioAum[j] = gerente.calculaSalario(stod(getSalario(j)));
            }
            else if(getDesig(j) == "diretor"){
                salarioAum[j] = diretor.calculaSalario(stod(getSalario(j)));
            }
        }

        if(count = 0){
            break;
        }
    }

    arquivo.open("./csv/Empresa.csv", ios::out);
        arquivo << "codigo,nome,end,telefone,data de ingresso,designacao,salario,area de supervisao,area academica,formacao maxima" << endl;
        for(int i = 0; i < TAM; i++){
            if(linhas[i+1] != ""){
                arquivo << getCodigo(i) + "," + getNome(i) + "," + getEnd(i) + "," + getTelefone(i) + "," + getData(i) + "," + getDesig(i) + "," + to_string(salarioAum[i]).erase(to_string(salarioAum[i]).size()-4, 4) + "," + getSup(i) + "," + getAcad(i) + "," + getFormacao(i) << endl;
            }
            else{
                break;
            }
        }
    arquivo.close();

}

void Funcionario::addFuncionario(){
    typedef struct{
        string dia;
        string mes;
        string ano;
    } Data;

    Data data;
    string nome, aux, codigo, cod, telefone, designacao, endereco, cep, numero, areaS[2], areaF[2], formacao;
    string logradouro, bairro, cidade, uf, linha[TAM], line, dia, mes, ano, salario;
    string yn, desig;
    bool teste;
    int i, c, li = 0;


    criarArquivo();
    lerArquivo();

    cout << "\n-------------------------------------------------------------\n\n";
    exibeListaFunc();
    cout << "\n-------------------------------------------------------------\n";

    while(1){
        cout << "\nDeseja adicionar funcionario? [s/n]" << endl;
        cin >> yn;
        getchar();
        if(yn == "S" || yn == "s" ||yn == "N" || yn == "n"){
            break;
        }
        else if(yn.length() > 1){
            system("cls");
            continue;
        }
        else{
            system("cls");
            continue;
        }
        system("cls");
    }
    system("cls");
    
    while(yn == "S" || yn == "s"){
        while(1){
            c = 1;
            while(1){
                system("cls");
                cout << "Digite o codigo: ";
                getline(cin, cod);
                system("cls");

                if(cod.length() == 3){
                    codigo = cod;
                    break;
                }
                else if(cod.length() == 2){
                    codigo = "0" + cod;
                    break;
                }
                else if(cod.length() == 1){
                    codigo = "00" + cod;
                    break;
                }
                else{
                    cout << "codigo maior do que o esperado\n" << endl;
                    Sleep(5000);
                    continue;
                }            
            }
            for(i = 1; i < TAM; i++){
                if(linhas[i] != ""){
                    colunas();
                }
                if(getCodigo(i-1) == codigo){
                    cout << "codigo invalido, tente novamente\n" << endl;
                    Sleep(5000);
                    c = 0;
                    break;
                }
            }
            if(c == 0){
                continue;
            }
            if(c == 1){
                teste = false;

                for(int i = 0; i < codigo.size(); i++){
                    if(codigo[i] != ','){
                    }else{
                        teste = true;
                        system("cls");
                        cout << "Codigo invalido, digite sem virgulas" << endl;
                        Sleep(5000);
                        system("cls");
                        break;
                    }
                }
            }
            if(teste){
                continue;
            }
            else{
                break;
            }
        }

        while(1){
            system("cls");
            teste = false;
            cout << "Digite o nome: ";
            getline(cin, nome);

            for(int i = 0; i < nome.size(); i++){
                if(nome[i] != ','){
                }else{
                    teste = true;
                    system("cls");
                    cout << "Nome invalido, digite sem virgulas" << endl;
                    Sleep(5000);
                    system("cls");
                    break;
                }
            }

            if(teste){
                continue;
            }else
                break;
        }

        system("cls");


        while(1){
            cout << "Poderia informar seu CEP? [s/n]: ";
            cin >> yn;
            getchar();
            if(yn == "S" || yn == "s" ||yn == "N" || yn == "n"){
                break;
            }
            else if(yn.length() > 1){
                system("cls");
                continue;
            }
            else{
                system("cls");
                continue;
            } 
            system("cls");
        }
        system("cls");

        while(1){
            system("cls");
            if(yn == "S" || yn == "s"){
                cout << "Digite seu CEP: ";
                getline(cin, cep);

                if(cep.length() > 8 || cep.length() < 8){
                    cout << "CEP invalido\n" << endl;
                    Sleep(5000);
                    continue;
                }
                else{
                    endereco = retornaEndereco(cep);
                    break;
                }
            }
            else{
                break;
            }
        }
        system("cls");
        if(endereco == Nan || yn == "N" || yn == "n"){
            while(1){
                endereco.clear();
                cep.clear();
                cout << "Informe o logradouro: ";
                getline(cin, logradouro);
                cout << "Informe o bairro: ";
                getline(cin, bairro);
                cout << "Informe a cidade: ";
                getline(cin, cidade);
                cout << "Informe a Uf: ";
                getline(cin, uf);
                system("cls");

                teste = false;

                for(int i = 0; i < logradouro.size(); i++){
                    if((logradouro[i] != ',')){
                    }else{
                        teste = true;
                        system("cls");
                        cout << "Endereco invalido, digite sem virgulas" << endl;
                        Sleep(5000);
                        system("cls");
                        break;
                    }
                }
                for(int i = 0; i < bairro.size(); i++){
                    if((bairro[i] != ',')){
                    }else{
                        teste = true;
                        system("cls");
                        cout << "Endereco invalido, digite sem virgulas" << endl;
                        Sleep(5000);
                        system("cls");
                        break;
                    }
                }
                for(int i = 0; i < cidade.size(); i++){
                    if((cidade[i] != ',')){
                    }else{
                        teste = true;
                        system("cls");
                        cout << "Endereco invalido, digite sem virgulas" << endl;
                        Sleep(5000);
                        system("cls");
                        break;
                    }
                }
                for(int i = 0; i < uf.size(); i++){
                    if((uf[i] != ',')){
                    }else{
                        teste = true;
                        system("cls");
                        cout << "Endereco invalido, digite sem virgulas" << endl;
                        Sleep(5000);
                        system("cls");
                        break;
                    }
                }

                if(teste){
                    continue;
                }else
                    break;
            }
            endereco = "Logradouro: " + logradouro + " - " "Bairro: " + bairro + " - " + "Cidade: " + cidade + " - " + "UF: " + uf;            
        }
    

        cout << "Digite o numero da casa: ";
        getline(cin, numero);

        endereco = endereco + " - numero: " + numero;
        system("cls");

        while(1){
            system("cls");
            teste = false;
            cout << "telefone - formato: (00) 00000-0000: ";
            getline(cin, telefone);
            system("cls");

            for(int i = 0; i < telefone.size(); i++){
                if(telefone[i] != ','){
                }else{
                    teste = true;
                    system("cls");
                    cout << "Telefone invalido, digite sem virgulas" << endl;
                    Sleep(5000);
                    system("cls");
                    break;
                }
            }

            if(teste){
                continue;
            }else
                break;
        }

        system("cls");

        while(1){
            system("cls");
            cout << "Data que ingressou na empresa:\n";
            cout << "Dia: ";
            getline(cin, data.dia);
            if(data.dia.size()==0){
                system("cls");
                cout << "Dia invalido" << endl;
                Sleep(5000);
                continue;
            }
            cout << "Mes: ";
            getline(cin, data.mes);
            if(data.mes.size()==0){
                system("cls");
                cout << "Mes invalido" << endl;
                Sleep(5000);
                continue;
            }
            cout << "Ano: ";
            getline(cin, data.ano);
            if(data.ano.size()==0){
                system("cls");
                cout << "Ano invalido" << endl;
                Sleep(5000);
                continue;
            }
            if(data.dia.length() == 1){
                dia = "0" + data.dia;
                if(isNumber(dia)){

                }else{
                    system("cls");
                    cout << "Dia invalido" << endl;
                    Sleep(5000);
                    continue;
                }
            }

            else if(data.dia.length() == 2){
                dia = data.dia;
                if(isNumber(dia)){

                }else{
                    system("cls");
                    cout << "Dia invalido" << endl;
                    Sleep(5000);
                    continue;
                }
            }

            else if(data.dia.length() > 2){
                system("cls");
                cout << "Dia invalido" << endl;
                Sleep(5000);
                continue;
            }

            if(data.mes.length() == 1){
                mes = "0" + data.mes;
                if(isNumber(mes)){
                    
                }else{
                    system("cls");
                    cout << "Mes invalido" << endl;
                    Sleep(5000);
                    continue;
                }
            }
            else if(data.mes.length() == 2){
                mes = data.mes;
                if(isNumber(mes)){
                    
                }else{
                    system("cls");
                    cout << "Mes invalido" << endl;
                    Sleep(5000);
                    continue;
                }
            }
            else if(data.mes.length() > 2){
                system("cls");
                cout << "Mes invalido" << endl;
                Sleep(5000);
                continue;
            }
            
            if(data.ano.length() == 2){
                ano = "19" + data.ano;
                if(isNumber(ano)){
                    
                }else{
                    system("cls");
                    cout << "Ano invalido" << endl;
                    Sleep(5000);
                    continue;
                }
            }
            else if(data.ano.length() == 4){
                ano = data.ano;
                if(isNumber(ano)){
                    
                }else{
                    system("cls");
                    cout << "Ano invalido" << endl;
                    Sleep(5000);
                    continue;
                }
            }
            else{
                ano = "0";
            }
            

            if(stoi(mes) < 1 || stoi(mes) > 12){
                system("cls");
                cout << "Data invalida\n" << endl;
                Sleep(5000);
                continue;
            }
            
            if(stoi(ano) < 1000 || stoi(ano) > 2022){
                system("cls");
                cout << "Data invalida\n" << endl;
                Sleep(5000);
                continue;
            }

            if(stoi(mes)){
                system("cls");
                if(stoi(mes) == 2){
                    if(stoi(data.dia) <= 28 && stoi(data.dia) >= 1){
                        break;
                    }else{
                        system("cls");
                        cout << "Dia do mes invalido" << endl;
                        Sleep(5000);
                        continue;
                    }
                }
                if(stoi(mes) == 1 || stoi(mes) == 3|| stoi(mes) == 5 || stoi(mes) == 7 || stoi(mes) == 8 || stoi(mes) == 10 || stoi(mes) == 12){
                    if(stoi(dia) <= 31 && stoi(dia) >= 1){
                        break;
                    }else{
                        system("cls");
                        cout << "Dia do mes invalido\n" << endl;
                        Sleep(5000);
                        continue;
                    }
                }
                else{
                    if(stoi(dia) <= 30 && stoi(dia) >= 1){
                        break;
                    }else{
                        system("cls");
                        cout << "Dia do mes invalido\n" << endl;
                        Sleep(5000);
                        continue;
                    }
                }
            }
        }
        system("cls");

        c = 1;
        while(1){
            system("cls");
            cout << "Escolha a designacao:\n";
            cout << "(1) Operador\n";
            cout << "(2) Gerente\n";
            cout << "(3) Diretor\n";
            cout << "(4) Presidente\n\n";

            getline(cin, desig);
            system("cls");
            if(desig == "1"){
                designacao = "Operador";
                c = 0;
            }else if(desig == "2"){
                designacao = "Gerente";
                c = 0;
            }else if(desig == "3"){
                designacao = "Diretor";
                c = 0;
            }else if(desig == "4"){
                designacao = "Presidente";
                c = 0;
            }else{
                cout << "Inválido! Tente novamente\n";
                Sleep(5000);
            }

            if(c == 0){
                break;
            }
        }

        system("cls");

        if(designacao == "Gerente"){
            cout << "Informe a area de supervisão: ";
            getline(cin, areaS[0]);
            system("cls");
        }
        else if(designacao == "Diretor"){
            cout << "Informe a area de supervisão: ";
            getline(cin, areaS[1]);
            system("cls");
            cout << "Informe a area de formacao: ";
            getline(cin, areaF[0]);
            system("cls");
        }
        else if(designacao == "Presidente"){
            cout << "Informe a area de formacao: ";
            getline(cin, areaF[1]);
            system("cls");
            cout << "Informe a formacao academica maxima: ";
            getline(cin, formacao);
            system("cls");
        }

        while(1){
            teste = false;
            cout << "Salario: ";
            getline(cin, salario);

            for(int i = 0; i < salario.size(); i++){
                if(salario[i] != ','){
                    if(isdigit(salario[i]) == 0 && salario[i] != '.'){
                        teste = true;
                    }
                }else{
                    salario[i] = '.';
                }
            }

            if(teste){
                system("cls");
                cout << "Salario invalido" << endl;
                Sleep(5000);
                continue; 
            }else
                break;
        }

        system("cls");

        fotografarUsuario(codigo);

        line = codigo + "," + transformaStringMin(nome) + "," + transformaStringMin(endereco) + "," + telefone + "," + dia + "/" + mes +"/" + ano + "," + transformaStringMin(designacao) + "," + salario ;
        if(designacao == "Gerente"){
            linha[li] = line + ",'" + areaS[0] + "'," + Nan + "," + Nan + "\n";
        }
        else if(designacao == "Diretor"){
            linha[li] = line + ",'" + areaS[1] + "','" + areaF[0] + "'," + Nan + "\n";
        }
        else if(designacao == "Presidente"){
            linha[li] = line + "," + Nan + ",'" + areaF[1] + "'," + formacao + "\n";
        }
        else{
            linha[li] = line + "," + Nan + "," + Nan + "," + Nan + "\n";
        }

        system("cls");

        cout << "\n-------------------------------------------------------------\n\n";

        cout << "Cadastro realizado!" << endl;

        cout << "\n-------------------------------------------------------------\n";

        cout << "Deseja adicionar outro funcionario? [s/n]" << endl;
        cin >> yn;
        getchar();

        system("cls");

        li++;
    }

    arquivo.open("./csv/Empresa.csv", ios::out | ios::app);
    for(li = 0; li < TAM; li++){
        arquivo << linha[li];
    }
    arquivo.close();

}

void Funcionario::buscarFuncionario(){
    int escolha;

    while(1){
        cout << "\n------------------------- BUSCAR ---------------------------\n\n";
        cout << "[1] Buscar por nome\n";
        cout << "[2] Buscar por data de ingresso (intervalo de tempo)\n";
        cout << "[3] Buscar por endereco\n"; 
        cout << "\n------------------------------------------------------------\n\n";
        
        cin >> escolha;
        getchar();
    
        system("cls");

        if (escolha <= 0 || escolha > 3){
            cout << "Escolha invalida! Tente novamente" << endl;
            continue;

        } else {
            switch (escolha){
                case 1:
                    buscaPorNome();
                    break;
        
                case 2:
                    buscaPorData();
                    break;
        
                case 3:
                    buscaPorEndereco();
                    break;
            }

            break;
        }
    }
}

void Funcionario::modificarFuncionario(){
    int c = 0, cont = 0;
    int escolha = 0, i = 0; 
    string auxCodigo;
    string cod, aux;

    colunas();
    
    while(1){
        c = 1;
        while(1){
            system("cls");
            cout << "Informe o codigo do funcionario: ";
            getline(cin, auxCodigo);
            
            system("cls");

            if(auxCodigo.length() == 3){
                cod = auxCodigo;
                break;
            }
            else if(auxCodigo.length() == 2){
                cod = "0" + auxCodigo;
                break;
            }
            else if(auxCodigo.length() == 1){
                cod = "00" + auxCodigo;
                break;
            }
            else{
                system("cls");
                cout << "Codigo maior do que o esperado" << endl;
                Sleep(5000);
                continue;
            }
        }
        
        for(int i = 0; i < TAM; i++){
            //verificando se o codigo digitado existe ou não
            if(codigo[i].find(cod) != string::npos){
                c = 1;
                break;
            }
            else{
                c = 0;
                continue;
            }
        }
        
        if(c == 1){
            system("cls");
            break;
        }
        else{
            system("cls");
            cout << "Codigo nao existe, tente novamente" << endl;
            Sleep(5000);
            continue;
        }
    }

    while(1){
        system("cls");
        cout << "\nO que deseja modificar?" << endl;
        cout << "[1] Codigo\n";
        cout << "[2] Nome\n";
        cout << "[3] Endereco\n"; 
        cout << "[4] Telefone\n";
        cout << "[5] Data\n";
        cout << "[6] Salario\n";
        cout << "[7] Designacao\n";
        cout << "[0] Sair\n\n";

        cin >> escolha;
        getchar();
   
        system("cls");

        if (escolha < 0 || escolha > 7){
            cout << "Escolha invalida! Tente novamente" << endl;
            Sleep(5000);
            system("cls");
            continue;

        } else {
            switch (escolha){
                case 1:
                    modificaCodigo(cod);
                    system("cls");
                    cout << "\n-------------------------------------------------------------\n";

                    cout << "\nCodigo alterado!" << endl;

                    cout << "\n-------------------------------------------------------------\n";
                    Sleep(5000);
                    system("cls");
                    break;
        
                case 2:
                    modificaNome(cod);
                    cout << "\n-------------------------------------------------------------\n";

                    cout << "\nNome alterado!" << endl;

                    cout << "\n-------------------------------------------------------------\n";
                    Sleep(5000);
                    system("cls");  
                    break;      
                case 3:
                    modificaEndereco(cod);
                    cout << "\n-------------------------------------------------------------\n";

                    cout << "\nEndereco alterado!" << endl;

                    cout << "\n-------------------------------------------------------------\n";
                    Sleep(5000);
                    system("cls");
                    break;
                case 4:
                    modificaTelefone(cod);
                    cout << "\n-------------------------------------------------------------\n";

                    cout << "\nTelefone alterado!" << endl;

                    cout << "\n-------------------------------------------------------------\n";
                    Sleep(5000);
                    system("cls");
                    break;

                case 5:
                    modificaData(cod);
                    cout << "\n-------------------------------------------------------------\n";

                    cout << "\nData de ingresso alterada!" << endl;

                    cout << "\n-------------------------------------------------------------\n";
                    Sleep(5000);
                    system("cls");
                    break;
        
                case 6:
                    modificaSalario(cod);
                    cout << "\n-------------------------------------------------------------\n";

                    cout << "\nSalario alterado!" << endl;

                    cout << "\n-------------------------------------------------------------\n";
                    Sleep(5000);
                    system("cls");
                    break;
        
                case 7:
                    modificaDesignacao(cod);
                    cout << "\n-------------------------------------------------------------\n";

                    cout << "\nDesignacao alterada!" << endl;

                    cout << "\n-------------------------------------------------------------\n";
                    Sleep(5000);
                    system("cls");
                    break;
                case 0:
                    break;
            }

            break;
        }
    }
}

void Funcionario::excluirRegistro(){
    string cod, linhaAux,linha[TAM], command;
    int cont = 0, teste = 1;
    char yn;
    fstream file;

    lerArquivo(); // Lê o arquivo com todas as informações dos usuário e passa para as variáveis corrrespondentes
    colunas();

    system("cls");

    cout << "Digite o Codigo do Registro: ";
    
    cin >> cod;
    getchar();

    system("cls");
    for(int i = 0; i < tamArq; i++){
        if(codigo[i] == cod){ // procura o código digitado entre os códigos do arquivo
            if(desig[i] == "Presidente" || desig[i] == "Diretor"){ // verifica se esse código pertence a um Presidente ou Diretor
                system("cls");
                cout << "Registro nao pode ser excluido." << endl;
                Sleep(5000);
                break;
            }else{
                system("cls");
                while(1){
                    cout << "Deseja excluir o registro do Arquivo? [s/n]\n";
                    cin >> yn;
                    getchar();

                    if(yn == 'n' || yn == 'N'){
                        system("cls");
                        cout << "\n-------------------------------------------------------------\n\n";

                        cout << "Registro nao exluido." << endl;

                        cout << "\n-------------------------------------------------------------\n";
                        Sleep(5000);
                        break;
                    }else if(yn == 's' || yn == 'S'){
                        system("cls");
                        cout << "\n-------------------------------------------------------------\n\n";

                        cout << "O registro foi excluido." << endl;
                        command = "./fotos-funcionarios/" + cod +".jpg";
                        remove(command.c_str());

                        cout << "\n-------------------------------------------------------------\n";
                        Sleep(5000);

                        cont = i+1; // Armazena o index da linha em que o código foi excluído
                        teste = 0;
                        break;
                    }else{
                        system("cls");
                        cout << "Opcao invalida." << endl;
                        Sleep(5000);
                        continue;
                    }
                }
                break;
            }
        }else if(i == tamArq-1){ // se código digitado não for encontrado e a linha estiver vazia encerra o for
            system("cls");
            cout << "Codigo nao encontrado." << endl;
            Sleep(5);
        }
    }

    int i = 0;
    for(int j = 0; j < tamArq; j++){
        if((j == cont) && (teste == 0)){ //o index corresponde ao contador e variável teste está zerada comfirmando que essa linha não dever 
                                         // ser salva no arquivo logo deve ser excluída.
        }else{
            linhaAux = linhas[j];
            linha[i] = linhaAux;
            i++;
        }
    }


    file.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i<tamArq; i++){
        if(linha[i] == ""){
            break;
        }
        file << linha[i] << endl;
    }
    file.close();


}

bool Funcionario::calculaFolhaSalarial(){
    typedef struct{
        string mes;
        string ano;
    } Data;

    Data data;
    ifstream fileTeste;
    fstream file;
    string mes, ano, busca;
    salarioEmpresa=0;
    int mesI;
    bool teste;

    limpaArraySalario();
    lerArquivo();
    colunas();

    while(1){
        system("cls");
        cout << "Data em que a folha salaria deve ser calculada:\n";
        cout << "Mes: ";
        getline(cin, data.mes);
        if(data.mes.size()==0){
            system("cls");
            cout << "Mes invalido" << endl;
            Sleep(5000);
            continue;
        }
        cout << "Ano: ";
        getline(cin, data.ano);
        if(data.ano.size()==0){
            system("cls");
            cout << "Ano invalido" << endl;
            Sleep(5000);
            continue;
        }

        if(data.mes.length() == 1){
                mes = "0" + data.mes;
                if(!isNumber(mes)){
                    system("cls");
                    cout << "Mes invalido" << endl;
                    Sleep(5000);
                    continue;
                }
        }
        else if(data.mes.length() == 2){
            mes = data.mes;
            if(!isNumber(mes)){
                system("cls");
                cout << "Mes invalido" << endl;
                Sleep(5000);
                continue;
            }
        }
        else if(data.mes.length() > 2){
            system("cls");
            cout << "Mes invalido" << endl;
            Sleep(5000);
            continue;
        }
        
        if(data.ano.length() == 2){
            ano = "19" + data.ano;
            if(!isNumber(ano)){
                system("cls");
                cout << "Ano invalido" << endl;
                Sleep(5000);
                continue;
            }
        }
        else if(data.ano.length() == 4){
            ano = data.ano;
            if(!isNumber(ano)){
                system("cls");
                cout << "Ano invalido" << endl;
                Sleep(5000);
                continue;
            }
        }
        else{
            system("cls");
            cout << "Ano invalido" << endl;
            Sleep(5000);
            continue;
        }
            

        if(stoi(mes) < 1 || stoi(mes) > 12){
            system("cls");
            cout << "Data invalida\n" << endl;
            Sleep(5000);
            continue;
        }
            
        if(stoi(ano) < 1000 || stoi(ano) > 2022){
            system("cls");
            cout << "Data invalida\n" << endl;
            Sleep(5000);
            continue;
        }else{
            break;
        }
    }

    busca = "./csv/FolhaSalarial-" + mes + ano + ".csv";

    // verifica se o arquivo já foi criado
    fileTeste.open(busca);
    if (fileTeste.is_open()){
        fileTeste.close();
        return false;
    }else{
        fileTeste.close();

        // transforma string em double
        for(int i = 0; i < tamArq-1; i++){
            if(linhas[i] != ""){
                if(getSalario(i) != ""){
                    salarioBruto[i] = stod(getSalario(i));
                }
            }
        }

        //variavel mes da folha salarial
        mesI = stod(mes);

        // Calcula salario bruto daquele mes
        for(int i = 0; i < tamArq-1; i++){
            if(linhas[i] != ""){
                if(getSalario(i) != ""){
                    if(mesI == 2){
                        salarioBruto[i] = ((salarioBruto[i]/28)*geraDiasTrabalhados(mesI)) +  ((salarioBruto[i]/28)/8)*2*geraHorasExtras(mesI);
                    }else if(mesI == 1 || mesI == 3 || mesI == 5 || mesI == 7 || mesI == 8 || mesI == 10 || mesI == 12){
                        salarioBruto[i] = ((salarioBruto[i]/31)*geraDiasTrabalhados(mesI)) +  ((salarioBruto[i]/31)/8)*2*geraHorasExtras(mesI);
                    }else{
                        salarioBruto[i] = ((salarioBruto[i]/30)*geraDiasTrabalhados(mesI)) +  ((salarioBruto[i]/30)/8)*2*geraHorasExtras(mesI);       
                    }
                }else
                    break;
            }
        }

        //desconto inss e irrf
        calculaDescontos(salarioBruto);

        file.open(busca, fstream::out);
        file << "Funcinario," << "Designacao," <<"SalarioBruto," << "INSS," << "IRRF," << "SalarioLiquido" << endl; 
        for(int i = 0; i<tamArq-1; i++){
            if(getNome(i) != ""){
                if(salarioBruto[i] != 0){
                    file << getNome(i) << "," << getDesig(i) << "," << fixed << setprecision(2) << "R$" << salarioBruto[i] << "," << fixed << setprecision(2) 
                    << "R$" <<inss[i] << "," << fixed << setprecision(2) << "R$" << irrf[i] << "," << fixed << setprecision(2) << "R$" 
                    << salarioLiquido[i] << endl;
                    salarioEmpresa+=salarioLiquido[i];
                }else
                    break;
            }else
                break;
        }
        file << "SalarioEmpresa: " << fixed << setprecision(2) << salarioEmpresa << endl;
        file.close();
        return true;

    }
}

void Funcionario::exibeFolhaSalarialFuncionario(){
    string nomeF, codigoF, opcao;
    int i = 0, teste, valor, c;
    double salarioD[TAM];

    limpaArraySalario();
    lerArquivo();
    colunas();

    while(1){
        system("cls");
        cout << "Deseja fazer a busca por nome (1) ou codigo (2)?" << endl;
        getline(cin, opcao);
        system("cls");
        if(opcao == "1"){
            teste = 0;
            cout << "Digite o nome: ";
            getchar();
            getline(cin, nomeF);
            system("cls");
            nomeF = transformaStringMin(nomeF);
            for(i=0;i<TAM;i++){
                if(nomeF == nome[i]){
                    valor = i;
                    teste = 1;
                    break;
            }
        }
        if(teste){
            break;
        }else{
            while(1){
                c=0;
                cout << "Nome Invalido" << endl;
                Sleep(5000);
                system("cls");
                cout << "Nenhum funcionario encontrado. Gostaria de tentar novamente? [s/n]" << endl;
                getline(cin, opcao);

                if (opcao == "s" || opcao == "S"){    
                    system("cls");
                    c = 1;
                    break;
                }
                else if (opcao == "n" || opcao == "N"){
                    system("cls");
                    c = 2;
                    break;
                }else{
                system("cls"); 
                    cout << "Opcao invalida! Tente novamente" << endl << endl;
                    Sleep(5000);
                    continue;
                }
            }

            if (c == 1){
                continue; //Vai para o inicio do while
            }
            else if (c == 2){                
                break;    
            }
        }
        
        }else if(opcao == "2"){
            teste = 0;
            cout << "Digite o codigo: ";
            getchar();
            getline(cin, codigoF);
            system("cls");
            for(i=0;i<TAM;i++){
                if(codigoF == codigo[i]){
                    valor = i;
                    teste = 1;
                    break;
                }
            }
            if(teste)
                break;
            }else{
                while(1){
                    c=0;
                    cout << "Nome Invalido" << endl;
                    Sleep(5000);
                    system("cls");
                    cout << "Nenhum funcionario encontrado. Gostaria de tentar novamente? [s/n]" << endl;
                    getline(cin, opcao);

                    if (opcao == "s" || opcao == "S"){    
                        system("cls");
                        c = 1;
                        break;
                    }
                    else if (opcao == "n" || opcao == "N"){
                        system("cls");
                        c = 2;
                        break;
                    }else{
                    system("cls"); 
                        cout << "Opcao invalida! Tente novamente" << endl << endl;
                        Sleep(5000);
                    continue;
                    }
                }

                if (c == 1){
                    continue; //Vai para o inicio do while
                }
                else if (c == 2){                
                    break;    
                }
            }  
        }
    
    for(int i = 0; i < tamArq - 1; i++){
        try{
            salarioD[i] = stod(salario[i]);    
        }catch(std :: invalid_argument  const & ex ){
        }
    }

    calculaDescontos(salarioD);
    if(teste){
        system("cls");
        cout << "\n-------------------------------------------------------------\n\n";
        cout << "Funcinario,Designacao,SalarioBruto,INSS,IRRF,SalarioLiquido" << endl;
        cout << nome[valor] << ",R$" << salario[valor] << ",R$" << inss[valor] << ",R$" << irrf[valor] << ",R$" << salarioLiquido[valor] << endl;
        cout << "\n-------------------------------------------------------------\n";

        cout << "\n\n";
        system("pause");
    }
}

void Funcionario::exibeFolhaSalarialEmpresa(){
    typedef struct{
        string mes;
        string ano;
    } Data;

    Data data;
    int i, k, l, teste=0;
    string opcao, buscaMes, arquivo[TAM], ano, mes, busca[12], linha, temp, aux; 
    string meses[12]={"janeiro", "fevereiro", "março", "abril", "maio","junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    ifstream fileTeste;
    salarioEmpresa = 0;
    double empresaMes[12];

    limpaArraySalario();
    lerArquivo();
    colunas();
    system("cls");

    while(1){
        system("cls");
        cout << "Exibir folha salarial mensal (1) ou anual (2)?" << endl;
        getline(cin, opcao);
        system("cls");
        if(opcao == "1"){
            break;
        }else if(opcao == "2"){
            break;
        }else{
            cout << "Opcao invalida" << endl;
            opcao = "0";
            Sleep(5000);
            continue;
        }
    }
    

    if(opcao == "1"){
        while(1){
        system("cls");
        cout << "Data em que a folha salaria deve ser exibida:\n";
        cout << "Mes: ";
        getline(cin, data.mes);
        if(data.mes.size()==0){
            system("cls");
            cout << "Mes invalido" << endl;
            Sleep(5000);
            continue;
        }
        cout << "Ano: ";
        getline(cin, data.ano);
        if(data.ano.size()==0){
            system("cls");
            cout << "Ano invalido" << endl;
            Sleep(5000);
            continue;
        }

        if(data.mes.length() == 1){
                mes = "0" + data.mes;
                if(!isNumber(mes)){
                    system("cls");
                    cout << "Mes invalido" << endl;
                    Sleep(5000);
                    continue;
                }
        }
        else if(data.mes.length() == 2){
            mes = data.mes;
            if(!isNumber(mes)){
                system("cls");
                cout << "Mes invalido" << endl;
                Sleep(5000);
                continue;
            }
        }
        else if(data.mes.length() > 2){
            system("cls");
            cout << "Mes invalido" << endl;
            Sleep(5000);
            continue;
        }
        
        if(data.ano.length() == 2){
            ano = "19" + data.ano;
            if(!isNumber(ano)){
                system("cls");
                cout << "Ano invalido" << endl;
                Sleep(5000);
                continue;
            }
        }
        else if(data.ano.length() == 4){
            ano = data.ano;
            if(!isNumber(ano)){
                system("cls");
                cout << "Ano invalido" << endl;
                Sleep(5000);
                continue;
            }
        }
        else{
            system("cls");
            cout << "Ano invalido" << endl;
            Sleep(5000);
            continue;
        }
            

        if(stoi(mes) < 1 || stoi(mes) > 12){
            system("cls");
            cout << "Data invalida\n" << endl;
            Sleep(5000);
            continue;
        }
            
        if(stoi(ano) < 1000 || stoi(ano) > 2022){
            system("cls");
            cout << "Data invalida\n" << endl;
            Sleep(5000);
            continue;
        }else{
            break;
        }
    }

    buscaMes = "./csv/FolhaSalarial-" + mes + ano + ".csv";

        fileTeste.open(buscaMes);
        if (fileTeste.is_open()){
            system("cls");
            cout<<"Folha Salarial dessa data ja foi calculada"<<endl;
            i=0;
            Sleep(5000);
            system("cls");
            cout << "\n-------------------------------------------------------------\n\n";
            while(getline(fileTeste, arquivo[i])){
                cout << arquivo[i] << endl;
            }
            cout << "\n-------------------------------------------------------------\n";
            cout << "\n\n";
            system("pause");
            system("cls");

            fileTeste.close();
        }else{
            fileTeste.close();
            cout<<"Folha Salarial dessa data ainda não foi calculada"<<endl;
            Sleep(5000);
            system("cls");
        }
    }else if(opcao == "2"){
       while(1){
        system("cls");
        cout << "Data em que a folha salaria deve ser exibida:\n";
        cout << "Ano: ";
        getline(cin, data.ano);
        if(data.ano.size()==0){
            system("cls");
            cout << "Ano invalido" << endl;
            Sleep(5000);
            continue;
        }
        if(data.ano.length() == 2){
            ano = "19" + data.ano;
            if(!isNumber(ano)){
                system("cls");
                cout << "Ano invalido" << endl;
                Sleep(5000);
                continue;
            }
        }
        else if(data.ano.length() == 4){
            ano = data.ano;
            if(!isNumber(ano)){
                system("cls");
                cout << "Ano invalido" << endl;
                Sleep(5000);
                continue;
            }
        }
        else{
            system("cls");
            cout << "Ano invalido" << endl;
            Sleep(5000);
            continue;
        }
        if(stoi(ano) < 1000 || stoi(ano) > 2022){
            system("cls");
            cout << "Data invalida\n" << endl;
            Sleep(5000);
            continue;
        }else{
            break;
        }
    }
        for(int j = 1; j<13; j++){
            if(j < 10){
                busca[j-1] = "./csv/FolhaSalarial-0" + to_string(j) + ano + ".csv";
            }else if(j >= 10){
                busca[j-1] = "./csv/FolhaSalarial-" + to_string(j) + ano + ".csv";
            }

            fileTeste.open(busca[j-1]);
            if(fileTeste.is_open()){
                if(j==1){
                    cout << "\n-------------------------------------------------------------\n\n";
                }
                while(getline(fileTeste, linha)){
                    temp = "";
                    for(k = 0; k < linha.size(); k++){
                        if(linha[k] != ':'){
                            temp = temp + linha[k];
                        }else{
                            k++;
                            break;
                        }
                    }

                    if(temp == "SalarioEmpresa"){
                        aux = temp;
                    }else{
                        aux = "";
                    }
                        
                    temp = "";
                    for(++k; k < linha.size(); k++){
                        temp = temp + linha[k];
                    }

                    if(aux == "SalarioEmpresa"){
                        try{
                            empresaMes[j-1] = stod(temp);
                            salarioEmpresa += empresaMes[j-1];
                        }catch(std :: invalid_argument  const & ex ){
                        }
                        
                        if(j==1){
                            system("cls");
                            cout << "\n------------------- " << "Folha Salarial " << ano << " ---------------------\n"<< endl;
                        }
                        
                        cout << "Mes de " << meses[j-1] << ": R$ " << empresaMes[j-1] << endl;
                        
                        if(j==12){
                            cout << "\n";
                            cout <<  "Gasto Salarial Anual Da Empresa: R$ " << salarioEmpresa<< endl;
                        }

                    }
                }
                if(j==12){
                    cout << "\n-------------------------------------------------------------\n";
                    cout << "\n\n";
                    system("pause");
                }
                    
                fileTeste.close();
            }else{
                fileTeste.close();
                system("cls");
                cout<<"Folha Salarial do mes " << meses[j-1] << " nao foi calculada" <<endl;
                Sleep(5000);
                system("cls");
            }
        }
    }
}



