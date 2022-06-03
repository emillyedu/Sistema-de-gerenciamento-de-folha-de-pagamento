#include "Funcionario.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;

Funcionario::Funcionario(){
}

string Funcionario::getCodigo(int i){
    return codigo[i];
}
string Funcionario::getDesig(int i){
    return desig[i];
}
string Funcionario::getSalario(int i){
    return salario[i];
}
string Funcionario::getNome(int i){
    return nome[i];
}
string Funcionario::getEnd(int i){
    return end[i];
}
string Funcionario::getTelefone(int i){
    return telefone[i];
}
string Funcionario::getData(int i){
    return data[i];
}
string Funcionario::getSup(int i){
    return sup[i];
}
string Funcionario::getAcad(int i){
    return acad[i];
}
string Funcionario::getFormacao(int i){
    return formacao[i];
}

string Funcionario::getLinhas(int i){
    return linhas[i];
}


void Funcionario::criarArquivo(){
    arquivo.open("./csv/Empresa.csv", ios::in);

    if(!arquivo.is_open()){
        arquivo.open("./csv/Empresa.csv", ios::out);
    }

    arquivo.close();
}

void Funcionario::lerArquivo(){
    arquivo.open("./csv/Empresa.csv", ios::in);

    int i = 0;
    if(arquivo.is_open()){
        while(getline(arquivo, linhas[i])){
            i++;
        }
        arquivo.close();
    }
    else{
        cout << "nao foi possivel ler o arquivo" << endl;
    }
}

void Funcionario::exibirArquivo(){
    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            cout << linhas[i] << endl;
        }
    }
}

void Funcionario::exibeRegistroFunc(){
    //Ao inserir o número de código do funcionário, os usuários podem acessar todas as informações 
    //fornecidas relacionadas a um determinado funcionário por meio desta função.
    string cod, codigo;
    int flag = 0, c;

    lerArquivo();

    while(1){
        c = 1;
        while(1){
            cout << "Insira o código do funcionário desejado: ";
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
                cout << "codigo maior do que o esperado" << endl;
                continue;
            }
        }
        for(int i = 1; i < 100; i++){
            if(linhas[i] != ""){
                colunas();
            }
            if(getCodigo(i-1) == codigo){
                cout << "codigo invalido, tente novamente" << endl;
                c = 0;
                break;
            }
        }
        if(c == 1){
            break;
        }
    }

    for(int i = 0; i < 100; i++){

        if(linhas[i] != ""){
            colunas();
        }
        if(getCodigo(i) == cod){
            cout << endl;
            cout << "Codigo: " << getCodigo(i) << endl;
            cout << "Nome: " << getNome(i) << endl;
            cout << "Endereco: " << getEnd(i) << endl;
            cout << "Telefone: " << getTelefone(i) << endl;
            cout << "Data de ingresso: " << getData(i) << endl;
            cout << "Designacao: " << getDesig(i) << endl;
            cout << "Salario: " << getSalario(i) << endl;
            if(getSup(i) != Nan){
                cout << "Area de supervisao: " << getSup(i) << endl;
            }
            if(getAcad(i) != Nan){
                cout << "Area academica: " << getAcad(i) << endl;
            }
            if(getFormacao(i) != Nan){
                cout << "Formacao maxima: " << getFormacao(i) << endl << endl;     
            }
            flag = 1;
            break;
        }
    }
    
    if(flag == 0){
        cout << "Funcionario nao encontrado" << endl;
    }
}

void Funcionario::exibeListaFunc(){
    //Este recurso exibe o registro de todos os funcionários 
    lerArquivo();

    cout << "Codigo,Nome,Designacao" << endl;
    for(int i = 0; i < 100; i++){
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
        cout << "(4) Presidente\n";

        cin >> desig;
        getchar();

        switch (desig){
        case 1:
            designacao = "Operador";
            c = 0;
            break;
        case 2:
            designacao = "Gerente";
            c = 0;
            break;
        case 3:
            designacao = "Diretor";
            c = 0;
            break;
        case 4:
            designacao = "Presidente";
            c = 0;
            break;
        default:
            cout << "Inválido! Tente novamente\n";
            break;
        }

        if(c == 0){
            break;
        }
    }
    
    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            colunas();
        }
        if(getDesig(i) == designacao){
            flag = 1;
        }
    }

    if(flag == 0){
        cout << "Não foi encontrado nenhum funcionario" << endl;
        return;
    }

    cout << "Codigo,Nome,Designacao" << endl;
    for(int i = 0; i < 100; i++){
        if(getDesig(i) == designacao){
            cout << getCodigo(i) << "," << getNome(i) << "," << getDesig(i) << endl;
        }
    }
}

void Funcionario::separadorColuna(string colPresent[], int del[]){
    for(int i = 1, j = 0; i < 100; i++, j++){
        if(linhas[i] != ""){
            colPresent[j] = linhas[i];
            colPresent[j].erase(0, del[j]);
            colPresent[j].erase(colPresent[j].find(','));
        }
        else{
            break;
        }
        //cout << colPresent[j] << endl;
    }
}

void Funcionario::colunas(){
    int del[100] = {0};
    int j, i;

    criarArquivo();
    lerArquivo();

    for(i = 1, j = 0; i < 100; i++, j++){
        if(linhas[i] != ""){
            codigo[j] = linhas[i];
            codigo[j].erase(3, codigo[j].length());
        }
        else{
            break;
        }
        //cout << codigo[j] << endl;
    }

    for(j = 0; j < 100; j++){
        del[j] += codigo[j].size() + 1;
    }
    separadorColuna(nome, del);
    
    for(j = 0; j < 100; j++){
        del[j] += nome[j].size() + 1;
    }
    separadorColuna(end, del);

    for(j = 0; j < 100; j++){
        del[j] += end[j].size() + 1;
    }
    separadorColuna(telefone, del);

    for(j = 0; j < 100; j++){
        del[j] += telefone[j].size() + 1;
    }
    separadorColuna(data, del);
    for(j = 0; j < 100; j++){
        del[j] += data[j].size() + 1;
    }
    separadorColuna(desig, del);
    for(j = 0; j < 100; j++){
        del[j] += desig[j].size() + 1;
    }
    separadorColuna(salario, del);
    for(j = 0; j < 100; j++){
        del[j] += salario[j].size() + 1;
    }
    separadorColuna(sup, del);
    for(j = 0; j < 100; j++){
        del[j] += sup[j].size() + 1;
    }
    separadorColuna(acad, del);
    
    for(i = 1, j = 0; i < 100; i++, j++){
        del[j] += acad[j].length() +1;
        if(linhas[i] != ""){
            formacao[j] = linhas[i];
            formacao[j].erase(0, del[j]);
        }
        else{
            break;
        }
        //cout << formacao[j] << endl; 
    }
}

