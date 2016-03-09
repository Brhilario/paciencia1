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
	Pilha* P;
	Carta baralho_ouro[13];
	Carta baralho_copas[13];
	Carta baralho_paus[13];
	Carta baralho_espada[13];
	int i = 0;

	preenche_baralho(baralho_ouro,'O');
	sleep(1);
	preenche_baralho(baralho_copas,'C');
	sleep(1);
	preenche_baralho(baralho_paus,'P');
	sleep(1);
	preenche_baralho(baralho_espada,'E');

	for (i=0;i<13;i++)
		printf ("%d de %c ",baralho_ouro[i].valor ,baralho_ouro[i].naipe);

	for (i=0;i<13;i++)
		printf ("%d de %c ",baralho_copas[i].valor ,baralho_copas[i].naipe);

	printf("\n");

	L = Inicializar_Lista();
    //L=Insere_Inicio(L,47);
    //L=Insere_Inicio(L,48);
	//listaM=lst_insere(listaM,49);
    L = Insere_Fim (L,30,'O',0);
    //L = Insere_Fim (L,35);
   // Insere_Fim (listaM,38);
    Imprime(L);

    //P = pilha_cria();

    ListaMesa* L1 = Inicializar_Lista();
    ListaMesa* L2 = Inicializar_Lista();
    ListaMesa* L3 = Inicializar_Lista();
    ListaMesa* L4 = Inicializar_Lista();
    ListaMesa* L5 = Inicializar_Lista();
    ListaMesa* L6 = Inicializar_Lista();
    ListaMesa* L7 = Inicializar_Lista();

    preenche_pilhasfileira (baralho_ouro,baralho_copas,baralho_paus,baralho_espada,L1,L2,L3,L4,L5,L6,L7);
    printf ("L1 = ");
    Imprime(L1);
    printf("\n");
    printf ("L2 = ");
    Imprime(L2);

	return 0;
}