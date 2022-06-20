#include <iostream>
#include <fstream>
#include <string>
#include <string.h>


/**
 *  TAM é o tamanho utilizado nos arrays dos atributos do programa, que é 100. Diretiva muito útil, permitindo
 *  dar um nome a um valor constante antes de o programa ser compilado.
 *  \def
*/
#define TAM 100


#ifndef GERENCIAARQUIVO_H
#define GERENCIAARQUIVO_H

using namespace std;

/** 
 *  Classe utilizada para o gerenciamento dos dados dos funcionários no arquivo csv.
 *  \class
*/
class GerenciaArquivo
{
public:
    GerenciaArquivo();
    ~GerenciaArquivo();

    /** 
     *  Método que apaga uma string, tornando-a vazia. Possui um parâmetro.
     *  \param *str um ponteiro do tipo string que aponta para a string que será apagada.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void clearString(string *str);

    /** 
     *  Um método que transforma uma string qualquer em outra, mas agora contendo apenas letras minúsculas.
     *  Possui um parâmetro.
     *  \param str uma variável do tipo string, a ser modificada.
     *  \return string, retorna a string modificada.
     *  \author Lucas Bitu
    */
    string transformaStringMin(string str);

    /** 
     *  Um método que verifica se uma string inserida possui apenas caracteres numéricos. Possui um parâmetro.
     *  \param &str endereço de uma variável do tipo const string, a ser verificada.
     *  \return bool, retorna verdadeiro se só houver números na string recebida, caso contrário, retorna falso. 
     *  \author Lucas Bitu
    */
    bool isNumber(const string& str);

    /** 
     *  Método para criação do arquivo csv onde ficarão os dados dos funcionários. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void criarArquivo();

    /** 
     *  Método para leitura do arquivo csv onde ficarão os dados dos funcionários. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void lerArquivo();

    /** 
     *  Um método utilizado para a exibição dos dados dos funcionários. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void exibirArquivo();

    /** 
     *  Método para auxiliar na obtenção dos dados dos funcionários, a partir do arquivo csv. Possui dois parâmetros.
     *  \param colunaAtual[] elemento de um array do tipo string.
     *  \param del[] elemento de um array do tipo inteiro.
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void separadorColuna(string colunaAtual[], int del[]);

    /** 
     *  Método responsável por obter os dados salvos no arquivo csv, "guardando-os" separadamente em cada array do tipo
     *  string, que são, justamente, grande parte dos atributos da classe "GerenciaArquivo". Não possui parâmetros.  
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda
    */
    void colunas();

    /** 
     *  Um método que faz uso da API presente em "http://viacep.com.br" para, a partir de um CEP informado, obter
     *  o endereço de um funcionário(a). Possui um parâmetro.
     *  \param cep variável do tipo string a ser recebida.
     *  \return string, retorna uma string com o endereço.
     *  \author Êmilly Eduarda
    */
    string retornaEndereco(string cep);

    /** 
     *  Método para auxiliar no processo de obtenção do endereço de um funcionário(a) pela API. Possui três parâmetros.
     *  \param api[] elemento de um array do tipo string.
     *  \param line variável do tipo inteiro.
     *  \param tam variável do tipo inteiro. 
     *  \return string, retorna as partes do endereço para auxiliar no método "retornaEndereco(string cep)".
     *  \author Êmilly Eduarda
    */
    string forEndereco(string api[], int line, int tam);

    /** 
     *  Um método que gera números aletórios de dias trabalhados pelos funcionários, dependendo de um mês informado.
     *  Possui um parâmetro.
     *  \param m variável do tipo double, mês em que a folha salarial vai ser calculada.
     *  \return double, retorna a quantidade de dias trabalhados em determinado mês.
     *  \author Lucas Bitu
    */
    double geraDiasTrabalhados(double m);

    /** 
     *  Este método gera números aletórios de horas extras feitas pelos funcionários, dependendo de um mês informado.
     *  Possui um parâmetro.
     *  \param m variável do tipo double, mês em que a folha salarial vai ser calculada.
     *  \return double, retorna a quantidade de horas extras feitas em determinado mês.
     *  \author Lucas Bitu
    */
    double geraHorasExtras(double m);

    /** 
     *  Método responsável por calcular os descontos no salário dos funcionários, relativos ao imposto de renda
     *  e previdência social. Possui um parâmetro.
     *  \param sa[] elemento de um array do tipo double, salário a ser descontado.
     *  \return void, não possui retorno.
     *  \author Lucas Bitu
    */
    void calculaDescontos(double sa[]);

    /** 
     *  Método utilizado para limpar o array que armazena os salários dos funcionários. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Lucas Bitu
    */
    void limpaArraySalario();
    