string Funcionario::forEndereco(string api[], int line, int tam){
    api[line].erase(0, tam);
    int count = 0;
    while(1){
        for(int i = 0; i < 50; i++){
            if(api[line][i] == '"'){
                api[line].erase(i, 2);
                count = 1;
                break;
            }
        }
        if(count = 1){
            break;
        }
    }
    return api[line];
}

string Funcionario::retornaEndereco(string cep){
    int i;
    int count = 0;
    string logradouro;
    string linhasAPI[12];

    fstream arquivoAPI;
    
    string CEP = cep;
    string url = "http://viacep.com.br/ws/" + CEP +"/json/";
    string comando = "wget " + url;

    system(comando.c_str());

    system("cls");

    arquivoAPI.open("index.html", ios::in);

    i = 0;
    while(getline(arquivoAPI, linhasAPI[i])){
        i++;
    }

    arquivoAPI.close();

    if(linhasAPI[2] == "}"){
        system("del index.html");
        cout << "endereco nao encontrado" << endl;
        return "Nan";
    }

    system("del index.html");

    return "Logradouro: " + forEndereco(linhasAPI, 2, 17) + " - " "Bairro: " + forEndereco(linhasAPI, 4, 13) + " - " + "Cidade: " + forEndereco(linhasAPI, 5, 17) + " - " + "UF: " + forEndereco(linhasAPI, 6, 9);

}

