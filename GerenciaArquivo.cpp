#include "GerenciaArquivo.h"
#include <iostream>
#include <fstream>
#include <string>


GerenciaArquivo::GerenciaArquivo()
{

}

GerenciaArquivo::~GerenciaArquivo()
{

}

string GerenciaArquivo::getCodigo(int i){
    return codigo[i];
}
string GerenciaArquivo::getDesig(int i){
    return desig[i];
}
string GerenciaArquivo::getSalario(int i){
    return salario[i];
}
string GerenciaArquivo::getNome(int i){
    return nome[i];
}
string GerenciaArquivo::getEnd(int i){
    return end[i];
}
string GerenciaArquivo::getTelefone(int i){
    return telefone[i];
}
string GerenciaArquivo::getData(int i){
    return data[i];
}
string GerenciaArquivo::getSup(int i){
    return sup[i];
}
string GerenciaArquivo::getAcad(int i){
    return acad[i];
}
string GerenciaArquivo::getFormacao(int i){
    return formacao[i];
}

string GerenciaArquivo::getLinhas(int i){
    return linhas[i];
}

void GerenciaArquivo::criarArquivo(){
    arquivo.open("./csv/Empresa.csv", ios::in);

    if(!arquivo.is_open()){
        arquivo.open("./csv/Empresa.csv", ios::out);
    }

    arquivo.close();
}

void GerenciaArquivo::lerArquivo(){
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

void GerenciaArquivo::exibirArquivo(){
    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            cout << linhas[i] << endl;
        }
    }
}

void GerenciaArquivo::separadorColuna(string colPresent[], int del[]){
    for(int i = 1, j = 0; i < 100; i++, j++){
        if(linhas[i] != ""){
            colPresent[j] = linhas[i];
            colPresent[j].erase(0, del[j]);
            colPresent[j].erase(colPresent[j].find(','));
        }
        else{
            break;
        }
    }
}

void GerenciaArquivo::colunas(){
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
    }
}

string GerenciaArquivo::forEndereco(string api[], int line, int tam){
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

string GerenciaArquivo::retornaEndereco(string cep){
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

//Numeros aletórios de dias trabalhados
double GerenciaArquivo::geraDiasTrabalhados(double m){
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
double GerenciaArquivo::geraHorasExtras(double m){
    double horas;
    while(1){
        horas = rand() % 2;
        horas = horas*m;
        if(horas < 56){
            return horas;
        }
    }

}

void GerenciaArquivo::modificaCodigo(string cod){
    int c = 0, cont = 0;
    string mod, aux;
    string modificacao;
    
    colunas();

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

            linhas[cont] = modificacao + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
            + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont];

            cont = 0;
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            arquivo << linhas[i] << endl;
        }
    }

    arquivo.close(); 
}        

void GerenciaArquivo::modificaNome(string cod){
    int cont = 0;
    string modificacao;

    colunas();

    cout << "Digite o novo nome: ";
    getline(cin, modificacao);

    system("cls");

    while(1){
        if (codigo[cont].find(cod) != string::npos){

            linhas[cont] = codigo[cont] + "," + modificacao + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
            + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 

            cont = 0;
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            arquivo << linhas[i] << endl;
        }
    }

    arquivo.close();       
}        

void GerenciaArquivo::modificaEndereco(string cod){
    int cont = 0;
    string yn, cep;
    string modificacao, endereco, logradouro, bairro, cidade, uf, numero;

    colunas();
    
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

            linhas[cont] = codigo[cont] + "," + nome[cont] + "," + modificacao + "," + telefone[cont] + "," + data[cont]
            + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 

            cont = 0;
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            arquivo << linhas[i] << endl;
        }
    }

    arquivo.close();  
}        

void GerenciaArquivo::modificaTelefone(string cod){
    int cont = 0;
    string modificacao;

    colunas();

    cout << "Digite o novo telefone: ";
    getline(cin, modificacao);

    system("cls");

    while(1){
        if (codigo[cont].find(cod) != string::npos){

            linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + modificacao + "," + data[cont]
            + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 

            cont = 0;
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            arquivo << linhas[i] << endl;
        }
    }

    arquivo.close();   
}

void GerenciaArquivo::modificaData(string cod){
    typedef struct{
        int dia;
        int mes;
        int ano;
    } Data;

    Data modificacao; 
    string dia, mes, ano;
    int cont = 0;
    
    colunas();

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

            linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
            + dia + "/" + mes + "/" + ano + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," 
            + acad[cont] + "," + formacao[cont];  
            
            cont = 0;
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            arquivo << linhas[i] << endl;
        }
    }

    arquivo.close(); 
}

