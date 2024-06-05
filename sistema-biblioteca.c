#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 50
// Sitema de boblioteca
// 1 cadastrar Usuario da biblioteca
// 1 cadastrar novo Livro
// 2 exibir livros cadastrados
// 3 emprestar livro

typedef struct no{
	int cod;
	int anoPublicacao[TAM_MAX];
	char autor[TAM_MAX];
	char titulo[TAM_MAX];
	char editora[TAM_MAX];
	
	struct no* prox; // ponteiro para percorrer a lista de livros
}No;

void insere_livro(No* novo, No* lista){
	
	if(lista == NULL){
		printf("\nDigite um codigo para o novo livro: ");
		scanf("%d", &novo->cod);
		
		printf("\nDigite o ano da ede publicacao do livro: ");
		scanf("%d", &novo->anoPublicacao);
		
			fflush(stdin); // Limpando o buffer
		
		printf("\nDigite o nome do AUTOR do livro: ");
		gets(novo->autor);
		
		printf("\nDigite o TITULO do livro: ");
		gets(novo->titulo);
		
		printf("\nDigite o nome da EDITORA que produziu o livro: ");
		gets(novo->editora);
		
		printf("\n\tLIVRO CADASTRADO COM SUCESSO!");
		
		novo->prox = NULL;
		lista = novo;
		
		return lista;
		
	}else{
		printf("\nDigite um codigo para o novo livro: ");
		scanf("%d", &novo->cod);
		
		printf("\nDigite o ano da ede publicacao do livro: ");
		scanf("%d", &novo->anoPublicacao);
		
			fflush(stdin); // Limpando o buffer
		
		printf("\nDigite o nome do AUTOR do livro: ");
		gets(novo->autor);
		
		printf("\nDigite o TITULO do livro: ");
		gets(novo->titulo);
		
		printf("\nDigite o nome da EDITORA que produziu o livro: ");
		gets(novo->editora);
		
		printf("\n\tLIVRO CADASTRADO COM SUCESSO!");
		
		novo->prox = Lista;
		lista = novo;
		
		return lista;
	}
}

No* cadastrar_livro(No* lista){
	No* novo = (No *)malloc(sizeof(No));
	
	if(novo==NULL){
		printf("\n\tERRO AO EXECUTAR ESTA FUNCAO! \n  (memortia insuficiente!)");
		exit(1);
	}else{
		lista = insere_livro(novo, lista);
	}
	
	return lista;
}


int main(){
	int op;
	No* lista = NULL;
	
	do{
		printf("\n\n======= BIBLIOTECA ESCOLAR =======");
		printf("\n\n     >>> MENU BIBLIOTECA <<<");
		//printf("[1]-CADASTRAR ADMINISTRADOR DA BIBLIOTECA");
		//printf("[2]-CADASTRAR USUARIO\n");
		printf("\n[1]-CADASTRAR LIVRO NO ACERVO: ");
		printf("\n[2]-EXIBIR TODOS OS LIVRO NO ACERVO: ");
		//printf("[4]-EMPRESTAR LIVRO\n");
		
		printf("\nDIGITE AQUI: ");
		scanf("%d", &op);
	
	
	
		switch(op){
			case 1:{
				lista = cadastrar_livro(lista);
				break;
			}
		}
	}while(op != 0);
	
	
	
	return 0;
}
