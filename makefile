#---------------------------Variáveis da Main------------------------------------
CC = gcc
MAIN_SRC = Src/main.c Src/arquivo.c Src/mapa.c Src/progDinamica.c 
MAIN_OUT = Out/exe
EXEC_MAIN = ./$(MAIN_OUT)
MAPA ?= mapa


#----------------------------Variáveis de Testes----------------------------------
#Var Arquivos(FILE)
TEST_ARQUIVO = Test/arquivo_teste.c Src/arquivo.c Src/mapa.c
TEST_OUT_ARQUIVO = Out/arquivo_teste
EXEC_TEST_ARQUIVO = ./$(TEST_OUT_ARQUIVO)

#var ProgDinamamica
TEST_PROG_DINAMICA =  Test/prog_dinamica_teste.c  Src/progDinamica.c Src/arquivo.c Src/mapa.c
TEST_OUT_PROG_DINAMICA = Out/progDinam_teste
EXEC_TEST_PROG_DINAMICA = ./$(TEST_OUT_PROG_DINAMICA)


#------------------------------Rules----------------------------------------------
compile:
	$(CC) $(MAIN_SRC) -o $(MAIN_OUT)


run: 
	$(EXEC_MAIN) $(MAPA)

all: compile run

clean:
	rm -f $(MAIN_OUT) Out/*.txt


#-----------------------------Testes----------------------------------------------
files:
	$(CC) $(TEST_ARQUIVO) -o $(TEST_OUT_ARQUIVO)
	$(EXEC_TEST_ARQUIVO)


pd:
	$(CC) $(TEST_PROG_DINAMICA) -o $(TEST_OUT_PROG_DINAMICA)
	$(EXEC_TEST_PROG_DINAMICA)


#----------------------------Variáveis de Extra----------------------------------
#Var Arquivos(FILE)
CRIA_ARQUIVO = Src/criador.c Src/arquivo.c Src/mapa.c
SAIDA_CRIA_ARQUIVO = Out/criador
EXEC_CRIA_ARQUIVO = ./$(SAIDA_CRIA_ARQUIVO)

NOME ?= mapaCriado
LINHA ?= 10
COLUNA ?= 10
VIDA ?= 100


#-----------------------------Rules Extras----------------------------------------------

make criarArquivo:
	$(CC) $(CRIA_ARQUIVO) -o $(SAIDA_CRIA_ARQUIVO)
	$(EXEC_CRIA_ARQUIVO) $(NOME) $(LINHA) $(COLUNA) $(VIDA)
