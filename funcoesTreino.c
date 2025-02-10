#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_LENGHT  111
#define NAME_SIZE   100
#define SALARY_SIZE   9

// aprendendo a ler coisas de um txt 😒
void pegaSexo(char* linha, char* sexo){

        *sexo = linha[100];
}


void pegaNome(char* linha, char* nome){

        for(int a = 0; a < NAME_SIZE; a++){
                nome[a] = linha[a];
        }
}


void pegaSalario(char* linha, float* salarioReal){
        
        // passando o salário pra uma string auxiliar
        int aux = 0;
  
        char salario[10];
  
        for(int a = 101; a < 111; a++){
                salario[aux] = linha[a];
                aux++;
        }

        // achar o indice que não tem 0
        int a;
        for(a = 0; salario[a] == '0'; a++);

        // transformando char em float
        int restante = SALARY_SIZE - a;  

        for(int b = 0; b < restante; b++){
                *salarioReal += (float) (salario[a] - '0');  // converte pra int e depois passo pra float
                *salarioReal *= 10;
                a++;
        }

        *salarioReal /= 10;
}


void mostraDados(char* nome, char sexo, float salario){

        printf("nome: %s \nsexo: %c \nsalario: %.2f", nome, sexo, salario);
}


int main(){
        // fazendo o terminal do WINDOWS mostrar ç e ´
        SetConsoleOutputCP(CP_UTF8);

  
        // abrindo o arquivo
        FILE* arquivo = fopen("entrada.txt", "r");
        
        if(arquivo == NULL){
                puts("Arquivo não encontrado");
                return 1;
        }


        // inicializando
        char linha[MAX_LENGHT];

        char nome[NAME_SIZE];  // será o struct
        float salario = 0;     // será o struct 
        char sexo;             // será o struct


        // lendo o que tem no txt
        fgets(linha, MAX_LENGHT, arquivo);

        pegaSexo(linha, &sexo);
        pegaNome(linha, nome);
        pegaSalario(linha, &salario);
        
        mostraDados(nome, sexo, salario);

        return 0;
}



