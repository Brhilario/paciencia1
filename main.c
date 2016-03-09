#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Para gerar numeros aleatorios
#include <unistd.h>
#include "lista.h"
#include "pilha.h"
#include "processamento.h"

int main (){
	ListaMesa* L;
	Pilha* PBaralho;
	Pilha* PEstoque;
	Pilha* PDescarte;
	Pilha* POuro;
	Pilha* PCopas;
	Pilha* PEspadas;
	Pilha* PPaus;
	Carta baralho_ouro[13];
	Carta baralho_copas[13];
	Carta baralho_paus[13];
	Carta baralho_espada[13];
    char escolha1[3];
    char escolha2[3];
   	ListaMesa* listajogada;
	int i = 0;
	int escolha,jogar,escolherLista1,escolherLista2,jogarcarta;
	Carta carta,carta2;
	//preenche 4 vetores cada um com um naipe montando aleatoriamente
	preenche_baralho(baralho_ouro,'O');
	sleep(1);
	preenche_baralho(baralho_copas,'C');
	sleep(1);
	preenche_baralho(baralho_paus,'P');
	sleep(1);
	preenche_baralho(baralho_espada,'E');
	//testar na tela, não será usado
	for (i=0;i<13;i++)
		printf ("%d de %c ",baralho_ouro[i].valor ,baralho_ouro[i].naipe);

	for (i=0;i<13;i++)
		printf ("%d de %c ",baralho_copas[i].valor ,baralho_copas[i].naipe);

	for (i=0;i<13;i++)
		printf ("%d de %c ",baralho_espada[i].valor ,baralho_espada[i].naipe);

	for (i=0;i<13;i++)
		printf ("%d de %c ",baralho_paus[i].valor ,baralho_paus[i].naipe);

	printf("\n");


	//cria as 7 listas de jogo da mesa
	ListaMesa* L1 = Inicializar_Lista();
	ListaMesa* L2 = Inicializar_Lista();
	ListaMesa* L3 = Inicializar_Lista();
	ListaMesa* L4 = Inicializar_Lista();
	ListaMesa* L5 = Inicializar_Lista();
	ListaMesa* L6 = Inicializar_Lista();
	ListaMesa* L7 = Inicializar_Lista();
	//monta a pilha de baralho com todas as cartas.
	PBaralho = pilha_cria ();
	PBaralho = baralho(baralho_ouro,baralho_copas,baralho_paus,baralho_espada,PBaralho);


	// passa a pilha de baralho para montar as 7 listas da mesa;
	L1 = pilha_mesa(PBaralho,L1,1);
	L2 = pilha_mesa(PBaralho,L2,2);
	L3 = pilha_mesa(PBaralho,L3,3);
	L4 = pilha_mesa(PBaralho,L4,4);
	L5 = pilha_mesa(PBaralho,L5,5);
	L6= pilha_mesa(PBaralho,L6,6);
	L7 = pilha_mesa(PBaralho,L7,7);
	//pilha de estoque para guardar as cartas que sobraram da montagem da mesa
	PEstoque = pilha_cria();
	PEstoque = Pilha_estoque(PEstoque,PBaralho);
	//cria a lista de descarte que vai guardar as cartas não utilizadas no estoque
	PDescarte = pilha_cria();
	
	//cria as pilhas de naipes
	POuro = pilha_cria();;
	PCopas = pilha_cria();;
	PEspadas = pilha_cria();;
	PPaus = pilha_cria();;	
	
	//monta as listas na mesa
	printf("  L1    L2    L3    L4    L5    L6    L7\n ");
	ImpListaMesaComp(L1,L2,L3,L4,L5,L6,L7);
	//retira uma carta da pilha de estoque e coloca na mesa
	printf("estoque      \n");
	carta =  pilha_pop(PEstoque);
	printf("carta = %d %c %d\n", carta.valor,carta.naipe,carta.flag);

	printf("jogar? 0 - nao, 1 - sim \n");
	scanf("%d",&jogar);
	while (jogar == 1){
		printf("escolha uma jogada  (0 - pegar outra carta, 1 - usar a carta, 2 - alterar lista)");
		scanf("%d",&escolha);
	//	carta =  pilha_pop(PEstoque);
		if (escolha == 0){
			//escolhendo outra carta vamos pegar a que estava na mesa e guardar na pilha de descarte
			pilha_push (PDescarte,carta.flag, carta.naipe, carta.valor);
			
			if (pilha_vazia (PEstoque) == 1){
     	 	    PEstoque = Pilha_estoque(PEstoque,PDescarte);
			 					                      	 	
		 	}  
			//imprimi novamente a mesa
			printf("  L1    L2    L3    L4    L5    L6    L7\n ");
			ImpListaMesaComp(L1,L2,L3,L4,L5,L6,L7);
			//pega outra carta do estoque
			printf("estoque      \n");
			carta =  pilha_pop(PEstoque);
			printf("carta = %d %c %d\n", carta.valor,carta.naipe,carta.flag);
			//tirando a carta da pilha de descarte e imprimindo somente para testar, não será usado
		//	carta2 =pilha_pop(PDescarte);
		//	printf("carta descarte = %d %c %d\n", carta2.valor,carta2.naipe,carta2.flag);
		} else
		if (escolha == 1){
		   printf("Deseja inserir nas pilhas de fileiras(1) ou na Pilha de Naipe(2)");
		   scanf("%d",&jogarcarta);
		   if (jogarcarta ==1){
		 	printf( "escolha a lista onde deseja inserir (1,2,3,4,5,6,7)");
		  	scanf("%d",&escolherLista1);
		  	switch(escolherLista1){
		  				case 1 :Insere_Fim (L1, carta.valor, carta.naipe, 1) ;break;
		  				case 2 :Insere_Fim (L2, carta.valor, carta.naipe, 1) ;break;
		  				case 3 :Insere_Fim (L3, carta.valor, carta.naipe, 1) ;break;
		  				case 4 :Insere_Fim (L4, carta.valor, carta.naipe, 1) ;break;
		  				case 5 :Insere_Fim (L5, carta.valor, carta.naipe, 1) ;break;
		  				case 6 :Insere_Fim (L6, carta.valor, carta.naipe, 1) ;break;
		  				case 7 :Insere_Fim (L7, carta.valor, carta.naipe, 1) ;break;
		  				default:printf("Operadorinvalido!\n");break;
		  	}
		 //  	printf("  L1    L2    L3    L4    L5    L6    L7\n ");
		//	ImpListaMesaComp(L1,L2,L3,L4,L5,L6,L7);	
		//	printf("estoque      \n");
		//	carta =  pilha_pop(PEstoque);
		//	printf("carta = %d %c %d\n", carta.valor,carta.naipe,carta.flag);
	 	} else {
				switch(carta.naipe){
		  				case 'O' :pilha_push(POuro, 1, carta.naipe, carta.valor) ;break;
		  				case 'E' :pilha_push(PEspadas, 1, carta.naipe, carta.valor) ;break;
		  				case 'P' :pilha_push(PPaus, 1, carta.naipe, carta.valor) ;break;
		  				case 'C' :pilha_push(PCopas, 1, carta.naipe, carta.valor) ;break;
		  				default:printf("Operadorinvalido!\n");break;
		  		}	 		
			 }
		 
		   	printf("  L1    L2    L3    L4    L5    L6    L7\n ");
		 	ImpListaMesaComp(L1,L2,L3,L4,L5,L6,L7);	
		 	printf("estoque      \n");
		 	carta =  pilha_pop(PEstoque);
		 	printf("carta = %d %c %d\n", carta.valor,carta.naipe,carta.flag);
		 	printf("carta pilha naipe %d %c",POuro->prim->info.valor,POuro->prim->info.naipe);
		 
		 } else
	 	if (escolha = 2){
	 		printf("escolha o número, o naipe da carta, a lista que deseja tirar e a lista que deseja inserir (nessa ordem)");
	 		scanf("%d %c %d %d",&carta2.valor,&carta2.naipe,&escolherLista1,&escolherLista2);
	 		        listajogada = Inicializar_Lista();
            	   	switch(escolherLista1){
		  				case 1 :listajogada = quebralista(L1, carta2.valor, carta2.naipe) ;break;
		  				case 2 :listajogada = quebralista(L2, carta2.valor, carta2.naipe) ;break;
		  				case 3 :listajogada = quebralista(L3, carta2.valor, carta2.naipe) ;break;
		  				case 4 :listajogada = quebralista(L4, carta2.valor, carta2.naipe) ;break;
		  				case 5 :listajogada = quebralista(L5, carta2.valor, carta2.naipe) ;break;
		  				case 6 :listajogada = quebralista(L6, carta2.valor, carta2.naipe) ;break;
		  				case 7 :listajogada = quebralista(L7, carta2.valor, carta2.naipe) ;break;
		  				default:printf("Operadorinvalido!\n");break; 
	 		 		} 
	 		 		switch(escolherLista2){
		  				case 1 :L1=inserelistafim(L1, listajogada) ;break;
		  				case 2 :L2=inserelistafim(L2, listajogada) ;break;
		  				case 3 :L3=inserelistafim(L3, listajogada) ;break;
		  				case 4 :L4=inserelistafim(L4, listajogada) ;break;
		  				case 5 :L5=inserelistafim(L5, listajogada) ;break;
		  				case 6 :L6=inserelistafim(L6, listajogada) ;break;
		  				case 7 :L7=inserelistafim(L7, listajogada) ;break;
		  				default:printf("Operadorinvalido!\n");break; 
	 		 		} 
				printf("\n");	   
	 		 	Imprime(listajogada);
                printf("\n");
				printf("  L1    L2    L3    L4    L5    L6    L7\n ");
			    ImpListaMesaComp(L1,L2,L3,L4,L5,L6,L7);					  	
	 		 		
	 	}
	 	      		

	}

	return 0;
}
