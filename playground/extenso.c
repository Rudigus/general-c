#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int i, un, dez, cent, mil, esp;
    char unidade[10][15] = {"", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    char dezena[10][15] = {"", "dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
    char centena[10][15] = {"", "cem", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos",
    "oitocentos", "novecentos"};
    char especial[9][15] = {"onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
    setlocale(LC_ALL, "portuguese");
    for(i = 1; i < 10000; i++){
        un = (i % 10);
        dez = (i % 100) / 10;
        cent = (i % 1000) / 100;
        mil = i / 1000;
        esp = i % 100;
        if(mil != 0 && mil == 1)
        {
            printf("mil");
        } else if (mil != 0){
            printf("%s mil", unidade[mil]);
        }
        if(cent != 0 && mil == 0){
            printf("%s", centena[cent]);
        } else if(cent != 0 && mil != 0 && (dez != 0 || un != 0)){
            printf(", %s", centena[cent]);
        } else if(cent != 0 && mil != 0){
            printf(" e %s", centena[cent]);
        }
        if(esp >= 11 && esp <= 19 && (cent != 0 || mil != 0))
        {
            printf(" e %s. ", especial[esp - 11]);
            continue;
        } else if(esp >= 11 && esp <= 19){
            printf("%s. ", especial[esp - 11]);
            continue;
        }
        if(dez != 0 && (mil != 0 || cent != 0)){
            printf(" e %s", dezena[dez]);
        } else if (dez != 0){
            printf("%s", dezena[dez]);
        }
        if(un != 0 && (dez != 0 || cent != 0 || mil != 0)){
            printf(" e %s. ", unidade[un]);
        } else if(un != 0){
            printf("%s. ", unidade[un]);
        } else{
            printf(". ");
        }
    }
    return 0;
}
