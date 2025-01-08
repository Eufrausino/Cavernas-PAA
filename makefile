#QUANDO CRIAREM MAIS MUDULOS, É  SO ADICIONAR NA LINHA DO < MAIN_SCR > O QUE TIVER CRIADO

#---------------------------Variáveis da Main------------------------------------
CC = gcc
MAIN_SRC = Src/main.c Src/arquivo.c Src/mapa.c Src/progDinamica.c
MAIN_OUT = Out/exe
EXEC_MAIN = ./$(MAIN_OUT)


#----------------------------Variáveis de Testes----------------------------------
#Var Arquivos(FILE)
TEST_ARQUIVO = Test/arquivo_teste.c Src/arquivo.c Src/mapa.c
TEST_OUT_ARQUIVO = Out/arquivo_teste
EXEC_TEST_ARQUIVO = ./$(TEST_OUT_ARQUIVO)

#var ProgDinamamica
TEST_PROG_DINAMICA =  Test/prog_dinamica_teste.c  Src/progDinamica.c Src/arquivo.c Src/mapa.c
TEST_OUT_PROG_DINAMICA = Out/progDinam_teste
EXEC_TEST_PROG_DINAMICA = ./$(TEST_OUT_PROG_DINAMICA)

#var menu
TEST_MENU = Test/menu_teste.c #colocar restante aquivos necessarios
TEST_OUT_MENU = Out/menu_teste
EXEC_TEST_MENU = ./$(TEST_OUT_MENU)


#------------------------------Rules----------------------------------------------
compile:
	$(CC) $(MAIN_SRC) -o $(MAIN_OUT)

run:
	$(EXEC_MAIN)

all: compile run


#-----------------------------Testes----------------------------------------------
files:
	$(CC) $(TEST_ARQUIVO) -o $(TEST_OUT_ARQUIVO)
	$(EXEC_TEST_ARQUIVO)

menu:
	$(CC) $(TEST_MENU) -o $(TEST_OUT_MENU)
	$(EXEC_TEST_MENU)

pd:
	$(CC) $(TEST_PROG_DINAMICA) -o $(TEST_OUT_PROG_DINAMICA)
	$(EXEC_TEST_PROG_DINAMICA)
