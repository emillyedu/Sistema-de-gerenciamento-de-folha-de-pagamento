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

void Funcionario::addFuncionario(){
    typedef struct{
        int dia;
        int mes;
        int ano;
    } Data;

    Data data;
    string nome, aux, codigo, cod, telefone, designacao, endereco, cep, numero, areaS[2], areaF[2], formacao;
    string Nan("Nan"), logradouro, bairro, cidade, uf, linha[100], line, dia, mes, ano;
    string yn;
    int i, c, desig, li = 0;
    float salario;

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
                    aux = linhas[i];
                    aux.erase(3, aux.length());
                }

                if(aux == codigo){
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
        
        if(endereco == "Nan" || yn == "N" || yn == "n"){
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
        if(designacao == "gerente" || designacao == "Gerente"){
            linha[li] = line + "," + areaS[0] + "," + Nan + "," + Nan + "\n";
        }
        else if(designacao == "diretor" || designacao == "Diretor"){
            linha[li] = line + "," + areaS[1] + "," + areaF[0] + "," + Nan + "\n";
        }
        else if(designacao == "presidente" || designacao == "Presidente"){
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