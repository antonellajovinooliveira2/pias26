#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
#define QP 40


// SALGADOS

char tipo [3] = {
	'S', 'D', 'B'
};

char produtos[QP][100] = {
	"COXINHA DE FRANGO",
	"COXINHA DE CARNE",
	"COXINHA DE COSTELA",
	"PASTEL DE QUEIJO",
	"PASTEL DE CARNE",
	"PASTEL DE PIZZA",
	"ESFIRRA DE CARNE",
	"ESFIRRA DE FRANGO",
	"ESFIRRA DE QUEIJO",
	"BOLINHA DE QUEIJO",
	"SANDUÍCHE NATURAL"
	
	
	"CROISSANT DE LEITE NINHO",
	"CROISSANT DE NUTELLA",
	"CROISSANT DE CHOCOLATE",
	"DONUT DE DOCE DE LEITE",
	"DONUT DE BRIGADEIRO",
	"DONUT DE LEITE NINHO",
	"CUPCAKE DE CENOURA COM CHOCOLATE",
	"CUPCAKE DE BRIGADEIRO",
	"CUPCAKE DE MORANGO COM NINHO",
	"PUDIM DO WAGUINHO",
	"BOLO DE CHOCOLATE",
	"BOLO DE BAUNILHA",
	"BOLO DE MORANGO",
	"COOKIE DE CHOCOLATE",
	"COOKIE DE RED VELVET",
	"COOKIE DE NUTELLA",
	
	
	"CHÁ DE CAMOMILA",
	"CHÁ CIDREIRA",
	"CHÁ DE ERVA DOCE",
	"CAFÉ COM LEITE",
	"CAFÉ TRADICIONAL",
	"CAPUCCINO",
	"COCA COLA",
	"FANTA LARANJA",
	"GUARANÁ",
	"ÁGUA",
	"SUCO DE LARANJA",
	"SUCO DE UVA",
	"SUCO DE MARACUJÁ"
};

char produtos_tipo[40] = {
	'S','S','S','S','S','S','S','S','S','S','S',
	'D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D',
    'B','B','B','B','B','B','B','B','B','B','B','B','B',
};

float precos[QP] = {
	6.50, 6.50, 7.00,
	10.00, 10.00, 12.00,
	6.00, 6.00, 6.00,
	5.50, 8.50,
	
	12.00, 12.00, 9.00,
	12.00, 12.00, 10.00,
	8.00, 8.00, 7.67, 8.00,
	 12.00, 10.00,
	10.00, 10.00, 12.00,
	15.00,
	
	6.00, 6.00, 6.00,
	6.00, 5.00, 8.00,
	5.00, 5.00, 5.00,
	3.00, 6.00, 6.00,
	6.00
};

int estoque[QP] = {
	50, 50, 50,
	50, 50, 50,
	50, 50, 50,
	50, 50, 
	
	50, 50, 50, 50,
	50, 50, 50, 50,
	50, 50, 50, 50,
	50, 50, 50, 50,
	
	100, 100, 100,
	100, 100, 100,
	100, 100, 100,
	100, 100, 100,
	100
};

float compras[QP] = {
	0, 0, 0,
	0, 0, 0,
	0, 0, 0,
	0, 0,
	
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	
	0, 0, 0,
	0, 0, 0,
	0, 0, 0,
	0, 0, 0,
	0
};





// MOSTRAR PRODUTOS


void mostra_produtos_s() {
			
	printf("\n\n ===== SALGADOS =====\n\n");

	for(int i = 0; i < 10; i++) {

		printf("%d - %s -- R$ %.2f -- ESTOQUE: %d\n" , i, produtos[i], precos[i], estoque[i], i + 1);
		       		
		       
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
			limpar();

			break;


		case 2:
			limpar();
			mostra_produtos_d();
			limpar();
			break;


		case 3:
			limpar();
		    mostra_produtos_b();
			limpar();			
			break;


		case 4:
			limpar();
			mostra_compra();
			
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
