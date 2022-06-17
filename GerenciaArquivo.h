#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

/*! \brief Descrição mais curta do programa:
 *  Esse programa se trata de ... .
 *
 *  Descrição mais detalhada....
 *  
*/

/*! 
 *  \def TAM é o tamanho utilizado nos arrays dos atributos do programa, que é 100. Diretiva muito útil, permitindo
 *  dar um nome a um valor constante antes de o programa ser compilado.
*/
#define TAM 100


#ifndef GERENCIAARQUIVO_H
#define GERENCIAARQUIVO_H

using namespace std;

/*! Classe utilizada para o gerenciamento dos dados dos funcionários no arquivo csv.
 *  \class
*/
class GerenciaArquivo
{
public:
    GerenciaArquivo();
    ~GerenciaArquivo();

    /*! Método que apaga uma string, tornando-a vazia. Possui um parâmetro.
     *  \param *str um ponteiro do tipo string que aponta para uma string qualquer, a fim de realizar a função do método.
     *  \return void, não possui retorno.
     *  \author ???
    */
    void clearString(string *str);

    /*! Um método que transforma uma string qualquer em outra, mas agora contendo apenas letras minúsculas.
     *  Possui um parâmetro.
     *  \param str uma variável do tipo string, a ser modificada.
     *  \return string, retorna a string com todas as letras minúsculas.
     *  \author ???
    */
    string transformaStringMin(string str);

    /*! Método utilizado para criar o arquivo csv onde ficarão os dados dos funcionários. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly
    */
    void criarArquivo();

    /*! Método utilizado para ler o arquivo csv onde ficarão os dados dos funcionários. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly
    */
    void lerArquivo();

    /*! Um método utilizado para a exibição dos dados dos funcionários. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Êmilly
    */
    void exibirArquivo();

    /*! Método para auxiliar na obtenção dos dados dos funcionários, a partir do arquivo csv. Possui dois parâmetros.
     *  \param colunaAtual[] elemento de um array do tipo string, funcionando como uma referência para realização
     *  da função do método.
     *  \param del[] elemento de um array do tipo inteiro, também funcionando como uma referência para realização
     *  da função do método.
     *  \return void, não possui retorno.
     *  \author Êmilly
    */
    void separadorColuna(string colunaAtual[], int del[]);

    /*! Este método é responsável por obter os dados dos funcionários, a partir do arquivo csv, "guardando-os"
     *  separadamente em cada array do tipo string, que são, justamente, grande parte dos atributos da classe
     *  "GerenciaArquivo". Não possui parâmetros.  
     *  \return void, não possui retorno.
     *  \author Êmilly
    */
    void colunas();

    /*! Um método que faz uso da API presente em "http://viacep.com.br" para, a partir de um CEP informado, obter
     *  o endereço de um funcionário(a). Possui um parâmetro.
     *  \param cep variável do tipo string a ser recebida, a fim de realizar a função do método.
     *  \return string, retorna uma string com o endereço do funcionário(a).
     *  \author Êmilly
    */
    string retornaEndereco(string cep);

    /*! Método para auxiliar no processo de obtenção do endereço de um funcionário(a) pela API. Possui três parâmetros.
     *  \param api[] elemento de um array do tipo string, funcionando como uma referência para obter determinada parte
     *  do endereço.
     *  \param line variável do tipo inteiro, representando também uma referência para obter determinada parte do
     *  endereço.
     *  \param tam variável do tipo inteiro, representando o tamanho do índice até onde a string do API deve ser
     *  apagada, a fim de gerar outra string com as partes certas do endereço. 
     *  \return string, retorna as partes do endereço para auxiliar no método "retornaEndereco(string cep)".
     *  \author Êmilly
    */
    string forEndereco(string api[], int line, int tam);

    /*! Um método que gera números aletórios de dias trabalhados pelos funcionários, dependendo de um mês informado.
     *  Possui um parâmetro.
     *  \param m variável do tipo double, representando o mês em que a folha salarial vai ser calculada.
     *  \return double, retorna a quantidade de dias trabalhados pelo funcionário(a) em determinado mês.
     *  \author Lucas Bitu
    */
    double geraDiasTrabalhados(double m);

    /*! Um método que gera números aletórios de horas extras feitas pelos funcionários, dependendo de um mês informado.
     *  Possui um parâmetro.
     *  \param m variável do tipo double, representando o mês em que a folha salarial vai ser calculada.
     *  \return double, retorna a quantidade de horas extras feitas pelo funcionário(a) em determinado mês.
     *  \author Lucas Bitu
    */
    double geraHorasExtras(double m);

    /*! Método responsável por calcular os descontos no salário dos funcionários, relativos ao imposto de renda
     *  e previdência social. Possui um parâmetro.
     *  \param sa[] elemento de um array do tipo double, representando o salário a ser descontado.
     *  \return void, não possui retorno.
     *  \author Lucas Bitu
    */
    void calculaDescontos(double sa[]);

    /*! Método utilizado para limpar o array que armazena os salários dos funcionários. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author ???
    */
    void limpaArraySalario();
    
