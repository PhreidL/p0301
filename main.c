#include <stdio.h>
#include <stdlib.h>
#define esp 100

char f[esp];
char pilha[esp];
int p = 0;
int itens = 0;


void eA();
void eB();
void eC();
void eD();
void empilha();
void desempilha();

int main() {
    puts("Entrada de expressao:");
    gets(f);
    fflush(stdin);
    eA();
    return 0;
}

void eA(){
    if(f[p] >= '0' && f[p] <= '9'){
        p++;
        eB();
    }
    else 
		if(f[p] == '('){
        	p++;
        	eC();
    	}
    	else{
        	puts("rejeita");
    	}
}

void eB(){
    if(f[p] == '*' || f[p] == '/' || f[p] == '+' || f[p] == '-'){
        p++;
        eA();
    }
    else 
		if(itens != 0 && f[p] != '\0'){
        	eD();
    	}
    	else{
        	if(itens == 0 && f[p] == '\0'){
            	puts("aceita");
            	return main();
        	}
        	else{
            	puts("rejeita");
    		}
		}
}

void eC(){
	empilha(')');
	eA();
}

void eD(){
	if(f[p] == ')'){
        p++;
        desempilha();
    }
}

void empilha(){
    //pilha[itens] = a;
    itens++;
}

void desempilha(){
    itens--;
    eB();
}
