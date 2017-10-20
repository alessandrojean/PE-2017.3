#include <stdio.h>
#include <string.h>

int main(){
    char expressao[1000] = "";
    while(scanf("%s", expressao) != EOF)
    {
        int fechados = 0, erro = 0, pAbertos = 0, pFechados = 0, i = 0;
        for(; i < strlen(expressao); i++){
            if(expressao[i] == '('){
                fechados++;
                pAbertos++;
            }
            else if(expressao[i] == ')'){
                fechados--;
                pFechados++;
                if(fechados < 0)
                    erro++;
            }

        }

        if(pAbertos > 0 || pFechados > 0)
            printf(fechados == 0 && erro == 0 ? "correct\n" : "incorrect\n");
    }
    
    return 0;
}