    /*! Método que realiza a busca parcial de funcionários pelo nome dos mesmos. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void buscaPorNome();

    /*! Método que realiza a busca parcial de funcionários pelo intervalo de tempo entre as datas em que os mesmos
     *  ingressaram na empresa. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void buscaPorData();

    /*! Método que realiza a busca parcial de funcionários pelo endereço dos mesmos. Não possui parâmetros.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void buscaPorEndereco();

    /*! Um método que, a partir do código atual de um funcionário(a), é responsável por modificar esse código para
     *  um novo, salvando a modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, que recebe o código atual do funcionário(a), a fim de realizar a modificação
     *  no funcionário(a) correto.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void modificaCodigo(string cod);

    /*! Um método que, a partir do código de um funcionário(a), é responsável por modificar o nome do mesmo, salvando
     *  a modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, que recebe o código do funcionário(a), a fim de realizar a modificação
     *  do nome no funcionário(a) correto.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void modificaNome(string cod);

    /*! Um método que, a partir do código de um funcionário(a), é responsável por modificar o endereço do mesmo,
     *  salvando a modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, que recebe o código do funcionário(a), para realizar a modificação
     *  do endereço no funcionário(a) correto.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void modificaEndereco(string cod);

    /*! Um método que, a partir do código de um funcionário(a), é responsável por modificar o telefone do mesmo,
     *  salvando a modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, que recebe o código do funcionário(a), para realizar a modificação
     *  do telefone no funcionário(a) correto.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void modificaTelefone(string cod);

    /*! Um método que, a partir do código de um funcionário(a), é responsável por modificar a data de ingresso
     *  do mesmo, salvando a modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, que recebe o código do funcionário(a), a fim de realizar a modificação
     *  da data de ingresso no funcionário(a) correto.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void modificaData(string cod);

    /*! Método que, a partir do código de um funcionário(a), é responsável por modificar o salário do mesmo, salvando
     *  a modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, que recebe o código do funcionário(a), a fim de realizar a modificação
     *  do salário no funcionário(a) correto.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void modificaSalario(string cod);

    /*! Método que, a partir do código de um funcionário(a), é responsável por modificar a designação do mesmo,
     *  salvando tal modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, que recebe o código do funcionário(a), para realizar a modificação
     *  da designação no funcionário(a) correto.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void modificaDesignacao(string cod);

    /*! Um método auxiliar para o método "modificaDesignacao(string cod)". É responsável por modificar a designação
     *  de um Operador, salvando tal modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, que recebe o código do funcionário(a), para realizar a modificação
     *  da designação no funcionário(a) correto.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void modDesigDeOperador(string cod);

    /*! Um método auxiliar para o método "modificaDesignacao(string cod)". É responsável por modificar a designação
     *  de um Gerente, salvando tal modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, que recebe o código do funcionário(a), para realizar a modificação
     *  da designação no funcionário(a) correto.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void modDesigDeGerente(string cod);

   /*! Um método auxiliar para o método "modificaDesignacao(string cod)". É responsável por modificar a designação
     *  de um Diretor, salvando tal modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, que recebe o código do funcionário(a), para realizar a modificação
     *  da designação no funcionário(a) correto.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void modDesigDeDiretor(string cod);

    /*! Um método auxiliar para o método "modificaDesignacao(string cod)". É responsável por modificar a designação
     *  de um Presidente, salvando tal modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, que recebe o código do funcionário(a), para realizar a modificação
     *  da designação no funcionário(a) correto.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
    */
    void modDesigDePresidente(string cod);

    /*! Método auxiliar capaz de modificar a designação de qualquer funcionário(a) Gerente, Diretor ou Presidente,
     *  para um Operador, salvando tal modificação no arquivo csv. Possui um parâmetro.
     *  \param cod variável do tipo string, que recebe o código do funcionário(a), para realizar a modificação
     *  da designação no funcionário(a) correto.
     *  \return void, não possui retorno.
     *  \author Igor Matheus
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

    /*! Atributos do tipo string, sendo: linhas[TAM] um array de tamanho 100 para armazenar as linhas do arquivo csv;
     *  e Nan um atributo que armazena a string "Nan".
     *  \var
    */
    string linhas[TAM], Nan = {"Nan"};; 

    /*! Atributos do tipo string que armazenam, em arrays de tamanho TAM (100), os principais dados dos funcionários:
     *  codigo, nome, endereço, telefone, data, designação, salário, área de supervisão, formação acadêmica e
     *  formação acadêmica máxima.
     *  \var 
    */
    string codigo[TAM], nome[TAM], end[TAM], telefone[TAM], data[TAM], desig[TAM],salario[TAM],sup[TAM],acad[TAM],formacao[TAM];
    
    /*! Atributos do tipo double que armazenam os dados, em arrays de tamanho TAM (100), sobre o salário bruto,
     *  salário líquido, imposto do INSS, bem como do IRRF; E, em uma variável, armazena os dados sobre o salário
     *  da empresa.  
     *  \var 
    */
    double salarioBruto[TAM],inss[TAM],irrf[TAM],salarioLiquido[TAM], salarioEmpresa;

};

#endif
