# Caverna - PAA

Repositório dedicado para implementação do trabalho prático 2 de CCF 330 (Projeto e Análise de Algoritmos) 

## Índice

- [Sobre](#sobre)
- [Como Usar](#como-usar)
- [Comandos Disponíveis](#comandos-disponíveis)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Licença](#licença)

---

## Sobre

Trata-se de um software voltado a resolver um problema ludico usando um paradigma de Programação Dinâmica 

---

## Como Usar

### Requisitos

- [gcc](https://gcc.gnu.org/) instalado
- [Make](https://www.gnu.org/software/make/) para gerenciamento de build.
- ambos acima configurado no ambiente
- Recomenda-se fortemente o uso de sistemas Linux ou Mac 

### Passo a Passo

1. Clone o repositório:
   ```bash
   git clone git@github.com:Eufrausino/Cavernas-PAA.git
 
 apos o comando terá em sua máquina o software instalado, caso não tenha git em seu computador poderá apenas baixar o .zip do proejto no link:

2. link para dowload direto. 
    ```bash 
    https://github.com/Eufrausino/Cavernas-PAA

---


## Comandos Disponíveis
### Regras Principais 

Neste softare não temos uma intefarce, fazendo com que sua ultilização seja inteiramente por linha de comando. 

Atravez do Makefile podemos apenas digitar no terminal os comandos: 

#### Comandos pra Main:
**`make compile`**: compila o programa principal

**`make run`**: executa o programa principal, porem se executado sem a definição das variaveis, tal executará com as variaveis de defout ( sendo essas as padroẽs que executarão o arquivo de exemplo)

**`make run MAPA=<nome_do_mapa>`**: execeturá o programa com o mapa defido. 

**`make all`**: compilará e executará , podendo tambem colocar o mapa como argumento como comando. 
#### Comandos para Criar Arquivo:
**`make criarArquivo`**:  compilará e executará um Programa que cria um arquivo de entrada, onde se nao esqpecificado suas varieveis terá-las defindas como defalt: NOME= mapaCriado, LINHA= 10,COLUNA=10 ,VIDA= 100.

**`make criarArquivo NOME=<string> LINHA=<int>,COLUNA=<int> ,VIDA=<int>`**: compilará e executará, criando um arquivo dentro da pasta Lib/ com as variaveis definidas em linha de comando. 

#### Comandos de Teste Modular:

Desenvolvemos todo Software de formula modular, portanto podemos compilar e executa-los de maneira isolada e com "inteface" para testes, sendo os comando seguintes os necessários:

**`make files`**: Para ter acesso ao modulo de Arquivos

**`make pg`**: Para ter acesso ao modulo de Programação Dinâmica

## Estrutura do Projeto

├── Headers/  
│   ├── arquivo.h  
│   ├── mapa.h  
│   └── progDinamica.h  
├── Src/  
│   ├── criador.c  
│   ├── arquivo.c  
│   ├── mapa.c  
│   └── progDinamica.c  
├── Test/  
│   ├── arquivo_teste.c  
│   ├── prog_dinamica_teste.c  
│   └── menu_teste.c  
├── Lib/  
│   └── (mapas em formato .txt)  
├── Out/  
│   └── (arquivos gerados e executáveis)  
├── Makefile  
└── README.md  

---
## Licença

Nosso Software tem liceça MIT, ou seja ... podem copiar 
