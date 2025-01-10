#---------------------------Variáveis da Main------------------------------------
CC = gcc
MAIN_SRC = Src/main.c Src/arquivo.c Src/mapa.c Src/progDinamica.c 
MAIN_OUT = Out/exe
EXEC_MAIN = ./$(MAIN_OUT)
MAPA ?= mapa

#------------------------------Rules Principais----------------------------------------------
compile:
	$(CC) $(MAIN_SRC) -o $(MAIN_OUT)


run: 
	$(EXEC_MAIN) $(MAPA)

all: compile run



#----------------------------Variáveis de Testes----------------------------------
#Var Arquivos(FILE)
TEST_ARQUIVO = Test/arquivo_teste.c Src/arquivo.c Src/mapa.c
TEST_OUT_ARQUIVO = Out/arquivo_teste
EXEC_TEST_ARQUIVO = ./$(TEST_OUT_ARQUIVO)

#var ProgDinamamica
TEST_PROG_DINAMICA =  Test/prog_dinamica_teste.c  Src/progDinamica.c Src/arquivo.c Src/mapa.c
TEST_OUT_PROG_DINAMICA = Out/progDinam_teste
EXEC_TEST_PROG_DINAMICA = ./$(TEST_OUT_PROG_DINAMICA)




#-----------------------------Testes----------------------------------------------
files:
	$(CC) $(TEST_ARQUIVO) -o $(TEST_OUT_ARQUIVO)
	$(EXEC_TEST_ARQUIVO)


pd:
	$(CC) $(TEST_PROG_DINAMICA) -o $(TEST_OUT_PROG_DINAMICA)
	$(EXEC_TEST_PROG_DINAMICA)


#----------------------------Variáveis de Extra----------------------------------
#Criar Arquivo
CRIA_ARQUIVO = Src/criador.c Src/arquivo.c Src/mapa.c
SAIDA_CRIA_ARQUIVO = Out/criador
EXEC_CRIA_ARQUIVO = ./$(SAIDA_CRIA_ARQUIVO)

NOME ?= mapaCriado
LINHA ?= 10
COLUNA ?= 10
VIDA ?= 100

#ver Tempo de Execução
TEMPO_EXECUCAO = Src/tempoExecucao.c Src/arquivo.c Src/mapa.c Src/progDinamica.c
SAIDA_TEMPO_EXECUCAO = Out/tempo_execucao
EXEC_TEMPO_EXECUCAO = ./$(SAIDA_TEMPO_EXECUCAO)
#vou usar a variavel mapa que ja usa no programa principal 

#Nova Heuristica
NOVA_HEURISTICA = Src/novaHeuristica.c Src/arquivo.c Src/mapa.c Src/progDinamica.c
SAIDA_NOVA_HEURISTICA = Out/novaHeuristica
EXEC_NOVA_HEURISTICA = ./$(SAIDA_NOVA_HEURISTICA)
#vou usar a variavel mapa que ja usa no programa principal

#-----------------------------Rules Extras----------------------------------------------

criarArquivo:
	$(CC) $(CRIA_ARQUIVO) -o $(SAIDA_CRIA_ARQUIVO)
	$(EXEC_CRIA_ARQUIVO) $(NOME) $(LINHA) $(COLUNA) $(VIDA)

tempoExecucao:
	$(CC) $(TEMPO_EXECUCAO) -o $(SAIDA_TEMPO_EXECUCAO)
	$(EXEC_TEMPO_EXECUCAO) $(MAPA)

novaHeuristica:
	$(CC) $(NOVA_HEURISTICA) -o Out/novaHeuristica
	$(EXEC_NOVA_HEURISTICA) $(MAPA)


