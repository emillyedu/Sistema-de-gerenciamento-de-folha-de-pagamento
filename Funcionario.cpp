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
double Funcionario::aumentoDeSalarios(){
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
    string Nan("Nan"), logradouro, bairro, cidade, uf, linha[100], line, dia, mes, ano;
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

void Funcionario::excluirRegistro(){
    string cod, escolha, linha[100], linhaAux;
    int cont = 0, teste = 1;
    fstream file;

    lerArquivo();
    colunas();

    system("cls");

    cout << "Digite o Codigo do Registro: ";
    
    cin >> cod;

    for(int i = 0; i < 100; i++){
        if(codigo[i].find(cod) != string::npos && cod.size() == 3){
            if((linhas[i+1].find("Presidente") != string::npos) || (linhas[i+1].find("Diretor") != string::npos)){
                system("cls");
                cout << "Registro nao pode ser excluido." << endl;
                break;
            }else{
                system("cls");
                cout << "codigo encontrado: " << cod << endl;
                cout << "Deseja excluir o registro do Arquivo ? ";
                while(1){
                    cout << "Digite sim ou nao: ";
                    cin >> escolha;
                    if(escolha == "nao"){
                        system("cls");
                        cout << "Registro nao exluido." << endl;
                        break;
                    }else if(escolha == "sim"){
                        system("cls");
                        cout << "O registro foi excluido." << endl;
                        cont = i+1;
                        teste = 0;
                        break;
                    }else{
                        system("cls");
                        cout << "Opcao invalida" << endl;
                    }
                }
                break;
            }
        }else if(linha[i] == ""){
            system("cls");
            cout << "Codigo nao encontrado." << endl;
        }
    }

    int i = 0;
    for(int j = 0; j < 100; j++){
        if((j == cont) && (teste == 0)){

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
    srand(time(NULL));
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
        srand(time(NULL));
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
    string data, Smes;
    double salariosBruto[1000], salariosLiquido[100], descontoINSS[100], descontoIRRF[100], salarioEmpresa=0;
    double mes;

    cout << "Digite o ano e o mes, em que a folha salarial vai ser calculada: " << "Padrao : yyxxxx" << endl;
    cin >> data;
    Smes = data;

    data = "./csv/FolhaSalarial-" + data + ".csv";
    cout << data << endl;

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
        Smes = Smes.erase(2, Smes.length());
        mes = stod(Smes);

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
                // cout << salariosBruto[i] << endl;
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
                // cout << salariosLiquido[i] << endl;
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
                // cout << salariosLiquido[i] << endl;
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