void Funcionario::aumentoDeSalarios(){
    Operador operador;
    Gerente gerente;
    Presidente presidente;
    Diretor diretor;
    
    double salarioAum[100];

    criarArquivo();
    lerArquivo();

    int count ;
    for(int i = 1, j = 0; i < 100; i++, j++){
        count = 0;
        if(linhas[i] != ""){
            count = 1;

            colunas();
        
            if(getDesig(j) == "Operador"){
                salarioAum[j] = operador.calculaSalario(stod(getSalario(j)));
            }
            else if(getDesig(j)  == "Presidente"){
                salarioAum[j] = presidente.calculaSalario(stod(getSalario(j)));
            }
            else if(getDesig(j) == "Gerente"){
                salarioAum[j] = gerente.calculaSalario(stod(getSalario(j)));
            }
            else if(getDesig(j) == "Diretor"){
                salarioAum[j] = diretor.calculaSalario(stod(getSalario(j)));
            }
        }

        if(count = 0){
            break;
        }
    }

    arquivo.open("./csv/Empresa.csv", ios::out);
        arquivo << "codigo,nome,end,telefone,data de ingresso,designacao,salario,area de supervisao,area academica,formacao maxima" << endl;
        for(int i = 0; i < 100; i++){
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
        int dia;
        int mes;
        int ano;
    } Data;

    Data data;
    string nome, aux, codigo, cod, telefone, designacao, endereco, cep, numero, areaS[2], areaF[2], formacao;
    string logradouro, bairro, cidade, uf, linha[100], line, dia, mes, ano;
    string yn;
    int i, c, desig, li = 0;
    float salario;
    string tentativa;

    criarArquivo();
    lerArquivo();
    exibirArquivo();

    while(1){
        cout << "deseja adicionar funcionario? [s/n]" << endl;
        cin >> yn;
        getchar();
        if(yn == "S" || yn == "s" ||yn == "N" || yn == "n"){
            break;
        }
        else if(yn.length() > 1){
            continue;
        }
        else{
            continue;
        }
        system("cls");
    }
    system("cls");
    
    while(yn == "S" || yn == "s"){
        while(1){
            c = 1;
            while(1){
                cout << "digite o codigo: ";
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
                    cout << "codigo maior do que o esperado" << endl;
                    continue;
                }
            }
            for(i = 1; i < 100; i++){
                if(linhas[i] != ""){
                    colunas();
                }
                if(getCodigo(i-1) == codigo){
                    cout << "codigo invalido, tente novamente" << endl;
                    c = 0;
                    break;
                }
            }
            if(c == 1){
                break;
            }
        }

        cout << "digite o nome: ";
        getline(cin, nome);

        system("cls");

        while(1){
            cout << "poderia informar seu CEP? [s/n]: ";
            cin >> yn;
            getchar();
            if(yn == "S" || yn == "s" ||yn == "N" || yn == "n"){
                break;
            }
            else if(yn.length() > 1){
                continue;
            }
            else{
                continue;
            } 
            system("cls");
        }
        system("cls");

        while(1){
            if(yn == "S" || yn == "s"){
                cout << "digite seu CEP: ";
                getline(cin, cep);

                if(cep.length() > 8 || cep.length() < 8){
                    cout << "CEP invalido" << endl;
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
        
        if(endereco == Nan || yn == "N" || yn == "n"){
            endereco.clear();
            cep.clear();
            cout << "informe o logradouro: ";
            getline(cin, logradouro);
            cout << "informe o bairro: ";
            getline(cin, bairro);
            cout << "informe a cidade: ";
            getline(cin, cidade);
            cout << "informe a Uf: ";
            getline(cin, uf);

            endereco = "Logradouro: " + logradouro + " - " "Bairro: " + bairro + " - " + "Cidade: " + cidade + " - " + "UF: " + uf;            
        }

        cout << "digite o numero da casa: ";
        getline(cin, numero);

        endereco = endereco + " - numero: " + numero;
        system("cls");

        cout << "telefone - formato: (00) 0000-0000: ";
        getline(cin, telefone);

        system("cls");
        while(1){
            cout << "data que ingressou na empresa:\n";
            cout << "dia: ";
            cin >> data.dia;
            cout << "mes: ";
            cin >> data.mes;
            cout << "ano: ";
            cin >> data.ano;
            
            if(to_string(data.dia).length() == 1){
                dia = "0" + to_string(data.dia);
            }
            else if(to_string(data.dia).length() == 2){
                dia = to_string(data.dia);
            }
            if(to_string(data.mes).length() == 1){
                mes = "0" + to_string(data.mes);
            }
            else if(to_string(data.mes).length() == 2){
                mes = to_string(data.mes);
            }
            if(to_string(data.ano).length() == 2){
                ano = "19" + to_string(data.ano);
            }
            else if(to_string(data.ano).length() == 4){
                ano = to_string(data.ano);
            }
            else{
                ano = "0";
            }

            if(stoi(mes) < 1 || stoi(mes) > 12){
                system("cls");
                cout << "data invalida" << endl;
                continue;
            }
            
            if(stoi(ano) < 1000 || stoi(ano) > 2022){
                system("cls");
                cout << "data invalida" << endl;
                continue;
            }

            if(stoi(mes)){
                if(stoi(mes) == 2){
                    if(data.dia <= 28 && data.dia > 1){
                        break;
                    }else{
                        system("cls");
                        cout << "dia do mes invalido" << endl;
                        continue;
                    }
                }
                if(stoi(mes) == 1 || stoi(mes) == 3|| stoi(mes) == 5 || stoi(mes) == 7 || stoi(mes) == 8 || stoi(mes) == 10 || stoi(mes) == 12){
                    if(stoi(dia) <= 31 && stoi(dia) > 1){
                        break;
                    }else{
                        system("cls");
                        cout << "dia do mes invalido" << endl;
                        continue;
                    }
                }
                else{
                    if(stoi(dia) <= 30 && stoi(dia) > 1){
                        break;
                    }else{
                        system("cls");
                        cout << "dia do mes invalido" << endl;
                        continue;
                    }
                }
            }
        }
        system("cls");

        c = 1;
        while(1){
            cout << "Escolha a designacao:\n";
            cout << "(1) Operador\n";
            cout << "(2) Gerente\n";
            cout << "(3) Diretor\n";
            cout << "(4) Presidente\n";

            cin >> desig;
            getchar();

            switch (desig){
            case 1:
                designacao = "Operador";
                c = 0;
                break;
            case 2:
                designacao = "Gerente";
                c = 0;
                break;
            case 3:
                designacao = "Diretor";
                c = 0;
                break;
            case 4:
                designacao = "Presidente";
                c = 0;
                break;
            default:
                cout << "Inválido! Tente novamente\n";
                break;
            }

            if(c == 0){
                break;
            }
        }

        system("cls");

        if(designacao == "Gerente"){
            cout << "informe a area de supervisão: ";
            getline(cin, areaS[0]);
            system("cls");
        }
        else if(designacao == "Diretor"){
            cout << "informe a area de supervisão: ";
            getline(cin, areaS[1]);
            system("cls");
            cout << "informe a area de formacao: ";
            getline(cin, areaF[0]);
            system("cls");
        }
        else if(designacao == "Presidente"){
            cout << "informe a area de formacao: ";
            getline(cin, areaF[1]);
            system("cls");
            cout << "informa a formacao academica maxima: ";
            getline(cin, formacao);
            system("cls");
        }

        cout << "salario: ";
        cin >> salario;
        getchar();

        line = codigo + "," + nome + "," + endereco + "," + telefone + "," + dia + "/" + mes +"/" + ano + "," + designacao + "," + to_string(salario).erase(to_string(salario).size()-4, 4) ;
        if(designacao == "Gerente"){
            linha[li] = line + "," + areaS[0] + "," + Nan + "," + Nan + "\n";
        }
        else if(designacao == "Diretor"){
            linha[li] = line + "," + areaS[1] + "," + areaF[0] + "," + Nan + "\n";
        }
        else if(designacao == "Presidente"){
            linha[li] = line + "," + Nan + "," + areaF[1] + "," + formacao + "\n";
        }
        else{
            linha[li] = line + "," + Nan + "," + Nan + "," + Nan + "\n";
        }

        system("cls");

        cout << "Cadastro realizado!" << endl;

        cout << "Deseja adicionar outro funcionario? [s/n]" << endl;
        cin >> yn;
        getchar();

        li++;
    }

    arquivo.open("./csv/Empresa.csv", ios::out | ios::app);
    for(li = 0; li < 100; li++){
        arquivo << linha[li];
    }
    arquivo.close();

}

/* ======================================  Para as modificações =============================================*/

// Para manipular strings, é interessante utilizar "vetorChar.substr(17, vetorChar.size() - 2 - 17);"
void Funcionario::modificaCodigo(string cod){
    int c = 0, cont = 0;
    string mod, aux;
    string modificacao;
    
    colunas();

    cout << "================================= Modificar Codigo ===================================" << endl;
    cout << "\n";

    while(1){
        c = 1;
        while(1){
            cout << "Digite o novo codigo: ";
            getline(cin, mod);
            system("cls");

            if(mod.length() == 3){
                modificacao = mod;
                break;
            }
            else if(mod.length() == 2){
                modificacao = "0" + mod;
                break;
            }
            else if(mod.length() == 1){
                modificacao = "00" + mod;
                break;
            }
            else{
                cout << "Codigo maior do que o esperado" << endl;
                continue;
            }
        }

        for(int i = 1; i < 100; i++){
            if(linhas[i] != ""){
                aux = linhas[i];
                aux.erase(3, aux.length());
            }

            if(aux == modificacao){
                cout << "Codigo invalido, tente novamente" << endl;
                c = 0;
                break;
            }
        }

        if(c == 1){
            break;
        }
    }

    system("cls");

    while(1){
        if (codigo[cont].find(cod) != string::npos){

            cout << linhas[cont] << endl;
            cout << "\tcodigo encontrado\n";

            linhas[cont] = modificacao + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
            + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont];

            cout << linhas[cont] << endl;

            cont = 0; // zerando o contador
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    // Escrevendo no arquivo csv
    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            arquivo << linhas[i] << endl;
        }
    }

    arquivo.close(); 
}        

void Funcionario::modificaNome(string cod){
    int cont = 0;
    string modificacao;

    colunas();
    
    cout << "================================= Modificar Nome ===================================" << endl;
    cout << "\n";

    cout << "Digite o novo nome: ";
    getline(cin, modificacao);

    system("cls");

    while(1){
        if (codigo[cont].find(cod) != string::npos){

            cout << linhas[cont] << endl;
            cout << "\tcodigo encontrado\n";

            linhas[cont] = codigo[cont] + "," + modificacao + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
            + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 
            
            cout << linhas[cont] << endl;

            cont = 0; // zerando o contador
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    // Escrevendo no arquivo csv
    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            arquivo << linhas[i] << endl;
        }
    }

    arquivo.close();       
}        

void Funcionario::modificaEndereco(string cod){
    int cont = 0;
    string yn, cep;
    string modificacao, endereco, logradouro, bairro, cidade, uf, numero;

    colunas();
    
    cout << "================================= Modificar Endereco ===================================" << endl;
    cout << "\n";

    while(1){
        cout << "Poderia informar seu novo CEP? [s/n]: ";
        cin >> yn;
        getchar();

        if(yn == "S" || yn == "s" ||yn == "N" || yn == "n"){
            break;
        }
        else if(yn.length() > 1){
            continue;
        }
        else{
            continue;
        } 
        
        system("cls");
    }
    
    system("cls");

    while(1){
        if(yn == "S" || yn == "s"){
            cout << "Digite o novo CEP: ";
            getline(cin, cep);

            if(cep.length() > 8 || cep.length() < 8){
                cout << "CEP invalido" << endl;
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
        
    if(endereco == "Nan" || yn == "N" || yn == "n"){
        endereco.clear();
        cep.clear();

        cout << "informe o novo logradouro: ";
        getline(cin, logradouro);
        cout << "informe o novo bairro: ";
        getline(cin, bairro);
        cout << "informe a nova cidade: ";
        getline(cin, cidade);
        cout << "informe a nova Uf: ";
        getline(cin, uf);

        endereco = "Logradouro: " + logradouro + " - " "Bairro: " + bairro +
        " - " + "Cidade: " + cidade + " - " + "UF: " + uf;            
    }

    cout << "Digite o novo numero da casa: ";
    getline(cin, numero);

    modificacao = endereco + " - numero: " + numero;
    system("cls");
    
    while(1){
        if (codigo[cont].find(cod) != string::npos){

            cout << linhas[cont] << endl;
            cout << "\tcodigo encontrado\n";

            linhas[cont] = codigo[cont] + "," + nome[cont] + "," + modificacao + "," + telefone[cont] + "," + data[cont]
            + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 
            
            cout << linhas[cont] << endl;

            cont = 0; // zerando o contador
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    // Escrevendo no arquivo csv
    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            arquivo << linhas[i] << endl;
        }
    }

    arquivo.close();  
}        

void Funcionario::modificaTelefone(string cod){
    int cont = 0;
    string modificacao;

    colunas();
    
    cout << "================================= Modificar Telefone ===================================" << endl;
    cout << "\n";

    cout << "Digite o novo telefone - (formato: 0000-0000): ";
    getline(cin, modificacao);

    system("cls");

    while(1){
        if (codigo[cont].find(cod) != string::npos){

            cout << linhas[cont] << endl;
            cout << "\tcodigo encontrado\n";

            linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + modificacao + "," + data[cont]
            + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 
            
            cout << linhas[cont] << endl;

            cont = 0; // zerando o contador
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    // Escrevendo no arquivo csv
    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            arquivo << linhas[i] << endl;
        }
    }

    arquivo.close();   
}

void Funcionario::modificaData(string cod){
    typedef struct{
        int dia;
        int mes;
        int ano;
    } Data;

    Data modificacao; 
    string dia, mes, ano;
    int cont = 0;
    
    colunas();
    
    cout << "================================= Modificar Data de Ingresso ===================================" << endl;
    cout << "\n";

    while(1){
        cout << "Digite a nova data:\n";
        cout << "dia: ";
        cin >> modificacao.dia;
        cout << "mes: ";
        cin >> modificacao.mes;
        cout << "ano: ";
        cin >> modificacao.ano;
            
        if(to_string(modificacao.dia).length() == 1){
            dia = "0" + to_string(modificacao.dia);
        }
        else if(to_string(modificacao.dia).length() == 2){
            dia = to_string(modificacao.dia);
        }
        if(to_string(modificacao.mes).length() == 1){
            mes = "0" + to_string(modificacao.mes);
        }
        else if(to_string(modificacao.mes).length() == 2){
            mes = to_string(modificacao.mes);
        }
        if(to_string(modificacao.ano).length() == 2){
            ano = "19" + to_string(modificacao.ano);
        }
        else if(to_string(modificacao.ano).length() == 4){
            ano = to_string(modificacao.ano);
        }
        else{
            ano = "0";
        }

        if(stoi(mes) < 1 || stoi(mes) > 12){
            system("cls");
            cout << "data invalida" << endl;
            continue;
        }
            
        if(stoi(ano) < 1000 || stoi(ano) > 2022){
            system("cls");
            cout << "data invalida" << endl;
            continue;
        }

        if(stoi(mes)){
            if(stoi(mes) == 2){
                if(modificacao.dia <= 28 && modificacao.dia > 1){
                    break;

                } else {
                    system("cls");
                    cout << "dia do mes invalido" << endl;
                    continue;
                }
            }
            
            if(stoi(mes) == 1 || stoi(mes) == 3|| stoi(mes) == 5 || stoi(mes) == 7 || stoi(mes) == 8 || stoi(mes) == 10 || stoi(mes) == 12){
                if(stoi(dia) <= 31 && stoi(dia) >= 1){
                    break;

                } else {
                    system("cls");
                    cout << "dia do mes invalido" << endl;
                    continue;
                }

            } else {
                if(stoi(dia) <= 30 && stoi(dia) >= 1){
                    break;

                } else {
                    system("cls");
                    cout << "dia do mes invalido" << endl;
                    continue;
                }
            }
        }
    }
    
    system("cls");

    while(1){
        if (codigo[cont].find(cod) != string::npos){

            cout << linhas[cont] << endl;
            cout << "\tcodigo encontrado\n";

            linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
            + dia + "/" + mes + "/" + ano + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," 
            + acad[cont] + "," + formacao[cont];  
            
            cout << linhas[cont] << endl;

            cont = 0; // zerando o contador
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    // Escrevendo no arquivo csv
    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            arquivo << linhas[i] << endl;
        }
    }

    arquivo.close(); 
}

void Funcionario::modificaSalario(string cod){
    int cont = 0;
    string modificacao;
    
    colunas();
    
    cout << "================================= Modificar Salario ===================================" << endl;
    cout << "\n";

    while(1){
        cout << "Digite o novo salario: ";
        getline(cin, modificacao);
    
        system("cls");

        if (stod(modificacao) <= 0){
            cout << "Salario invalido! Tente novamente" << endl;
            continue;

        } else {
            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    cout << linhas[cont] << endl;
                    cout << "\tcodigo encontrado\n";

                    // Acrescentar o ".00" se for necessário
                    if (modificacao.find(".") != string::npos){

                        linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] +
                        "," + data[cont] + "," + desig[cont] + "," + modificacao + "," + sup[cont] + "," +
                        acad[cont] + "," + formacao[cont]; 

                    } else {

                        linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] +
                        "," + data[cont] + "," + desig[cont] + "," + modificacao + ".00" + "," + sup[cont] + "," +
                        acad[cont] + "," + formacao[cont]; 
                        
                    }        
            
                    cout << linhas[cont] << endl;

                    cont = 0; // zerando o contador
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }

            // Escrevendo no arquivo csv
            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close(); 

            break;
        }
    }   
}

void Funcionario::modDesigParaOperador(string cod){
    int cont = 0;
    string modificacao = "Operador";

    colunas();

    while(1){
        if (codigo[cont].find(cod) != string::npos){

            cout << linhas[cont] << endl;
            cout << "\tcodigo encontrado\n";

            linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
            + "," + modificacao + "," + salario[cont] + "," + "Nan" + "," + "Nan" + "," + "Nan"; 
            
            cout << linhas[cont] << endl;

            cont = 0; // zerando o contador
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    // Escrevendo no arquivo csv
    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            arquivo << linhas[i] << endl;
        }
    }

    arquivo.close();   
}
    
void Funcionario::modDesigDeGerente(string cod){
    int cont;
    string modificacao, areaS, areaF, formacaoMax;

    colunas();

    while(1){
        cont = 0; 

        cout << "Digite a nova designacao - (Operador, Diretor ou Presidente?): ";
        getline(cin, modificacao);

        if (modificacao == "Operador" || modificacao == "operador"){
            
            modDesigParaOperador(cod);
            break;

        } else if (modificacao == "Diretor" || modificacao == "diretor"){
            
            cout << "\n\nQual a area de supervisao? ";
            getline(cin, areaS);

            cout << "\nQual a area de formacao? ";
            getline(cin, areaF);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    cout << linhas[cont] << endl;
                    cout << "\tcodigo encontrado\n";

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + areaF + ","
                    + formacao[cont]; 
            
                    cout << linhas[cont] << endl;

                    cont = 0; // zerando o contador
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            // Escrevendo no arquivo csv
            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close();   

            break;
            
        } else if (modificacao == "Presidente" || modificacao == "presidente"){

            cout << "\nQual a area de formacao? ";
            getline(cin, areaF);

            cout << "\nQual a formacao maxima? ";
            getline(cin, formacaoMax);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    cout << linhas[cont] << endl;
                    cout << "\tcodigo encontrado\n";

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + "Nan" + "," + areaF + ","
                    + formacaoMax;
            
                    cout << linhas[cont] << endl;

                    cont = 0; // zerando o contador
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            // Escrevendo no arquivo csv
            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close();   

            break;
            
        } else {
            system("cls");
            cout << "Resposta invalida, tente novamente." << endl;
            continue;
        }
    }
}

void Funcionario::modDesigDeOperador(string cod){
    int cont = 0;
    string modificacao, areaS, areaF, formacaoMax;

    colunas();

    while(1){
        cont = 0;

        cout << "Digite a nova designacao - (Gerente, Diretor ou Presidente?): ";
        getline(cin, modificacao);
        
        if (modificacao == "Gerente" || modificacao == "gerente"){

            cout << "\n\nQual a area de supervisao? ";
            getline(cin, areaS);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    cout << linhas[cont] << endl;
                    cout << "\tcodigo encontrado\n";

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + acad[cont] + ","
                    + formacao[cont]; 
    
            
                    cout << linhas[cont] << endl;

                    cont = 0; // zerando o contador
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            // Escrevendo no arquivo csv
            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close();   

            break;

        } else if (modificacao == "Diretor" || modificacao == "diretor"){

            cout << "\n\nQual a area de supervisao? ";
            getline(cin, areaS);

            cout << "\nQual a area de formacao? ";
            getline(cin, areaF);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    cout << linhas[cont] << endl;
                    cout << "\tcodigo encontrado\n";

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + areaF + ","
                    + formacao[cont];
    
                    cout << linhas[cont] << endl;

                    cont = 0; // zerando o contador
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            // Escrevendo no arquivo csv
            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close();   

            break;

        } else if (modificacao == "Presidente" || modificacao == "presidente"){
            
            cout << "\nQual a area de formacao? ";
            getline(cin, areaF);

            cout << "\nQual a formacao maxima? ";
            getline(cin, formacaoMax);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    cout << linhas[cont] << endl;
                    cout << "\tcodigo encontrado\n";

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + sup[cont] + "," + areaF + ","
                    + formacaoMax;
    
                    cout << linhas[cont] << endl;

                    cont = 0; // zerando o contador
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            // Escrevendo no arquivo csv
            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close();   

            break;

        } else {
            system("cls");
            cout << "Resposta invalida, tente novamente." << endl;

            continue;        
        }
    }
}

void Funcionario::modDesigDeDiretor(string cod){
    int cont;
    string modificacao, areaS, areaF, formacaoMax;

    colunas();

    while(1){
        cont = 0;

        cout << "Digite a nova designacao - (Operador, Gerente ou Presidente?): ";
        getline(cin, modificacao);
    
        if (modificacao == "Operador" || modificacao == "operador"){
            
            modDesigParaOperador(cod);
            break;

        } else if (modificacao == "Gerente" || modificacao == "gerente"){

            cout << "\n\nQual a area de supervisao? ";
            getline(cin, areaS);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    cout << linhas[cont] << endl;
                    cout << "\tcodigo encontrado\n";

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + "Nan" + ","
                    + formacao[cont]; 
    
                    cout << linhas[cont] << endl;

                    cont = 0; // zerando o contador
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            // Escrevendo no arquivo csv
            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close();   

            break;

        } else if (modificacao == "Presidente" || modificacao == "presidente"){
            
            cout << "\nQual a area de formacao? ";
            getline(cin, areaF);

            cout << "\nQual a formacao maxima? ";
            getline(cin, formacaoMax);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    cout << linhas[cont] << endl;
                    cout << "\tcodigo encontrado\n";

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + "Nan" + "," + areaF + ","
                    + formacaoMax; 
    
                    cout << linhas[cont] << endl;

                    cont = 0; // zerando o contador
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            // Escrevendo no arquivo csv
            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close();   

            break;

        } else {
            system("cls");
            cout << "Resposta invalida, tente novamente." << endl;

            continue;        
        }
    }
}

void Funcionario::modDesigDePresidente(string cod){
    int cont;
    string modificacao, areaS, areaF, formacaoMax;

    colunas();

    while(1){
        cont = 0;

        cout << "Digite a nova designacao - (Operador, Gerente ou Diretor?): ";
        getline(cin, modificacao);

        if (modificacao == "Operador" || modificacao == "operador"){
            
            modDesigParaOperador(cod);
            break;

        } else if (modificacao == "Gerente" || modificacao == "gerente"){

            cout << "\n\nQual a area de supervisao? ";
            getline(cin, areaS);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    cout << linhas[cont] << endl;
                    cout << "\tcodigo encontrado\n";

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + "Nan" + "," + "Nan";
    
                    cout << linhas[cont] << endl;

                    cont = 0; // zerando o contador
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            // Escrevendo no arquivo csv
            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close();   

            break;

        } else if (modificacao == "Diretor" || modificacao == "diretor"){
            
            cout << "\nQual a area de supervisao?";
            getline(cin, areaS);

            cout << "\nQual a area de formacao? ";
            getline(cin, areaF);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    cout << linhas[cont] << endl;
                    cout << "\tcodigo encontrado\n";

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + areaF + "," + "Nan"; 
    
                    cout << linhas[cont] << endl;

                    cont = 0; // zerando o contador
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            // Escrevendo no arquivo csv
            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close();   

            break;

        } else {
            system("cls");
            cout << "Resposta invalida, tente novamente." << endl;
    
            continue;        
        }
    }
}

void Funcionario::modificaDesignacao(string cod){
    string desigAtual;
    int cont = 0;
    int c = 0;

    colunas();
    
    while(1){
        cont = 0;
        c = 0;

        while(1){
            if (codigo[cont].find(cod) != string::npos){

                cout << linhas[cont] << endl;
                cout << "\tcodigo encontrado\n";

                desigAtual = desig[cont];

                if (desigAtual == "Operador" || desigAtual == "operador"){
                    desigAtual = "1";
                    c = 1;
                } else if (desigAtual == "Gerente" || desigAtual == "gerente"){
                    desigAtual = "2";
                    c = 1;
                } else if (desigAtual == "Diretor" || desigAtual == "diretor"){
                    desigAtual = "3";
                    c = 1;
                } else {
                    desigAtual = "4";
                    c = 1;
                }
               
                if (c == 1){
                    break;
                }
                    
            } else {
                cont++;
            }    
        }
        
        system("cls");
 
        if (stoi(desigAtual) > 0 && stoi(desigAtual) <= 4){

            switch (stoi(desigAtual)){
                case 1:
                    cout << "================================= Modificar Designacao ===================================" << endl;
                    cout << "\n";
                    modDesigDeOperador(cod);
                    break;
        
                case 2:
                    cout << "================================= Modificar Designacao ===================================" << endl;
                    cout << "\n";
                    modDesigDeGerente(cod); 
                    break;

                case 3:
                    cout << "================================= Modificar Designacao ===================================" << endl;
                    cout << "\n";
                    modDesigDeDiretor(cod); 
                    break;

                case 4:
                    cout << "================================= Modificar Designacao ===================================" << endl;
                    cout << "\n";
                    modDesigDePresidente(cod); 
                    break;
            }

            break;

        } else {
            
            cout << "Opcao invalida! Tente novamente" << endl;
            continue;

        }
    }      
}

void Funcionario::modificarFuncionario(){
    int c = 0, cont = 0;
    string codigo;
    string cod, aux;
    int desig, escolha = 0, i = 0;

    
    cout << "========================================= Modificar ========================================" << endl;
        
    while(1){
        c = 1;
        while(1){
            cout << "\nQual o codigo do funcionario?\n";
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
                cout << "Codigo maior do que o esperado" << endl;
                continue;
            }
        }

        for(int i = 1; i < 100; i++){
            if(linhas[i] != ""){
                aux = linhas[i];
                aux.erase(3, aux.length());
            }

            if(aux == cod){
                cout << "Codigo invalido, tente novamente" << endl;
                c = 0;
                break;
            }
        }

        if(c == 1){
            break;
        }
    
        system("cls");
    }

    while(1){   
        cout << "O que deseja modificar?" << endl;
        cout << "[1] Codigo\n";
        cout << "[2] Nome\n";
        cout << "[3] Endereco\n"; 
        cout << "[4] Telefone\n";
        cout << "[5] Data\n";
        cout << "[6] Salario\n";
        cout << "[7] Designacao\n\n";

        cin >> escolha;
        getchar();
   
        system("cls");

        if (escolha <= 0 || escolha > 7){
            cout << "Escolha invalida! Tente novamente" << endl;
            continue;

        } else {
            switch (escolha){
                case 1:
                    modificaCodigo(cod);
                    break;
        
                case 2:
                    modificaNome(cod);
                    break;
        
                case 3:
                    modificaEndereco(cod);
                    break;
        
                case 4:
                    modificaTelefone(cod);
                    break;

                case 5:
                    modificaData(cod);
                    break;
        
                case 6:
                    modificaSalario(cod);
                    break;
        
                case 7:
                    modificaDesignacao(cod);
                    break;
            }

            break;
        }
    }
}
/* ==========================================================================================================*/

