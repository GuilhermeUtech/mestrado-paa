#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define FRACASSO 0

typedef struct GENERICO Generico;

int criarTipoGenerico(Generico ** vetor, char * tipo, int tamanho, char * dados, int i);

char * inverterString(char *s);

int inverterInteiro(int dados);

void printarSaidaFormatada(Generico ** vetor, int i, char * tipo);