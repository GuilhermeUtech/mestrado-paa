#include "rgen_privado.h"
#include <string.h>

int criarTipoGenerico(GENERICO ** vetor, char * tipo, int tamanho, char * dados, int i){

    if(strcmp(tipo, "int") == 0){
        
        if(i == 1){ 
            *vetor = malloc (sizeof(*vetor));
            (*vetor)->tamanho = tamanho;
            (*vetor)->dados = malloc(sizeof(int));
            (*vetor)->dados = inverterInteiro(atoi(dados));
            (*vetor)->tipo = tipo;
        } else {
            *vetor = realloc(*vetor, sizeof(GENERICO) * i);
            (*vetor+(i-1))->tamanho = tamanho;
            (*vetor+(i-1))->dados = malloc(sizeof(int));
            (*vetor+(i-1))->dados = inverterInteiro(atoi(dados));
            (*vetor+(i-1))->tipo = tipo;
        }

    } else {

        if(i == 0){ 
            *vetor = malloc(sizeof(*vetor));
            (*vetor)->tamanho = strlen(dados);
            (*vetor)->dados = malloc(sizeof(char) * strlen(dados));
            memcpy((*vetor)->dados, inverterString(dados), strlen(dados));
            (*vetor)->tipo = tipo;

        } else {
            *vetor = realloc(*vetor, sizeof(GENERICO) * i);
            (*vetor+(i-1))->tamanho = strlen(dados);
            (*vetor+(i-1))->dados = malloc(sizeof(char) * strlen(dados));
            memcpy((*vetor+(i-1))->dados, inverterString(dados), strlen(dados));
            (*vetor+(i-1))->tipo = tipo;
        }
    }
	
	if(vetor == NULL){
        return FRACASSO;
    } else {
	    return SUCESSO;
    }
}

char * inverterString(char *s){

    int length = strlen(s) ;
    int aux, repasse;

    for (int i=0, repasse=length-1; i<repasse; i++, repasse--){
        aux = s[i];
        s[i] = s[repasse];
        s[repasse] = aux;
    }

    return s;
}

int inverterInteiro(int dados){
    
    int retorno=0;
    int i=1;
   
    while(i<=dados){
        retorno*=10;
        retorno+=(dados%(i*10)-dados%i)/i;
        i*=10;
    }
    return retorno;
}

void printarSaidaFormatada(GENERICO ** vetor, int i, char * tipo){
    if(strcmp(tipo, "int") == 0){
        for(int j=(i-2); j>=0; j--){
            printf("(%d);\n", (*vetor+j)->dados); 
        }
    } else {
        for(int j=(i-2); j>=0; j--){
            printf("(%s);\n", (*vetor+j)->dados);
        }
    }
}