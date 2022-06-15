#include "GerenciaArquivo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

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

void GerenciaArquivo::clearString(string *str){
    for(int i = 0; i < 100; i++) {
        str[i].clear();
    }
}

void GerenciaArquivo::criarArquivo(){
    arquivo.open("./csv/Empresa.csv", ios::in);

    if(!arquivo.is_open()){
        arquivo.open("./csv/Empresa.csv", ios::out);
        arquivo << "codigo,nome,end,telefone,data de ingresso,designacao,salario,area de supervisao,area academica,formacao maxima";
    }

    arquivo.close();
}

void GerenciaArquivo::lerArquivo(){
    arquivo.open("./csv/Empresa.csv", ios::in);
    
    clearString(linhas);

    int i = 0;
    if(arquivo.is_open()){
        while(getline(arquivo, linhas[i])){
            i++;
        }
        tamArq = i;
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

string GerenciaArquivo::transformaStringMin(string str){
    char* c;
    c = &str[0];

    strlwr(c);

    return c;
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

    clearString(codigo);
    clearString(nome);
    clearString(end);
    clearString(telefone);
    clearString(data);
    clearString(desig);
    clearString(salario);
    clearString(sup);
    clearString(acad);
    clearString(formacao);

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
        cout << "Endereco nao encontrado" << endl;
        Sleep(5000);
        return "Nan";
    }

    system("del index.html");

    return "Logradouro: " + forEndereco(linhasAPI, 2, 17) + " - " "Bairro: " + forEndereco(linhasAPI, 4, 13) + " - " + "Cidade: " + forEndereco(linhasAPI, 5, 17) + " - " + "UF: " + forEndereco(linhasAPI, 6, 9);

}

void GerenciaArquivo::calculaDescontos(double sa[]){

    for(int i = 0; i < tamArq-1; i++){
        if(linhas[i] != ""){
            if(getSalario(i) != ""){
                if(sa[i] <= 1212){
                    inss[i] = (sa[i]*(7.5/100));
                    salarioLiquido[i] = sa[i] - (sa[i]*(7.5/100));
                }else if(sa[i] <= 2427.35){
                    inss[i] = (((sa[i] - 1212.01)*(9*1.0/100))+90.90);
                    salarioLiquido[i] = sa[i] - (((sa[i] - 1212.01)*(9*1.0/100))+90.90);
                }else if(sa[i] <= 3641.03){
                    inss[i] = (((sa[i]-2427.36)*(12*1.0/100))+200.28);
                    salarioLiquido[i] = sa[i] - (((sa[i]-2427.36)*(12*1.0/100))+200.28);  
                }else if(sa[i] <= 7087.22){
                    inss[i] = (((sa[i]-3641.04)*(14*1.0/100))+345.92);
                    salarioLiquido[i] = sa[i] - (((sa[i]-3641.04)*(14*1.0/100))+345.92);
                }else if((sa[i] >= 7087.23)){
                    inss[i] = 828.38;
                    salarioLiquido[i] = sa[i] - 828.38;
                }
            }else
                break;
        }
    }

    for(int i = 0; i < tamArq-1; i++){
        if(linhas[i] != ""){
            if(getSalario(i) != ""){
                if(salarioLiquido[i] <= 1903.98){
                    irrf[i] = 0;
                }else if(salarioLiquido[i] <= 2826.65){
                    irrf[i] = ((salarioLiquido[i]*(7.5/100))-142.80);
                    salarioLiquido[i] = salarioLiquido[i] - ((salarioLiquido[i]*(7.5/100))-142.80);
                }else if(salarioLiquido[i] <= 3751.05){
                    irrf[i] = ((salarioLiquido[i]*(15*1.0/100))-354.80);
                    salarioLiquido[i] = salarioLiquido[i] - ((salarioLiquido[i]*(15*1.0/100))-354.80);
                }else if(salarioLiquido[i] <= 4664.68){
                    irrf[i] = ((salarioLiquido[i]*(22.5*1.0/100))-636.13);
                    salarioLiquido[i] = salarioLiquido[i] - ((salarioLiquido[i]*(22.5*1.0/100))-636.13);     
                }else if(salarioLiquido[i] >= 4664.69){
                    irrf[i] = ((salarioLiquido[i]*(27.5/100))-869.36);
                    salarioLiquido[i] = salarioLiquido[i] - ((salarioLiquido[i]*(27.5/100))-869.36);
                }
            }else
                break;
        }
    }
}


void GerenciaArquivo::limpaArraySalario(){
    fill_n(salarioBruto, TAM, 0);
    fill_n(inss, TAM, 0);
    fill_n(irrf, TAM, 0);
    fill_n(salarioLiquido, TAM, 0);
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

void GerenciaArquivo::buscaPorNome(){
    int c = 0; //controle
    int encontrado = 0; //contador de funcionarios foram encontrados
    string endereco[TAM];//auxiliar para end[i]
    string busca;
    string opcao;
    
    colunas();

    while(1){
        c = 0; //zerando controle
        encontrado = 0; //zerando contador

        cout << "Buscar: ";
        getline(cin, busca);

        busca = transformaStringMin(busca);
        
        system("cls");

        for (int i = 0; i < TAM; i++){
            //Encontrando a "busca" em minusculo, já que todos os nomes de funcionarios do arquivo estarão em minúsculo 
            if (nome[i].find(busca) != string::npos){
                endereco[i] = end[i];
                endereco[i] = endereco[i].erase(0, 12);//Para o endereco aparecer a partir de "Rua"

                cout << "\n";

                cout << "Codigo..........: " << codigo[i] << endl;
                cout << "Nome............: " << nome[i] << endl;
                cout << "Endereco........: " << endereco[i] << endl; //exibir só a partir de "Rua"
                cout << "Telefone........: " << telefone[i] << endl;
                cout << "Data de ingresso: " << data[i] << endl;
                cout << "Designacao......: " << desig[i] << endl;
                
                c = 1; //controle para gerenciar corretamente os laços de repetição
                encontrado++; //incrementa a quantidade de funcionarios encontrados
            }
        }

        if (c == 1){
            cout << "\n";
            cout << encontrado << " funcionario(s) encontrado(s) com \"" << busca << "\" no nome" << endl << endl;

            break;

        } else {
            while(1){
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

                } else {
                    system("cls"); 

                    cout << "Opcao invalida! Tente novamente" << endl << endl;
                    continue;
                }
            }

            //Para controlar corretamente os laços de repetição
            if (c == 1){
                continue; //Vai para o inicio do while
            }
            else if (c == 2){                
                break; //Sai do while    
            }
        }
    }
}

void GerenciaArquivo::buscaPorData(){   
    typedef struct{
        int diaIni, diaFi;
        int mesIni, mesFi;
        int anoIni, anoFi;
    } tData;

    string dInicial, mInicial, aInicial; //dia, mes e ano iniciais do intervalo de tempo
    string dFinal, mFinal, aFinal; //dia, mes e ano finais do intervalo de tempo
    string dataInicial, dataFinal; //auxiliares
    string endereco[TAM];//auxiliar para end[i]
    string dia[TAM], mes[TAM], ano[TAM];
    string auxMes, auxDia, auxAno, busca, opcao;
    tData dt;
    int c1 = 0, c2 = 0, c3 = 0; //controles para auxiliar nos laços de repetição
    int encontrado = 0; //contador de funcionarios encontrados

    colunas();

    while(1){
        c1 = 0; //zerando os controles
        c2 = 0; 
        c3 = 0;
        encontrado = 0; //zerando contador

        while(1){
            c1 = 0;

            cout << "Intervalo de tempo, a partir das datas de ingresso:\n" << endl;
        
            cout << "\tDia inicial: ";
            cin >> dt.diaIni;
            cout << "\tMes inicial: ";
            cin >> dt.mesIni;
            cout << "\tAno inicial: ";
            cin >> dt.anoIni;

            if (to_string(dt.diaIni).length() == 1){
                dInicial = "0" + to_string(dt.diaIni);
            }
            else if (to_string(dt.diaIni).length() == 2){
                dInicial = to_string(dt.diaIni);
            }
            if (to_string(dt.mesIni).length() == 1){
                mInicial = "0" + to_string(dt.mesIni);
            }
            else if(to_string(dt.mesIni).length() == 2){
                mInicial = to_string(dt.mesIni);
            }
            if(to_string(dt.anoIni).length() == 2){
                aInicial = "19" + to_string(dt.anoIni);
            }
            else if(to_string(dt.anoIni).length() == 4){
                aInicial = to_string(dt.anoIni);
            }
            else{
                aInicial = "0";
            }

            if(stoi(mInicial) < 1 || stoi(mInicial) > 12){
                system("cls");
                cout << "data invalida" << endl;
                
                c1 = 1;
            }
            
            if(stoi(aInicial) < 1000 || stoi(aInicial) > 2022){
                system("cls");
                cout << "data invalida" << endl;

                c1 = 1;
            }

            if(stoi(mInicial)){
                if(stoi(mInicial) == 2){
                    if(dt.diaIni <= 28 && dt.diaIni > 1){
                        c1 = 2;
                    }else{
                        system("cls");
                        cout << "dia do mes invalido" << endl;

                        c1 = 1;
                    }
                }
            
                if(stoi(mInicial) == 1 || stoi(mInicial) == 3|| stoi(mInicial) == 5 || stoi(mInicial) == 7 || 
                stoi(mInicial) == 8 || stoi(mInicial) == 10 || stoi(mInicial) == 12){

                    if(stoi(dInicial) <= 31 && stoi(dInicial) >= 1){
                        c1 = 2;
                    }else{
                        system("cls");
                        cout << "dia do mes invalido" << endl;

                        c1 = 1;
                    }
                }

                else{
                    if(stoi(dInicial) <= 30 && stoi(dInicial) >= 1){
                        c1 = 2;
                    }else{
                        system("cls");
                        cout << "dia do mes invalido" << endl;

                        c1 = 1;
                    }
                }
            } 

            //Para controlar corretamente os laços de repetição
            if (c1 == 1){
                continue; //Vai para o inicio do while
            }
            else if (c1 == 2){                
                break; //Sai do while    
            }
        }

        cout << "\n"; 

        while(1){
            c2 = 0; 

            cout << "\tDia final: ";
            cin >> dt.diaFi;
            cout << "\tMes final: ";
            cin >> dt.mesFi;
            cout << "\tAno final: ";
            cin >> dt.anoFi;

            if (to_string(dt.diaFi).length() == 1){
                dFinal = "0" + to_string(dt.diaFi);
            }
            else if (to_string(dt.diaFi).length() == 2){
                dFinal = to_string(dt.diaFi);
            }
            if (to_string(dt.mesFi).length() == 1){
                mFinal = "0" + to_string(dt.mesFi);
            }
            else if(to_string(dt.mesFi).length() == 2){
                mFinal = to_string(dt.mesFi);
            }
            if(to_string(dt.anoFi).length() == 2){
                aFinal = "19" + to_string(dt.anoFi);
            }
            else if(to_string(dt.anoFi).length() == 4){
                aFinal = to_string(dt.anoFi);
            }
            else{
                aFinal = "0";
            }

            if(stoi(mFinal) < 1 || stoi(mFinal) > 12){
                system("cls");
                cout << "data invalida" << endl;
                
                c2 = 1;
            }
            
            if(stoi(aFinal) < 1000 || stoi(aFinal) > 2022){
                system("cls");
                cout << "data invalida" << endl;
                
                c2 = 1;
            }

            if(stoi(mFinal)){
                if(stoi(mFinal) == 2){
                    if(dt.diaFi <= 28 && dt.diaFi > 1){
                        c2 = 2;
                    }else{
                        system("cls");
                        cout << "dia do mes invalido" << endl;
                        
                        c2 = 1;
                    }
                }
            
                if(stoi(mFinal) == 1 || stoi(mFinal) == 3|| stoi(mFinal) == 5 || stoi(mFinal) == 7 || 
                stoi(mFinal) == 8 || stoi(mFinal) == 10 || stoi(mFinal) == 12){

                    if(stoi(dFinal) <= 31 && stoi(dFinal) >= 1){
                        c2 = 2;
                    }else{
                        system("cls");
                        cout << "dia do mes invalido" << endl;
                        
                        c2 = 1;
                    }
                }

                else{
                    if(stoi(dFinal) <= 30 && stoi(dFinal) >= 1){
                        c2 = 2;
                    }else{
                        system("cls");
                        cout << "dia do mes invalido" << endl;
                        
                        c2 = 1;
                    }
                }
            }

            //Para controlar corretamente os laços de repetição
            if (c2 == 1){
                continue; //Vai para o inicio do while
            }
            else if (c2 == 2){                
                break; //Sai do while    
            }
        }

        system("cls");

        // Datas iniciais e finais em string "dia/mes/ano"
        dataInicial = dInicial + "/" + mInicial + "/" + aInicial;
        dataFinal = dFinal + "/" + mFinal + "/" + aFinal;

        // Imprimir apenas as informações dos funcionários que ingressaram no intervalo de tempo escolhido
        // Além disso, só imprime se a linha do arquivo estiver preenchida
        for (int i = 0; i < TAM; i++){
            endereco[i] = end[i];
            endereco[i] = endereco[i].erase(0, 12); //Para o endereco aparecer a partir de "Rua"

            if (data[i].length() == 10){
                auxDia = data[i];
                dia[i] = auxDia.substr(0, 2); //dia[i] recebe somente o dia da string data[i]

                auxMes = data[i];
                mes[i] = auxMes.substr(3, 2); //mes[i] recebe somente o mes da string data[i]

                auxAno = data[i];
                ano[i] = auxAno.substr(6, 4); //ano[i] recebe somente o ano da string data[i]

                if (stoi(ano[i]) > stoi(aInicial) && stoi(ano[i]) < stoi(aFinal)){

                    cout << "\n";

                    cout << "Codigo..........: " << codigo[i] << endl;
                    cout << "Nome............: " << nome[i] << endl;
                    cout << "Endereco........: " << endereco[i] << endl;
                    cout << "Telefone........: " << telefone[i] << endl;
                    cout << "Data de ingresso: " << data[i] << endl;
                    cout << "Designacao......: " << desig[i] << endl;
                
                    encontrado++; //incrementa a quantidade de funcionarios encontrados
                }
                else if (stoi(ano[i]) == stoi(aInicial) || stoi(ano[i]) == stoi(aFinal)){

                    if (stoi(mes[i]) > stoi(mInicial) && stoi(mes[i]) < stoi(mFinal)){

                        cout << "\n";

                        cout << "Codigo..........: " << codigo[i] << endl;
                        cout << "Nome............: " << nome[i] << endl;
                        cout << "Endereco........: " << endereco[i] << endl;
                        cout << "Telefone........: " << telefone[i] << endl;
                        cout << "Data de ingresso: " << data[i] << endl;
                        cout << "Designacao......: " << desig[i] << endl;
                
                        encontrado++; //incrementa a quantidade de funcionarios encontrados
                    }
                    else if (stoi(mes[i]) == stoi(mInicial) || stoi(mes[i]) == stoi(mFinal)){

                        if (stoi(dia[i]) >= stoi(dInicial) && stoi(dia[i]) <= stoi(dFinal)){
                        
                            cout << "\n";

                            cout << "Codigo..........: " << codigo[i] << endl;
                            cout << "Nome............: " << nome[i] << endl;
                            cout << "Endereco........: " << endereco[i] << endl;
                            cout << "Telefone........: " << telefone[i] << endl;
                            cout << "Data de ingresso: " << data[i] << endl;
                            cout << "Designacao......: " << desig[i] << endl;
                
                            encontrado++; //incrementa a quantidade de funcionarios encontrados
                        }
                    } 
                }
            }
        }
    
        if (encontrado > 0){
            cout << "\n";

            cout << encontrado << " funcionario(s) encontrado(s), que ingressaram na empresa entre " << dataInicial
            << " e " << dataFinal << endl << endl;

            break;

        } else {
            while(1){
                getchar(); //"limpa enter" da data final digitada

                cout << "Nenhum funcionario encontrado. Gostaria de tentar novamente? [s/n]" << endl;
                getline(cin, opcao);

                if (opcao == "s" || opcao == "S"){    
                    system("cls");
                    c3 = 1;
                    break;
                }
                else if (opcao == "n" || opcao == "N"){
                    system("cls");
                    c3 = 2;
                    break;

                } else {
                    system("cls"); 

                    cout << "Opcao invalida! Tente novamente" << endl << endl;
                    continue;
                }
            }

            //Para controlar corretamente os laços de repetição
            if (c3 == 1){
                continue; //Vai para o inicio do while
            }
            else if (c3 == 2){                
                break; //Sai do while    
            }
        }
    }
}

void GerenciaArquivo::buscaPorEndereco(){
    int c = 0; //controle
    int encontrado = 0; //contador de quantos funcionarios foram encontrados
    string endereco[TAM]; //auxiliar para end[i]
    string busca;
    string opcao, string1, string2; //duas strings auxiliares para tratar a questão de letras minúsculas

    colunas();

    while(1){
        c = 0; //zerando controle
        encontrado = 0; //zerando contador

        cout << "Buscar: ";
        getline(cin, busca);

        busca = transformaStringMin(busca);
        
        system("cls");

        for (int i = 0; i < TAM; i++){
            endereco[i] = end[i];
            endereco[i] = endereco[i].erase(0, 12); //Para o endereco aparecer a partir de "Rua"

            //Deixa o endereco em minusculo para poder realizar a busca em minusculo também
            string1 = endereco[i];
            string2 = transformaStringMin(string1);

            if (string2.find(busca) != string::npos){
                cout << "\n";

                cout << "Codigo..........: " << codigo[i] << endl;
                cout << "Nome............: " << nome[i] << endl;
                cout << "Endereco........: " << endereco[i] << endl;
                cout << "Telefone........: " << telefone[i] << endl;
                cout << "Data de ingresso: " << data[i] << endl;
                cout << "Designacao......: " << desig[i] << endl;
                
                c = 1; //controle para gerenciar corretamente os laços de repetição
                encontrado++; //incrementa a quantidade de funcionarios encontrados
            }
        }

        if (c == 1){
            cout << "\n";
            cout << encontrado << " funcionario(s) encontrado(s) com \"" << busca << "\" no endereco" << endl << endl;

            break;

        } else {
            while(1){
                cout << "Nenhum funcionario encontrado. Gostaria de tentar novamente? [s/n]" << endl;
                getline(cin, opcao);

                //getchar(); // Vai precisar?

                if (opcao == "s" || opcao == "S"){    
                    system("cls");
                    c = 1;
                    break;
                }
                else if (opcao == "n" || opcao == "N"){
                    system("cls");
                    c = 2;
                    break;

                } else {
                    system("cls"); 

                    cout << "Opcao invalida! Tente novamente" << endl << endl;
                    continue;
                }
            }

            //Para controlar corretamente os laços de repetição
            if (c == 1){
                continue; //Vai para o inicio do while
            }
            else if (c == 2){                
                break; //Sai do while    
            }
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

        for(int i = 1; i < TAM; i++){
            if(linhas[i] != ""){
                aux = linhas[i];
                aux.erase(3, aux.length());
            }

            //verificando o novo codigo digitado para que nao seja possivel dois ou mais codigos iguais
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

            linhas[cont+1] = modificacao + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
            + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont];

            cont = 0;
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < TAM; i++){
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

            linhas[cont+1] = codigo[cont] + "," + transformaStringMin(modificacao) + "," + end[cont]
            + "," + telefone[cont] + "," + data[cont] + "," + desig[cont] + "," + salario[cont] + ","
            + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 

            cont = 0;
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < TAM; i++){
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
            cout << "Digite o novo CEP - formato (00000000): ";
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

            linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + modificacao + "," + telefone[cont] + "," + data[cont]
            + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 

            cont = 0;
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < TAM; i++){
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

    cout << "Digite o novo telefone - formato: (00) 00000-0000: ";
    getline(cin, modificacao);

    system("cls");

    while(1){
        if (codigo[cont].find(cod) != string::npos){

            linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + modificacao + "," + data[cont]
            + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," + acad[cont] + "," + formacao[cont]; 

            cont = 0;
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < TAM; i++){
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

            linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
            + dia + "/" + mes + "/" + ano + "," + desig[cont] + "," + salario[cont] + "," + sup[cont] + "," 
            + acad[cont] + "," + formacao[cont];  
            
            cont = 0;
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < TAM; i++){
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

                        linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] +
                        "," + data[cont] + "," + desig[cont] + "," + modificacao + "," + sup[cont] + "," +
                        acad[cont] + "," + formacao[cont]; 

                    } else {

                        linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] +
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

            for(int i = 0; i < TAM; i++){
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

            linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + "," + data[cont]
            + "," + modificacao + "," + salario[cont] + "," + "Nan" + "," + "Nan" + "," + "Nan"; 
            
            cont = 0;
            
            break; 
                    
        } else {
            cont++;
        }    
    }

    arquivo.open("./csv/Empresa.csv", ios::out);

    for(int i = 0; i < TAM; i++){
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

                    linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + areaF + ","
                    + formacao[cont]; 

                    cont = 0;
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < TAM; i++){
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

                    linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + "Nan" + "," + areaF + ","
                    + formacaoMax;

                    cont = 0;
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < TAM; i++){
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

                    linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + acad[cont] + ","
                    + formacao[cont]; 

                    cont = 0;
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < TAM; i++){
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

                    linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + areaF + ","
                    + formacao[cont];

                    cont = 0;
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < TAM; i++){
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

                    linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + sup[cont] + "," + areaF + ","
                    + formacaoMax;

                    cont = 0;
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < TAM; i++){
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

                    linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + "Nan" + ","
                    + formacao[cont]; 

                    cont = 0;
            
                    break; 
                    
                } else {
                    cont++;
                }    
            }       

            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < TAM; i++){
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

                    linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + "Nan" + "," + areaF + ","
                    + formacaoMax; 
    
                    cont = 0;
                    break; 
                } else {
                    cont++;
                }    
            }       

            arquivo.open("./csv/Empresa.csv", ios::out);

            for(int i = 0; i < TAM; i++){
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

                    linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + "Nan" + "," + "Nan";
    
                    cont = 0;     
                    break;     
                } else {
                    cont++;
                }    
            }       

            arquivo.open("./csv/Empresa.csv", ios::out);
            for(int i = 0; i < TAM; i++){
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

                    linhas[cont+1] = codigo[cont] + "," + nome[cont] + "," + end[cont] + "," + telefone[cont] + ","
                    + data[cont] + "," + modificacao + "," + salario[cont] + "," + areaS + "," + areaF + "," + "Nan"; 
    
                    cont = 0;
                    break;      
                } else {
                    cont++;
                }    
            }       
            arquivo.open("./csv/Empresa.csv", ios::out);
            for(int i = 0; i < TAM; i++){
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
