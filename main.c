#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define NAME_SIZE  101
#define SEX_INDEX  100
#define MAX_SIZE   112
#define SALARY_SIZE 10

// corrija sempre com muito amor e carinho professor     😳
//                                                      👉👈


// código é nosso, logo, organizo ele da forma que EU QUERO >:(


typedef struct {

        char nome[NAME_SIZE];
        char sexo;
        double salario;

} Dado;


typedef struct No{

        Dado* infos;

        struct No* proximo;
        struct No* anterior;
        
} No;

typedef struct {

        No* comeco;
        No* fim;
        
} Fila;



void pegaSexo(char* linha, char* sexo){

        *sexo = linha[SEX_INDEX];
}


void pegaNome(char* linha, char* nome){

        int a;
        for(a = 0; a < NAME_SIZE - 1; a++){
                nome[a] = linha[a];
        }

        nome[a] = '\0';
}


void pegaSalario(char* linha, double* salario) {

        char salarioChar[SALARY_SIZE];
        int b = 0;
        
        for (int a = 101; a < 101 + 9; a++) {
            salarioChar[b] = linha[a];
            b++;
        }
        
        salarioChar[b] = '\0';

        *salario = atof(salarioChar);
}


void insereDados(Fila* fila, char* linha){

        // inicialização das structs novas
        No* novoNo     = (No*)malloc(sizeof(No));
        Dado* novoDado = (Dado*)malloc(sizeof(Dado));

        if(novoNo == NULL || novoDado == NULL){
                puts("problema na criação de dados para a fila");

                return;
        }

        // aplicação da lógica

        // colocando valores em novoDado
        pegaSexo(linha, &novoDado->sexo);
        pegaNome(linha, novoDado->nome);
        pegaSalario(linha, &novoDado->salario);
        
        // ligando o Nó com os dados passados
        novoNo->infos   = novoDado;
        novoNo->proximo = NULL;

        // ligando o nó criado à lista
        if(fila->comeco == NULL){
                fila->comeco = novoNo;
                fila->fim    = novoNo;
                
                novoNo->anterior = NULL;
        
        } else {
                
                novoNo->anterior = fila->fim;
                
                fila->fim->proximo = novoNo;
                fila->fim          = novoNo;
        }
}


void mostraFilaIda(Fila* fila){

        // peguei o nó inicial
        No* att = fila->comeco;

        puts("------------------------------------------------------------");        
        while(att != NULL){

                printf("Nome: %s \n", att->infos->nome);
                printf("Sexo: %c \n", att->infos->sexo);
                printf("Salario: %.2f \n", att->infos->salario);
                puts("------------------------------------------------------------");
                
                att = att->proximo;
        }

        printf("\n");
}


void mostraFilaVolta(Fila* fila){

        No* att = fila->fim;
        
        puts("------------------------------------------------------------");        
        while(att != NULL){

                printf("Nome: %s \n", att->infos->nome);
                printf("Sexo: %c \n", att->infos->sexo);
                printf("Salario: %.2f \n", att->infos->salario);
                puts("------------------------------------------------------------");
 
                att = att->anterior;
        }

        printf("\n");
        
}


Fila* criaFila(){

        Fila* fila = (Fila*)malloc(sizeof(Fila));

        fila->comeco = NULL;
        fila->fim    = NULL;

        return fila;
}


void ordenaFila(Fila* fila){  // tô usando bubble sort com aquela flag de mudança
        // ain mas é ruim em performance
        // NON ME INTERESSA 😎😎🔥🔥😎😎🔥🔥😎😎🔥🔥😎😎🔥🔥😎😎

        // strcmp(1, 2) compara pra ver qual é antes no alfabeto
        // 0 se são iguais; negativo se a primeira; positivo se a segunda

        int trocado;

        No* att; 

        do{
                trocado = 0;

                att = fila->comeco;

                while(att->proximo != NULL){
                        
                        if(strcmp(att->infos->nome, att->proximo->infos->nome) > 0){
                                
                                Dado* temp = att->infos;
                                
                                att->infos = att->proximo->infos;
                                
                                att->proximo->infos = temp;
                                
                                trocado = 1;
                        }

                        att = att->proximo;
                }

        } while(trocado);

}


void limpaBuffer(){
        char c;
        while((c = getchar()) != '\n' && c != EOF);
}


int mostraOpcoes(){
        
        int escolha;
        
        do{     
                puts("escolha uma das opcoes possiveis");
                int res = scanf("%d", &escolha);
                
                if(!res){
                        limpaBuffer();
                        continue;
                }
                
        } while(escolha != 1 && escolha != 2 && escolha != 0);
        
        return escolha;
}


// sempre com um bom uso de comentários dentro do código :D
int main(){

        setlocale(LC_ALL, "pt_BR.UTF-8");

        // inicialização
        Fila* fila = criaFila();

        FILE* arquivo = fopen("entrada.txt", "r");

        char linha[MAX_SIZE];

        int escolha;
        
        // implementação
        while(fgets(linha, MAX_SIZE, arquivo) != NULL){
                
                if(linha[strlen(linha) - 1] == '\n'){
                        linha[strlen(linha) - 1] = '\0';
                }

                if(linha[0] == '\0'){  // por algum motivo ficava printando uma linha inicial sem ninguém
                        continue;
                }

                insereDados(fila, linha);
        }


        ordenaFila(fila);
        
        
        while(1){
                puts("escolha 1 para mostrar em ordem crescente (a..z)");
                puts("escolha 2 para mostrar em ordem decrescente (z..a)");
                puts("escolha 0 para terminar o programa (ele sentirá sua falta 😭)");
                
                escolha = mostraOpcoes();
                
                if(escolha == 1){
                        mostraFilaIda(fila);
                        
                } else if(escolha == 2){
                        mostraFilaVolta(fila);
                        
                } else {
                        puts("adeus 😥");
                        break;
                }
        }
        

        return 0;
}
