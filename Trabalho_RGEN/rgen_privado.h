#include "rgen_publico.h"
#include <string.h>

#define SUCESSO 1
#define FRACASSO 0

typedef struct GENERICO{
    void * dados;
    char * tipo;
    int tamanho;
} GENERICO;

