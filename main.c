#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROD 100       
#define MAX_DEP 20         
#define TAM_NOME 50        
#define TAM_DEP 300        

char departamentos[MAX_DEP][TAM_DEP];
int total_departamentos = 0;


char nomes[MAX_PROD][TAM_NOME];
int departamento_produto[MAX_PROD]; 
int estoques[MAX_PROD];
float precos[MAX_PROD];
int total_produtos = 0;

void pausar() {
    printf("\nPressione [ENTER] para continuar...");
    getchar();
    getchar();
}
void limpar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void exibir_logo() {
    FILE *arquivo = fopen("logo.txt", "r");

    // Caso o arquivo nao exista, gera um padrao inicial automaticamente
    if (arquivo == NULL) {
        arquivo = fopen("logo.txt", "w");
        if (arquivo != NULL) {
            fprintf(arquivo, "============================================\n");
            fprintf(arquivo, "       SISTEMA INTEGRADO DE LOJA v3.2       \n");
            fprintf(arquivo, "============================================\n");
            fclose(arquivo);
            arquivo = fopen("logo.txt", "r");
        }
    }


// MOSTRAR PRODUTOS


void mostra_produtos_s() {
			
	printf("\n\n ===== SALGADOS =====\n\n");

	for(int i = 0; i < 11; i++) {

		printf("%d - %s -- R$ %.2f -- ESTOQUE: %d\n" , i, produtos[i], precos[i], estoque[i], 
		       i + 1);
		       		
		       
	}
	
	

	int produtose;
	int quantidade;

	

	printf("\nESCOLHA O PRODUTO: ");
	scanf("%d", &produtose);
	


	if(produtose < 0 || produtose > 10) {
		printf("\nPRODUTO INVÁLIDO!\n");
		return;
	}

	//ESCOLHA PRODUTOS

	printf("\nESCOLHA A QUANTIDADE: ");
	scanf("%d", &quantidade);

	if(quantidade <= 0) {
		printf("\nQUANTIDADE INVÁLIDA!\n");
		return;
	}

	if(quantidade > estoque[produtose]) {
		printf("\nESTOQUE INSUFICIENTE!\n");
		return;
	}

	compras [produtose] += quantidade;
	estoque [produtose] -= quantidade;

	printf("\nCOMPRA REALIZADA!\n");
}



void mostra_produtos_d() {

	printf("\n\n ===== DOCES =====\n\n");

	for(int i = 12; i < 26 && i> 10; i++) {

		printf("%d - %s -- R$ %.2f -- ESTOQUE: %d\n" , i, produtos[i], precos[i], estoque[i], 
		       i + 1);
		       
		       
	}
	int produtose;
	int quantidade;

	//MOSTRA PRODUTOS

	printf("\nESCOLHA O PRODUTO: ");
	scanf("%d", &produtose);

	if(produtose < 10 || produtose > 26) {
		printf("\nPRODUTO INVÁLIDO!\n");
		return;
	}

	//QUANTIDADE PRODUTOS

	printf("\nESCOLHA A QUANTIDADE: ");
	scanf("%d", &quantidade);

	if(quantidade <= 0) {
		printf("\nQUANTIDADE INVÁLIDA!\n");
		return;
	}

	if(quantidade > estoque[produtose]) {
		printf("\nESTOQUE INSUFICIENTE!\n");
		return;
	}

	compras [produtose] += quantidade;
	estoque [produtose] -= quantidade;

	printf("\nCOMPRA REALIZADA!\n");
}




void mostra_produtos_b() {

	printf("\n\n ===== BEBIDAS =====\n\n");

	for(int i = 30; i < 39 && i> 29; i++) {

		printf("%d - %s -- R$ %.2f -- ESTOQUE: %d\n" , i, produtos[i], precos[i], estoque[i], 
		       i + 1);
		       
		       
	}
	int produtose;
	int quantidade;

	//mostra_produtos();

	printf("\nESCOLHA O PRODUTO: ");
	scanf("%d", &produtose);

	if(produtose < 29 || produtose > 39) {
		printf("\nPRODUTO INVÁLIDO!\n");
		return;
	}

	//produtose--;

	printf("\nESCOLHA A QUANTIDADE: ");
	scanf("%d", &quantidade);

	if(quantidade <= 0) {
		printf("\nQUANTIDADE INVÁLIDA!\n");
		return;
	}

	if(quantidade > estoque[produtose]) {
		printf("\nESTOQUE INSUFICIENTE!\n");
		return;
	}

	compras [produtose] += quantidade;
	estoque [produtose] -= quantidade;

	printf("\nCOMPRA REALIZADA!\n");
}








// MOSTRAR COMPRA


void mostra_compra() {

	float total = 0;

	printf("\n\n========== SUA COMPRA ==========\n");


	// PRODUTOS

	for(int i = 0; i < QP; i++) {

		if(compras [i] > 0) {

			float pagar = compras[i] * precos[i];

			printf("\n%d - %s",

			       i + 1,
			       produtos [i]);

			printf("\nQUANTIDADE: %.0f", compras[i]);

			printf("\nVALOR: R$ %.2f\n", pagar);

			total += pagar;
		}
	}




	printf("\n --------- ೀ ---------\n");
	printf("\n     TOTAL: R$ %.2f\n", total);
	printf("\n -----------------------");
}



// MENU

void menu() {

	int escolha;

	do {

		printf("\n MENU PRINCIPAL ୭ ᵎᵎ 🍭\n\n");

		printf("1 - SALGADOS\n");
		printf("2 - DOCES\n");
		printf("3 - BEBIDAS\n");
		printf("4 - VER COMPRA\n");
		printf("5 - SAIR\n");

		printf("\nESCOLHA: ");
		scanf("%d", &escolha);


		switch(escolha) {

		case 1:
			limpar();
			mostra_produtos_s();
			pausar();
			limpar();

			break;


		case 2:
			limpar();
			mostra_produtos_d();
			pausar();
			limpar();
			break;


		case 3:
			limpar();
		    mostra_produtos_b();
		    pausar();
			limpar();			
			break;


		case 4:
			limpar();
			mostra_compra();
			pausar();
			limpar();
			break;


		case 5:

			printf("\nSAINDO...\n");

			break;


		default:

			printf("\nESCOLHA INVÁLIDA!\n");
		}

	} while(escolha != 5);
}


// MAIN


#define ROSA_BEBE "\033[38;2;255;182;193m"

int main() {

	printf(ROSA_BEBE
	       "██████╗  ██╗ ███████╗ ██████╗  ███████╗ ██████╗  ❤︎   ███████╗\n"
	       "██╔══██╗ ██║ ██╔════╝ ██╔══██╗ ██╔════╝ ██╔══██      ██╔════╝\n"
	       "██████╔╝ ██║ █████╗   ██████╔╝ █████╗   ██████╔╝     ███████╗\n"
	       "██╔══██╗ ██  ██╔══╝   ██╔══██╗ ██╔══╝   ██╔══██╗     ╚════██║\n"
	       "██████╔╝ ██║ ███████╗ ██████╔╝ ███████╗ ██║  ██      ███████║\n"
	       "╚═════╝  ╚═╝ ╚══════╝ ╚═════╝  ╚══════╝ ╚═╝  ╚═╝     ╚══════╝\n"
	      );

	printf("\n");
	printf("              C O N F E I T A R I A\n\n");

	printf("                ──── ୨୧ ────\n\n");

	menu();

	return 0;
}

