#include <stdio.h>

#include <stdlib.h>

    #include <windows.h>
    #define LIMPA_TELA system("cls")



typedef struct Fila {
    int valor;
    struct Fila *proximo;
}

Dados;

//Inicializando os dados da lista
Dados *principal = NULL;
Dados *final = NULL;

//Inserir um valor na fila
void insere(){
    int val;
    LIMPA_TELA;
    printf("\Inserir‹o: \n");
    printf("Insira o valor a ser inserido: ");
    scanf("%d",&val);
    Dados *atual = (Dados*)malloc(sizeof(Dados));
    atual -> valor = val;
    atual -> proximo = NULL;
    //se o principal estiver vazio, será o atual
    if(principal == NULL){
        principal = final = atual;
    }
    //senao, o proximo valor que seria o atual
    else{
        final->proximo=atual;
        final=atual;
    }
    printf("\nValor inserido!\n");
    getchar();
}


//Exclus‹o
void exclui(){
    Dados *auxiliar;
    printf("\nExclusao: \n");
    //o auxiliar ser‡ o pr—ximo da principal
    auxiliar=principal->proximo;
    //limpando a principal
    free(principal);
    //a principal ser‡ a auxiliar
    principal=auxiliar;
    printf("\nValor excluido!\n");
    getchar();
}


//Mostrando
void mostra(){
    int posicao=0;
    Dados *nova=principal;
    LIMPA_TELA;
    printf("\nMostrando valores: \n");
    //lao de repeti‹o para mostrar os valores
    for (; nova != NULL; nova = nova->proximo) {
    		posicao++;
        printf("Prioridade:‹o %d, contem o valor %d\n", posicao, nova->valor);
        
        
    }
    getchar();
}


//Mostrando erro de digita‹o
void mostra_erro(){
    LIMPA_TELA;
    printf("\nErro de Digita‹o: \n");
   
    printf("\nDigite uma opcao‹o valida ( 'ENTER' PARA CONTINUAR)!\n\n");
    
   	 getchar();
}

int main(){
    char escolha;
    //Lao que ir‡ mostrar o menu esperando uma op‹o (char)
    do {
        //Limpando a tela, e mostrando o menu
        LIMPA_TELA;
        
        
        
        printf("Escolha uma opicao: \n");
     	   printf("1 - Inserir valor na Fila\n");
        printf("2 - Remover valor da Fila\n");
        printf("3 - Mostrar valores da Fila\n");
        printf("4 - Sair\n\n");
        printf("Resposta: ");
        scanf("%c", &escolha);
        switch(escolha) {
            //Inserindo
            case '1':
                insere();
                break;
            //Excluindo
            case '2':
                if(principal!=NULL){
                    exclui();
                }
                else{
                    printf("\nA Fila esta vazia!\n");
                    getchar();
                }
                break;
            //Mostrando
            case '3':
                if(principal!=NULL){
                    mostra();
                }
                else{
                    printf("\n A Fila esta vazia! \n");
                    getchar();
                }
                break;
            case '4':
                printf("\n FIM! \n");
                sleep(3);
                exit(0);
                break;
            //Se foi algum valor invalido
            default:
                mostra_erro();
                break;
        }
        //Impedindo sujeira na grava‹o da escolha
        getchar();
    }
    while (escolha > 0); //Loop Infinito
    return (-1);
}
