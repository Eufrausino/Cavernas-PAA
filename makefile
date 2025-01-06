#QUANDO CRIAREM MAIS MUDULOS, É  SO ADICIONAR NA LINHA DO < MAIN_SCR > O QUE TIVER CRIADO

#JA OS TESTES TEM QUE FAZER DO ZERO

#---------------------------Variáveis da Main------------------------------------
CC = gcc
MAIN_SRC = Src/main.c Src/leitura.c Src/mapa.c
MAIN_OUT = Out/exe
EXEC_MAIN = ./$(MAIN_OUT)

#----------------------------Variáveis de Testes----------------------------------
#Var Leitura
TEST_LEITURA = Test/leitura_teste.c Src/leitura.c Src/mapa.c Src/prog_dinamica.c
TEST_OUT_LEITURA = Out/leitura_teste
EXEC_TEST_LEITURA = ./$(TEST_OUT_LEITURA)

#------------------------------Rules----------------------------------------------
compile:
	$(CC) $(MAIN_SRC) -o $(MAIN_OUT)

run:
	$(EXEC_MAIN)

all: compile run

#-----------------------------Testes----------------------------------------------
leitura:
	$(CC) $(TEST_LEITURA) -o $(TEST_OUT_LEITURA)
	$(EXEC_TEST_LEITURA)