void Funcionario::excluirRegistro(){
    string cod, escolha,linha[100], linhaAux;
    int cont = 0, teste = 1;
    fstream file;

    lerArquivo(); // Lê o arquivo com todas as informações dos usuário e passa para as variáveis corrrespondentes
    colunas();

    system("cls");

    cout << "Digite o Codigo do Registro: ";
    
    cin >> cod;

    for(int i = 0; i < 100; i++){
        if(codigo[i] == cod){ // procura o código digitado entre os códigos do arquivo
            if(desig[i] == "Presidente" || desig[i] == "Diretor"){ // verifica se esse código pertence a um Presidente ou Diretor
                system("cls");
                cout << "Registro nao pode ser excluido." << endl;
                break;
            }else{
                system("cls");
                cout << "codigo encontrado: " << cod << endl;
                cout << "Deseja excluir o registro do Arquivo ? ";
                while(1){
                    cout << "Digite (s)sim ou (n)nao: ";
                    cin >> escolha;
                    getchar();
                    if(escolha == "n" || escolha == "N"){
                        system("cls");
                        cout << "Registro nao exluido." << endl;
                        break;
                    }else if(escolha == "s" || escolha == "S"){
                        system("cls");
                        cout << "O registro foi excluido." << endl;
                        cont = i+1; // Armazena o index da linha em que o código foi excluído
                        teste = 0;
                        break;
                    }else{
                        system("cls");
                        cout << "Opcao invalida" << endl;
                        continue;
                    }
                }
                break;
            }
        }else if(linhas[i] == "" && i == 99){ // se código digitado não for encontrado e a linha estiver vazia encerra o for
            system("cls");
            cout << "Codigo nao encontrado." << endl;
        }
    }

    int i = 0;
    for(int j = 0; j < 100; j++){
        if((j == cont) && (teste == 0)){ //o index corresponde ao contador e variável teste está zerada comfirmando que essa linha não dever 
                                         // ser salva no arquivo logo deve ser excluída.
        }else{
            linhaAux = linhas[j];
            linha[i] = linhaAux;
            i++;
        }
    }


    file.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i<100; i++){
        if(linha[i] == ""){
            break;
        }
        file << linha[i] << endl;
    }
    file.close();

}

