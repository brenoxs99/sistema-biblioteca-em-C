#include <stdio.h>
#include <stdlib.h>

// Sitema de boblioteca
// 1 cadastrar Usuario da biblioteca
// 1 cadastrar novo Livro
// 2 exibir livros cadastrados
// 3 emprestar livro

typedef struct no{
	int cod;
	char autor [50];
	char titulo[50];
	char editora[50];
	
	struct no* prox; // ponteiro para percorrer a lista de livros
}No;

//No* pede_Dados(No * nuevo){
	
	
//	return novo;
//}

void insere_livro(No* novo, No* lista){
	
	if(lista == NULL){
		printf("\nDigite um codigo para o novo livro: ");
		scanf("%d", &novo->cod);
		
		fflush(stdin);
		printf("\nDigite o nome do AUTOR do livro: ");
		gets(novo->autor);
		
		printf("\n\tLIVRO CADASTRADO COM SUCESSO!");
	}
}

No* cadastrar_livro(No* lista){
	No* novo = (No *)malloc(sizeof(No));
	
	if(novo==NULL){
		printf("\n\tERRO AO EXECUTAR ESTA FUNCAO! \n  (memortia insuficiente!)");
	}else{
		insere_livro(novo, lista);
	}
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
		//printf("[4]-EMPRESTAR LIVRO\n");
		
		printf("\nDIGITE AQUI: ");
		scanf("%d", &op);
	
	
	
		switch(op){
			case 1:{
				cadastrar_livro(lista);
				break;
			}
		}
	}while(op != 0);
	
	
	
	return 0;
}
