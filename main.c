/*

  EU AINDA TENHO QUE ARRUMAR TODAS AS FUNÇÕES

  SE ESSE CÓDIGO FOR RODADO ELE VAI DAR UM ERRO

  Depois que eu fiz aquele arquivo de funções pra ter uma noção melhor de como pegar os dados do txt
  eu comecei a alterar a struct No e a criar a struct Dado

  As funções TODAS aqui estão adaptadas para a struct No receber como um dado um int, não uma struct

*/


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define NAME_SIZE 100
#define SALARY     10

// corrige com carinho fessor 😳
typedef struct {  // tenho que arrumar o restante das funções pra conseguir parear com essa

        char nome[NAME_SIZE];
        char sexo;
        float salario;

} Dado;

typedef struct No {

        struct Dado* dados;

        struct No* anterior;
        struct No* proximo;        

} No;

typedef struct {

        struct No* comeco;
        struct No* fim;

} Lista; 


Lista* criaLista(){
        Lista* lista = (Lista*)malloc(sizeof(Lista));

        if(lista == NULL){
                puts("erro ao criar a lista");
                return NULL;
        }

        lista->comeco = NULL;
        lista->fim = NULL;

        return lista;
}


void deletaLista(Lista* lista){

        No* att = lista->comeco;

        while(att != NULL){
                No* aux = att; 
                att = att->proximo;
                free(aux);
        }

        free(lista);

        puts("lista liberada da memoria");
}


void adicionaDado(Lista* lista, Dado* dado){
        No* novo = (No*)malloc(sizeof(No));

        if(novo == NULL){
                puts("erro ao criar o nó da lista");
                return;
        }

        novo->info = dado;
        novo->proximo = NULL;

        if(lista->comeco == NULL){
                lista->comeco = novo;
                lista->fim = novo;

                novo->anterior = NULL;

                return;
        }

        // o "fim" é onde será appendado 
        No* att = lista->fim;

        att->proximo = novo;
        novo->anterior = att;
        lista->fim = novo;
}


void mostraListaVai(Lista* lista){

        No* att = lista->comeco;

        while(att != NULL){
                printf("%d \n", att->info);

                att = att->proximo;
        }

        printf("\n");
}


void mostraListaVolta(Lista* lista){

        No* att = lista->fim;

        while(att != NULL){
                printf("%d \n", att->info);

                att = att->anterior;
        }

        printf("\n");
}


int main(){
        
        // fazendo o terminal reconhecer utf8 direito
        SetConsoleOutputCP(CP_UTF8);

        // criação da lista
        Lista* lista = criaLista();

        // adicionando dados
        adicionaDado(lista, 3);
        adicionaDado(lista, 5);
        adicionaDado(lista, 7);
        adicionaDado(lista, 9);
        adicionaDado(lista, 6);
        adicionaDado(lista, 1);
        adicionaDado(lista, 2);
        adicionaDado(lista, 4);

        // mostrando a lista
        mostraListaVai(lista);
        mostraListaVolta(lista);

        // libera a lista criada junto com seus dados
        deletaLista(lista);

        // só testando pra ser se a lista foi apagada mesmo
        mostraListaVai(lista);

        return 0;
}

