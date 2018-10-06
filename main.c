/*  Disciplina: CC6252 - Compiladores
 *  Projeto IV - Analisador Sintático de Expressão
 *  Desenvolvido por: João Victor Fernandes de Souza - RA: 22116012-0
 *                    Marcus Vinicius Sato Moré      - RA: 22115003-0
 */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
// Adicionando arquivo de funções auxiliares
#include "helpers.c"

int main(){
    
    char e[200];
    int  i = 0, // Posição da Cabeça de Leitura
         p = 0; // Pilha
    printf("\nDigite a Entrada: ");
    gets(e);
    goto A;

A:

    if(e[i] >= '0' && e[i] <= '9'){
        i++;
        goto B;
    }
    else 
        if(e[i] == '('){
            i++;
            goto C;
        }
        else
            goto REJEITA;
B:

    if(e[i] == '+' || e[i] == '-' || e[i] == '*' || e[i] == '/'){
        i++;
        goto A;
    }
    else 
        if(e[i] == ')'){
            if(p > 0){
                p--;
                goto D;
            }
            else
                goto REJEITA;             
        }
        else
            if(e[i] == '\0' && p == 0)
                goto ACEITA;
            else
                goto REJEITA;

C:
    p++;
    goto A;

D:
    if(e[i] == ')'){
        i++;
        goto B;
    }
    else
        goto REJEITA;

ACEITA:
    printf("\nSaida:  Aceita!\n");
    return(1);
REJEITA:
    printf("\nSaida:  Rejeita!\n");
    return 0;
}
