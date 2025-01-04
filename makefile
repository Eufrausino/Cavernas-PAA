compile:
	gcc Src/main.c Src/leitura.c Src/mapa.c -o Out/exe

run: 
	./Out/exe

all: compile run



# Testes
leitura:
	gcc Test/leitura_teste.c Src/leitura.c Src/mapa.c -o Out/leitura_teste
	./Out/leitura_teste