    /** 
     *  Método para realizar a busca parcial de funcionários pelo nome. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void buscaPorNome();

    /** 
     *  Método que realiza a busca parcial de funcionários pelo intervalo de tempo entre as datas em que os mesmos
     *  ingressaram na empresa. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void buscaPorData();

    /** 
     *  Método que realiza a busca parcial de funcionários pelo endereço. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void buscaPorEndereco();

    /** 
     *  A partir do código atual de um funcionário(a), este método modifica esse código para um novo, salvando a
     *  modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, código atual do funcionário(a).
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void modificaCodigo(string cod);

    /** 
     *  A partir do código de um funcionário(a), este método modifica o nome do mesmo, salvando a modificação
     *  no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, código do funcionário(a).
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void modificaNome(string cod);

    /** 
     *  Um método que, a partir do código de um funcionário(a), modifica o endereço do mesmo, salvando a modificação
     *  no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, código do funcionário(a).
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void modificaEndereco(string cod);

    /** 
     *  Tal método, a partir do código de um funcionário(a), modifica o telefone do mesmo, salvando a modificação no
     *  arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, código do funcionário(a).
     *  \return void, não possui retorno.
     *  \author Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void modificaTelefone(string cod);

    /** 
     *  Um método que, a partir do código de um funcionário(a), modifica a data de ingresso do mesmo, salvando a modificação
     *  no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, código do funcionário(a).
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void modificaData(string cod);

    /** 
     *  A partir do código de um funcionário(a), o método modifica o salário do mesmo, salvando a modificação no arquivo csv.
     *  Possui um parâmetro.
     *  \param cod variável do tipo string, código do funcionário(a).
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void modificaSalario(string cod);

    /** 
     *  Método que, a partir do código de um funcionário(a), modifica a designação do mesmo, salvando tal modificação no
     *  arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, código do funcionário(a).
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void modificaDesignacao(string cod);

    /** 
     *  Um método auxiliar para o método "modificaDesignacao(string cod)". Modifica a designação de um Operador, salvando
     *  tal modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, código do funcionário(a).
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda, Lucas Bitu e Igor Matheus
     */
    void modDesigDeOperador(string cod);

    /** 
     *  Um método auxiliar para o método "modificaDesignacao(string cod)". Modifica a designação de um Gerente e salva tal
     *  modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, código do funcionário(a).
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void modDesigDeGerente(string cod);

    /** 
     *  Método auxiliar para o método "modificaDesignacao(string cod)". Modifica a designação de um Diretor e salva tal
     *  modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, código do funcionário(a).
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void modDesigDeDiretor(string cod);

    /** 
     *  Método auxiliar para o método "modificaDesignacao(string cod)". Modifica a designação de um Presidente, salvando tal
     *  modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, código do funcionário(a).
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void modDesigDePresidente(string cod);

    /** 
     *  Um método auxiliar capaz de modificar a designação de um Gerente, Diretor ou Presidente, para um Operador, salvando essa
     *  modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, código do funcionário(a).
     *  \return void, não possui retorno.
     *  \authors Êmilly Eduarda, Lucas Bitu e Igor Matheus
    */
    void modDesigParaOperador(string cod);

    string getCodigo(int i);
    string getNome(int i);
    string getEnd(int i);
    string getTelefone(int i);
    string getData(int i);
    string getDesig(int i);
    string getSalario(int i);
    string getSup(int i);
    string getAcad(int i);
    string getFormacao(int i);
    string getLinhas(int i);
    
protected:

    /// arquivo é um atributo do tipo fstream que representa o arquivo csv dos dados dos funcionários.
    fstream arquivo;

    /// tamArq é um atributo do tipo int e se refere ao tamanho do arquivo. 
    int tamArq; 

    /** 
     *  Atributos do tipo string, sendo: linhas[TAM] um array para armazenar as linhas do arquivo csv;
     *  e Nan um atributo que armazena a string "Nan".
     *  \var 
    */
    string linhas[TAM], Nan = {"Nan"};; 

    /** 
     *  Atributos do tipo string que armazenam, em arrays, os principais dados dos funcionários:
     *  codigo, nome, endereço, telefone, data, designação, salário, área de supervisão, formação acadêmica e
     *  formação acadêmica máxima.
     *  \var 
    */
    string codigo[TAM], nome[TAM], end[TAM], telefone[TAM], data[TAM], desig[TAM],salario[TAM],sup[TAM],acad[TAM],formacao[TAM];
    
    /** 
     *  Atributos do tipo double que armazenam os dados, em arrays, sobre o salário bruto, salário líquido, impostos do INSS e IRRF;
     *  e, em uma variável, armazena os dados sobre o montante salarial da empresa.  
     *  \var 
    */
    double salarioBruto[TAM],inss[TAM],irrf[TAM],salarioLiquido[TAM], salarioEmpresa;

};

#endif