//Numeros aletórios de dias trabalhados
double Funcionario::geraDiasTrabalhados(double m){
    double dias;
    if(m == 2){
        while(1){
            dias = 1 + rand() % 28;
            if(dias <= 28 && dias > 14){
                return dias;
            }
        }
    }else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
        while(1){
            dias = 1 + rand() % 31;
            if(dias <= 31 && dias > 15){
                return dias;
            }
        }
    }else{
        while(1){
            dias = 1 + rand() % 30;
            if(dias <= 30 && dias > 15){
                return dias;
            }
        }
    }
}

//Numeros aletórios de horas extras
double Funcionario::geraHorasExtras(double m){
    double horas;
    while(1){
        horas = rand() % 2;
        horas = horas*m;
        if(horas < 56){
            return horas;
        }
    }

}

void Funcionario::calculaFolhaSalarial(){
    ifstream fileTeste;
    fstream file;
    string data, dataM, dataA;
    string meses[12]{"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
    int testeMes=0, testeAno=0;
    double salariosBruto[1000], salariosLiquido[100], descontoINSS[100], descontoIRRF[100], salarioEmpresa=0;
    double mes;

    while(1){
        cout << "Digite o ano e o mes, em que a folha salarial vai ser calculada: " << "Padrao : yyxxxx" << endl;
        cin >> data;
        getchar();
        dataM = data;
        dataM.erase(2, 6);
        dataA = data;
        dataA.erase(0, 2);
        
        for(int i = 0; i<12; i++){
            if(dataM == meses[i]){
                testeMes=1;
                break;
            }
        }
        
        if(strlen(dataA.c_str()) == 4){
            testeAno=1;
        }

        if((testeAno == 1) && (testeMes == 1)){
            break;
        }else{
            cout << "Data invalida." << endl;
            continue;
        }
    }

    data = "./csv/FolhaSalarial-" + data + ".csv";

    // verifica se o arquivo já foi criado
    fileTeste.open(data);
    if (fileTeste.is_open()){
        cout<<"Folha Salarial dessa data ja foi calculada"<<endl;
        fileTeste.close();
    }else{
        fileTeste.close();

        lerArquivo();
        colunas();


        // transforma string em double
        for(int i = 0; i < 100; i++){
                if(salario[i] != ""){
                    salariosBruto[i] = stod(salario[i]);
                }
        }

        //variavel mes da folha salarial
        dataM = dataM.erase(2, dataM.length());
        mes = stod(dataM);

        // Calcula salario bruto daquele mes
        for(int i = 0; i < 100; i++){
            if(salario[i] != ""){
                if(mes == 2){
                    salariosBruto[i] = ((salariosBruto[i]/28)*geraDiasTrabalhados(mes)) +  ((salariosBruto[i]/28)/8)*2*geraHorasExtras(mes);
                }else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                    salariosBruto[i] = ((salariosBruto[i]/31)*geraDiasTrabalhados(mes)) +  ((salariosBruto[i]/31)/8)*2*geraHorasExtras(mes);
                }else{
                    salariosBruto[i] = ((salariosBruto[i]/30)*geraDiasTrabalhados(mes)) +  ((salariosBruto[i]/30)/8)*2*geraHorasExtras(mes);       
                }
            }
        }

        //desconto inss
        for(int i = 0; i < 100; i++){
            if(salario[i] != ""){
                if(salariosBruto[i] <= 1212){
                    descontoINSS[i] = (salariosBruto[i]*(7.5/100));
                    salariosLiquido[i] = salariosBruto[i] - (salariosBruto[i]*(7.5/100));
                }else if(salariosBruto[i] <= 2427.35){
                    descontoINSS[i] = (((salariosBruto[i] - 1212.01)*(9*1.0/100))+90.90);
                    salariosLiquido[i] = salariosBruto[i] - (((salariosBruto[i] - 1212.01)*(9*1.0/100))+90.90);
                }else if(salariosBruto[i] <= 3641.03){
                    descontoINSS[i] = (((salariosBruto[i]-2427.36)*(12*1.0/100))+200.28);
                    salariosLiquido[i] = salariosBruto[i] - (((salariosBruto[i]-2427.36)*(12*1.0/100))+200.28);  
                }else if(salariosBruto[i] <= 7087.22){
                    descontoINSS[i] = (((salariosBruto[i]-3641.04)*(14*1.0/100))+345.92);
                    salariosLiquido[i] = salariosBruto[i] - (((salariosBruto[i]-3641.04)*(14*1.0/100))+345.92);
                }else if((salariosBruto[i] >= 7087.23)){
                    descontoINSS[i] = 828.38;
                    salariosLiquido[i] = salariosBruto[i] - 828.38;
                }
            }
        }
        
        //Desconto irrf
        for(int i = 0; i < 100; i++){
            if(salario[i] != ""){
                if(salariosLiquido[i] <= 1903.98){
                    descontoIRRF[i] = 0;
                }else if(salariosLiquido[i] <= 2826.65){
                    descontoIRRF[i] = ((salariosLiquido[i]*(7.5/100))-142.80);
                    salariosLiquido[i] = salariosLiquido[i] - ((salariosLiquido[i]*(7.5/100))-142.80);
                }else if(salariosLiquido[i] <= 3751.05){
                    descontoIRRF[i] = ((salariosLiquido[i]*(15*1.0/100))-354.80);
                    salariosLiquido[i] = salariosLiquido[i] - ((salariosLiquido[i]*(15*1.0/100))-354.80);
                }else if(salariosLiquido[i] <= 4664.68){
                    descontoIRRF[i] = ((salariosLiquido[i]*(22.5*1.0/100))-636.13);
                    salariosLiquido[i] = salariosLiquido[i] - ((salariosLiquido[i]*(22.5*1.0/100))-636.13);     
                }else if(salariosLiquido[i] >= 4664.69){
                    descontoIRRF[i] = ((salariosLiquido[i]*(27.5/100))-869.36);
                    salariosLiquido[i] = salariosLiquido[i] - ((salariosLiquido[i]*(27.5/100))-869.36);
                }
            }
        }

        file.open(data, fstream::out);
        file << "Funcinario," << "Designacao," <<"SalarioBruto," << "INSS," << "IRRF," << "SalarioLiquido" << endl; 
        for(int i = 0; i<100; i++){
            if(salariosBruto[i] != 0){
            file << nome[i] << "," << desig[i] << "," << fixed << setprecision(2) << "R$" << salariosBruto[i] << "," << fixed << setprecision(2) 
            << "R$" <<descontoINSS[i] << "," << fixed << setprecision(2) << "R$" << descontoIRRF[i] << "," << fixed << setprecision(2) << "R$" 
            << salariosLiquido[i] << endl;
            salarioEmpresa+=salariosLiquido[i];
            }
        }
        file << "SalarioEmpresa: " << fixed << setprecision(2) << salarioEmpresa << endl;
        file.close();

    }
}

