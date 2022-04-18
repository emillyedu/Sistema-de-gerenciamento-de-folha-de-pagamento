# anotações

função gera valores aleatorios: <random>
    
pedir cep e nº da casa e retornar endereço completo do funcionario:
    viCep: coloca cep no link (viacep.com.br/ws/01001000/json/) - requisição - solicitar download do json - arquivo- pega values.
        system - wget (comando) - baixa json
        browser - baisar json
  
        string cep =  "456789"
        string url = "https..." + cep + "/json/"
        string comando = "wget" + url
        system(comando.c_string()); <!-- baixa arq json -->

        entrar, ler arq...
