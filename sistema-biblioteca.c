#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 50
// Sitema de boblioteca
// 1 cadastrar Usuario da biblioteca
// 1 cadastrar novo Livro
// 2 exibir livros cadastrados
// 3 emprestar livro



// Lista de Usuários
typedef struct usu{
	int id;
	char nome[TAM_MAX];
	struct usu * prox;
}USU;


typedef struct no{
	int cod;
	char autor [TAM_MAX];
	char titulo[TAM_MAX];
	char editora[TAM_MAX];
	int alugado;
	
	struct no* prox; // ponteiro para percorrer a lista de livros
}No;

void insere_No_Arquivo(No* lista){
	FILE* arquivo;
	int contador_indice_lista = 0;
	
	
	// Cria um arquivo em modo de adição (a --> so add) (a+  --> add e lê) para adicionar sempre um arquivo sempre no final com uma pilha;
	arquivo = fopen("livrosCadastrados.txt", "a");
	
	// Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        // Exibe mensagem de erro se não foi possível abrir o arquivo
        printf("Erro ao abrir o arquivo!\n");
        //return 1; // Retorna um código de erro
    }
    
    
    if(contador_indice_lista !=0){
    	fprintf(arquivo, "\n\n\n%d\n", lista->cod);
		fflush(arquivo);
		fflush(arquivo); // Força a escrita do contéudo da variável no arquivo
		fprintf(arquivo, "%s\n", lista->autor);
		fflush(arquivo);
		fprintf(arquivo, "%s\n", lista->titulo);
		fflush(arquivo);
		fprintf(arquivo, "%s\n", lista->editora);
		fflush(arquivo);
	}else{
		fprintf(arquivo, "%d\n", lista->cod);
		fflush(arquivo);
		fflush(arquivo); // Força a escrita do contéudo da variável no arquivo
		fprintf(arquivo, "%s\n", lista->autor);
		fflush(arquivo);
		fprintf(arquivo, "%s\n", lista->titulo);
		fflush(arquivo);
		fprintf(arquivo, "%s\n", lista->editora);
		fflush(arquivo);
	}
	
	contador_indice_lista = 1;
	
}

No* insere_livro(No* novo, No* lista){
	
	
	if(lista == NULL){
		printf("\nDigite um codigo para o novo livro: ");
		scanf("%d", &novo->cod);
    
		fflush(stdin);
		printf("\nDigite o nome do AUTOR do livro: ");
		gets(novo->autor);
		
		printf("\nDigite o TITULO do livro: ");
		gets(novo->titulo);
		
		printf("\nDigite o nome da EDITORA do livro: ");
		gets(novo->editora);
		
		printf("\n\tLIVRO CADASTRADO COM SUCESSO!");
		
		
		// ADICIONANDO O LIVRO NA LISTA  (STRUCT)
		novo->prox = NULL;
		lista = novo;
		
		insere_No_Arquivo(lista);
		
		return lista;
		
	}else{ // se a lista não estiver vazia
		printf("\nDigite um codigo para o novo livro: ");
		scanf("%d", &novo->cod);
		
		fflush(stdin);
		printf("\nDigite o nome do AUTOR do livro: ");
		gets(novo->autor);
		
		printf("\nDigite o TITULO do livro: ");
		gets(novo->titulo);
		
		printf("\nDigite o nome da EDITORA do livro: ");
		gets(novo->editora);
		
		
		printf("\n\tLIVRO CADASTRADO COM SUCESSO!");
		
		
		// ADICIONANDO UM NOVO LIVRO NA LISTA  (STRUCT)
		novo->prox = lista;
		lista = novo;
		
		insere_No_Arquivo(lista);
		
		return lista;
	}
}

No* cadastrar_livro(No* lista){
	No* novo = (No *)malloc(sizeof(No));
	
	if(novo==NULL){
		printf("\n\tERRO AO EXECUTAR ESTA FUNÇÃO! \n  (memoria insuficiente!)");
	}else{
		lista = insere_livro(novo, lista);
	}
	
	return lista;
}


void exibir_Livros(No* lista){ // PROVISÓSRIA POIS IREI EXIBIR OS LIVROS COM BASE OS DADOS CADASTRADOS NO ARQUIVO
	No* aux = lista;
	
	if(lista == NULL){
		printf("A LISTA ESTA VAZIA!");
	}else{
		while(aux != NULL){
			
			printf("\n\n\tCODIGO DO LIVRO: %d", aux->cod);
			printf("\n\tAUTOR: %s", aux->autor);
			printf("\n\tTITULO: %s", aux->titulo);
			printf("\n\tEDITORA: %s", aux->editora);
			aux = aux->prox;
		}
	}	
}

void limpar_Banco(){
	FILE* arquivo;
	
	// Abre ou cria o arquivo "exemplo.txt" em modo de escrita ("w")
	arquivo = fopen("livrosCadastrados.txt", "w");
	
	// Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        // Exibe mensagem de erro se não foi possível abrir o arquivo
        printf("Erro ao abrir o arquivo!\n");
        //return 1; // Retorna um código de erro
    }
    
    printf("\n\t LIMPESA DE BANCO EXECUTADA COM SUCESSO!");
}


int main(){
	int op;
	No* lista = NULL;
	
	do{
		printf("\n\n======= BIBLIOTECA ESCOLAR =======");
		printf("\n\n     >>> MENU BIBLIOTECA <<<");
		//printf("[1]-CADASTRAR ADMINISTRADOR DA BIBLIOTECA");
		//printf("[2]-CADASTRAR USUARIO\n");
		printf("\n[1]-CADASTRAR LIVRO NO ACERVO");
		printf("\n[2]-EXIBIR LIVROS CADASTRADOS");
		printf("\n[3]-LIMPAR BANCO DE DADOS");
		printf("\n[0]-SAIR");
		//printf("[4]-EMPRESTAR LIVRO\n");
		
		printf("\nDIGITE AQUI: ");
		scanf("%d", &op);
	
	
	
		switch(op){
			case 1:{
				lista = cadastrar_livro(lista);
				break;
			}
			case 2:{
				exibir_Livros(lista);
				break;
			}
			case 3:{
				limpar_Banco();
				break;
			}
			case 0:{
				printf("\n\tFIM DO PROGRAMA!");
				break;
			}	
		}
	}while(op != 0);
	
	return 0;
	
}
