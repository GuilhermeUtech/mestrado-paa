#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define FRACASSO 0
#define SUCESSO 1

int main (int argc, char **argv) {
    
    Generico * vetor = NULL; 

    char * tipo;
    int tamanho;
    int i = 1;
    
    if (scanf("Tipo:%m[a-z];", &tipo) != 1) {
        printf("Erro ao ler a entrada!\n");
    } else {
        printf("Tipo_do_dado:%s;\n", tipo);

        if(obterBytesTipo(tipo, &tamanho) == SUCESSO){
            char * dadosEntrada;
            
            while(scanf("%ms", &dadosEntrada) != EOF){

                char *token = strtok(dadosEntrada, ";");

                while (token != NULL){
                    if(criarTipoGenerico(&vetor, tipo, tamanho, token, i) == 1){
                        i++;
                    } else {
                     printf("Erro ao criar a variável de tipo genérico!'\n");
                     exit(1);   
                    }
                    token = strtok(NULL, ";");
                }

            }
            printarSaidaFormatada(&vetor, i, tipo);

        } else {
            printf("Erro ao tentar obter os dados de entrada!\n");
        }
    }
    
    return 0;
}

int obterBytesTipo(char *tipo, int *tamanho){
    
    if(strcmp(tipo, "char") == 0){
        *tamanho = sizeof(char);
        return SUCESSO;
    } else if(strcmp(tipo, "short") == 0){
        *tamanho = sizeof(short);
        return SUCESSO;
    } else if(strcmp(tipo, "int") == 0 || strcmp(tipo, "long") == 0 || strcmp(tipo, "float") == 0){
        *tamanho = sizeof(int);
        return SUCESSO;
    } else if(strcmp(tipo, "double") == 0){
        *tamanho = sizeof(double);
        return SUCESSO;
    } else {
        return FRACASSO;
    }

}