void GerenciaArquivo::modificaSalario(string cod){
    int cont = 0;
    string modificacao;
    
    colunas();

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

                    if (modificacao.find(".") != string::npos){

                        linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] +
                        "," + data[cont] + "," + desig[cont] + "," + modificacao + "," + sup[cont] + "," +
                        acad[cont] + "," + formacao[cont]; 

                    } else {

                        linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] +
                        "," + data[cont] + "," + desig[cont] + "," + modificacao + ".00" + "," + sup[cont] + "," +
                        acad[cont] + "," + formacao[cont]; 
                        
                    }        

                    cont = 0;
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }

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

void GerenciaArquivo::modDesigParaOperador(string cod){
    int cont = 0;
    string modificacao = "Operador";

    colunas();

    while(1){
        if (codigo[cont].find(cod) != string::npos){

            linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
            + "," + modificacao + "," + salario[cont] + "," + "Nan" + "," + "Nan" + "," + "Nan"; 
            
            cont = 0;
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < 100; i++){
        if(linhas[i] != ""){
            arquivo << linhas[i] << endl;
        }
    }

    arquivo.close();   
}
    
void GerenciaArquivo::modDesigDeGerente(string cod){
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
            
            cout << "Qual a area de supervisao? ";
            getline(cin, areaS);

            cout << "Qual a area de formacao? ";
            getline(cin, areaF);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + areaF + ","
                    + formacao[cont]; 

                    cont = 0;
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close();   

            break;
            
        } else if (modificacao == "Presidente" || modificacao == "presidente"){

            cout << "Qual a area de formacao? ";
            getline(cin, areaF);

            cout << "Qual a formacao maxima? ";
            getline(cin, formacaoMax);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + "Nan" + "," + areaF + ","
                    + formacaoMax;

                    cont = 0;
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

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

void GerenciaArquivo::modDesigDeOperador(string cod){
    int cont = 0;
    string modificacao, areaS, areaF, formacaoMax;

    colunas();

    while(1){
        cont = 0;

        cout << "Digite a nova designacao - (Gerente, Diretor ou Presidente?): ";
        getline(cin, modificacao);
        
        if (modificacao == "Gerente" || modificacao == "gerente"){

            cout << "Qual a area de supervisao? ";
            getline(cin, areaS);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + acad[cont] + ","
                    + formacao[cont]; 

                    cont = 0;
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close();   

            break;

        } else if (modificacao == "Diretor" || modificacao == "diretor"){

            cout << "Qual a area de supervisao? ";
            getline(cin, areaS);

            cout << "Qual a area de formacao? ";
            getline(cin, areaF);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + areaF + ","
                    + formacao[cont];

                    cont = 0;
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close();   

            break;

        } else if (modificacao == "Presidente" || modificacao == "presidente"){
            
            cout << "Qual a area de formacao? ";
            getline(cin, areaF);

            cout << "Qual a formacao maxima? ";
            getline(cin, formacaoMax);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + sup[cont] + "," + areaF + ","
                    + formacaoMax;

                    cont = 0;
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

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

void GerenciaArquivo::modDesigDeDiretor(string cod){
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

            cout << "Qual a area de supervisao? ";
            getline(cin, areaS);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + "Nan" + ","
                    + formacao[cont]; 

                    cont = 0;
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }

            arquivo.close();   

            break;

        } else if (modificacao == "Presidente" || modificacao == "presidente"){
            
            cout << "Qual a area de formacao? ";
            getline(cin, areaF);

            cout << "Qual a formacao maxima? ";
            getline(cin, formacaoMax);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + "Nan" + "," + areaF + ","
                    + formacaoMax; 
    
                    cont = 0;
                    break; 
                } else {
                    cont++;
                }    
            }       

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

void GerenciaArquivo::modDesigDePresidente(string cod){
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

            cout << "Qual a area de supervisao? ";
            getline(cin, areaS);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + "Nan" + "," + "Nan";
    
                    cont = 0;     
                    break;     
                } else {
                    cont++;
                }    
            }       

            arquivo.open("./csv/Empresa.csv", ios::out);
            for(int i = 0; i < 100; i++){
                if(linhas[i] != ""){
                    arquivo << linhas[i] << endl;
                }
            }
            arquivo.close();   

            break;
        } else if (modificacao == "Diretor" || modificacao == "diretor"){
            cout << "Qual a area de supervisao?";
            getline(cin, areaS);

            cout << "Qual a area de formacao? ";
            getline(cin, areaF);

            system("cls");

            while(1){
                if (codigo[cont].find(cod) != string::npos){

                    linhas[cont] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + areaF + "," + "Nan"; 
    
                    cont = 0;
                    break;      
                } else {
                    cont++;
                }    
            }       
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

void GerenciaArquivo::modificaDesignacao(string cod){
    string desigAtual;
    int cont = 0;
    int c = 0;

    colunas();
    
    while(1){
        cont = 0;
        c = 0;

        while(1){
            if (codigo[cont].find(cod) != string::npos){

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
                    modDesigDeOperador(cod);
                    break;
        
                case 2:
                    modDesigDeGerente(cod); 
                    break;

                case 3:
                    modDesigDeDiretor(cod); 
                    break;
                case 4:
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