void Funcionario::exibeFolhaSalarialFuncionario(){
    ifstream fileTeste;
    fstream file;
    string data, arquivo[100], nomeF, codigoF, dataM, dataA;
    string meses[12]{"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
    int testeMes=0, testeAno=0;
    int i = 0, opcao, teste, valor;

    lerArquivo();
    colunas();

    while(1){
        cout << "Digite o ano e o mes, em que a folha salarial vai ser exibida: " << "Padrao : yyxxxx" << endl;
        cin >> data;
        getchar();
        dataM = data;
        dataM.erase(2, 6);
        dataA = data;
        dataA.erase(0, 2);
        for(int i = 0; i<12; i++){
            if(dataM == meses[i]){
                testeMes=1;
                break;
            }
        }
        
        if(strlen(dataA.c_str()) == 4){
            testeAno=1;
        }

        if((testeAno == 1) && (testeMes == 1)){
            break;
        }else{
            cout << "Data invalida." << endl;
            continue;
        }
    }
    while(1){
        cout << "Deseja fazer a busca por nome(1) ou codigo(2)?" << endl;
        cin >> opcao;
        if(opcao == 1){
            teste = 0;
            cout << "Digite o nome: ";
            getchar();
            getline(cin, nomeF);
            for(i=0;i<100;i++){
                if(nomeF == nome[i]){
                    valor = i;
                    teste = 1;
                    break;
            }
        }
        if(teste)
                break;
        cout << "Nome Inválido" << endl;
        
        }else if(opcao == 2){
            teste = 0;
            cout << "Digite o codigo: ";
            getchar();
            getline(cin, codigoF);
            for(i=0;i<100;i++){
                if(codigoF == codigo[i]){
                    valor = i;
                    teste = 1;
                    break;
                }
            }
            if(teste)
                break;
            cout << "codigo Inválido" << endl;     
        }
    }

    data = "./csv/FolhaSalarial-" + data + ".csv";
    cout << data << endl;

    fileTeste.open(data);
    if (fileTeste.is_open()){
        cout<<"Folha Salarial dessa data ja foi calculada"<<endl;
        i=0;
        while(getline(fileTeste, arquivo[i])){
            i++;
        }
        cout << "Codigo," << arquivo[0] << endl;
        cout << codigo[valor] << "," << arquivo[valor+1] << endl;

        fileTeste.close();
    }else{
        fileTeste.close();
        cout<<"Folha Salarial dessa data ainda não foi calculada"<<endl;
        // calculaFolhaSalarial();
        
        // fileTeste.open(data);

        // cout<<"Folha Salarial dessa data foi calculada"<<endl;
        // i=0;
        // while(getline(fileTeste, arquivo[i])){
        //     i++;
        // }
        
        // cout << "Codigo," << arquivo[0] << endl;
        // cout << codigo[valor] << "," << arquivo[valor+1] << endl;

        // fileTeste.close();
    }

}

void Funcionario::exibeFolhaSalarialEmpresa(){
    int opcao, i, k, l;
    string data, arquivo[100], ano, busca[12], SalarioBrutoS[100],INSSS[100],IRRFS[100],SalarioLiquidoS[100], linha, temp;
    ifstream fileTeste;
    double SalarioBruto[100],INSS[100],IRRF[100],SalarioLiquido[100], salarioEmpresa=0;

    lerArquivo();
    colunas();

    while(1){
        cout << "Exibir folha salarial mensal ou anual ? (1) - mensal / (2) - anual" << endl;
        cin >> opcao;
        getchar();
        if(opcao == 1){
            break;
        }else if(opcao == 2){
            break;
        }else
            continue;
    }
    

    if(opcao == 1){
        cout << "Digite o ano e o mes, folha salarial que vai ser exibida: " << "Padrao : yyxxxx" << endl;
        cin >> data;
        data = "./csv/FolhaSalarial-" + data + ".csv";
        cout << data << endl;

        fileTeste.open(data);
        if (fileTeste.is_open()){
            cout<<"Folha Salarial dessa data ja foi calculada"<<endl;
            i=0;
            while(getline(fileTeste, arquivo[i])){
                cout << arquivo[i] << endl;
            }

            fileTeste.close();
        }else{
            fileTeste.close();
            cout<<"Folha Salarial dessa data ainda não foi calculada"<<endl;

            // calculaFolhaSalarial();
            
            // fileTeste.open(data);

            // cout<<"Folha Salarial dessa data foi calculada"<<endl;
            // i=0;
            // while(getline(fileTeste, arquivo[i])){
            //     cout << arquivo[i] << endl;
            // }

            // fileTeste.close();
        }
    }else if(opcao == 2){
        cout << "Digite o ano da folha salarial que vai ser exibida: " << "Padrao : xxxx" << endl;
        cin >> ano;

        for(int j = 1; j<13; j++){
            if(j < 10){
                busca[j-1] = "./csv/FolhaSalarial-0" + to_string(j) + ano + ".csv";
            }else if(j >= 10){
                busca[j-1] = "./csv/FolhaSalarial-" + to_string(j) + ano + ".csv";
            }

            fileTeste.open(busca[j-1]);
            if (fileTeste.is_open()){
                i=0;
                l = 0;
                while(getline(fileTeste, linha)){
                    temp = "";
                    for(k = 0; k < linha.size(); k++){
                        if(linha[k] != ','){
                            temp = temp + linha[k];
                        }else{
                            break;
                        }
                    }
                        
                    temp = "";
                    for(++k; k < linha.size(); k++){
                        if(linha[k] != ','){
                            temp = temp + linha[k];
                        }else{
                            break;
                        }
                    }

                    temp = "";
                    for(++k; k < linha.size(); k++){
                        if(linha[k] != ','){
                            temp = temp + linha[k];
                        }else{
                            break;
                        }
                    }
                    SalarioBrutoS[i]=temp;

                    temp = "";
                    for(++k; k < linha.size(); k++){
                        if(linha[k] != ','){
                            temp = temp + linha[k];
                        }else{
                            break;
                        }
                    }
                    INSSS[i]=temp;

                    temp = "";
                    for(++k; k < linha.size(); k++){
                        if(linha[k] != ','){
                            temp = temp + linha[k];
                        }else{
                            break;
                        }
                    }
                    IRRFS[i]=temp;

                    temp = "";
                    for(++k; k < linha.size(); k++){
                        if(linha[k] != ','){
                            temp = temp + linha[k];
                        }else{
                            break;
                        }
                    }
                    SalarioLiquidoS[i]=temp;

                    if(l>0 && SalarioBrutoS[i] != ""){
                        SalarioBrutoS[i] = SalarioBrutoS[i].erase(0,2);
                        INSSS[i] = INSSS[i].erase(0,2);
                        IRRFS[i] = IRRFS[i].erase(0,2);
                        SalarioLiquidoS[i] = SalarioLiquidoS[i].erase(0,2);
                        try{
                            SalarioBruto[l-1] += stod(SalarioBrutoS[i]);
                            INSS[l-1] += stod(INSSS[i]);
                            IRRF[l-1] += stod(IRRFS[i]);
                            SalarioLiquido[l-1] += stod(SalarioLiquidoS[i]);
                        }catch(std :: invalid_argument  const & ex ){
                            cout << "O parâmetro não é uma string" << endl;
                        }
                    }
                    l++;
                }

                i++;
                    
                fileTeste.close();
            }else{
                fileTeste.close();
                cout<<"Folha Salarial do mes " << j << " nao foi calculada" <<endl;

                // calculaFolhaSalarial();
                
                // fileTeste.open(data);

                // cout<<"Folha Salarial dessa data foi calculada"<<endl;
                // i=0;
                // while(getline(fileTeste, arquivo[i])){
                //     cout << arquivo[i] << endl;
                // }

                // fileTeste.close();
            }
        }

        cout << "Folha Salaria: " << ano << endl;
        cout << "Funcinario,Designacao,SalarioBruto,INSS,IRRF,SalarioLiquido" << endl;
        for(i=0; i < 100; i++){
            if(nome[i] != ""){
                cout << nome[i] << "," << desig[i] << ',' << SalarioBruto[i] << "," << INSS[i] << "," << IRRF[i] << "," << SalarioLiquido[i] 
                << endl;
                salarioEmpresa += SalarioLiquido[i];
            }else{
                cout << "SalarioEmpresa: " << salarioEmpresa << endl;
                break;
            } 
        }
    }
}
