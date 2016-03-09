
//Função para preencher os baralhos passando o ponteiro do vetor e o naipe
void preenche_baralho(Carta* vetor_baralho,char naipe );

void preenche_pilhasfileira (Carta* baralho_ouro, Carta* baralho_copas, Carta*baralho_paus,Carta* baralho_espada, ListaMesa* L1,ListaMesa* L2,ListaMesa* L3,ListaMesa* L4,ListaMesa* L5,ListaMesa* L6,ListaMesa* L7);

void preenche_baralho(Carta* vetor_baralho,char naipe ){
    srand(time(NULL)); // Sequencias diferentes de numeros aleatorios

    int i = 0;
    int j = 0;
    int random;
    int achou_igual = 0;
    vetor_baralho[0].valor = rand() % 13 + 1;
    vetor_baralho[0].naipe = naipe;
    vetor_baralho[0].flag = 0;

    for (i=1;i<13;i++){
        random = rand() % 13 + 1;
        for (j=0;j<i;j++){
            if (vetor_baralho[j].valor == random){
                i--;
                break;
            }
        }
        if (j>=i){
            vetor_baralho[i].valor = random;
            vetor_baralho[i].naipe = naipe;
            vetor_baralho[i].flag = 0;
        }
    }
}

void preenche_pilhasfileira (Carta* baralho_ouro,Carta* baralho_copas, Carta*baralho_paus,Carta* baralho_espada, ListaMesa* L1,ListaMesa* L2,ListaMesa* L3,ListaMesa* L4,ListaMesa* L5,ListaMesa* L6,ListaMesa* L7){
    int i;

    for (i=0; i++; i<14) {
        ListaMesa* ouro = (ListaMesa*) malloc (sizeof (ListaMesa));
        ListaMesa* copas = (ListaMesa*) malloc (sizeof (ListaMesa));
        ListaMesa* espadas = (ListaMesa*) malloc (sizeof (ListaMesa));
        ListaMesa* paus = (ListaMesa*) malloc (sizeof (ListaMesa));
        ouro->info = baralho_ouro[i];
        copas->info = baralho_copas[i];
        espadas->info = baralho_espada[i];
        paus->info = baralho_paus[i];

        if (i==0){
            L1 = Insere_Fim(L1,ouro->info.valor, ouro->info.naipe, ouro->info.flag);
            L2 = Insere_Fim(L2,copas->info.valor, copas->info.naipe, copas->info.flag);
            L2 = Insere_Fim(L2,espadas->info.valor, espadas->info.naipe, espadas->info.flag);
            L3 = Insere_Fim(L2,paus->info.valor, paus->info.naipe, paus->info.flag);
        }

        if (i==1){
            L3 = Insere_Fim(L2,copas->info.valor, copas->info.naipe, copas->info.flag);
            L3 = Insere_Fim(L2,espadas->info.valor, espadas->info.naipe, espadas->info.flag);
            L4 = Insere_Fim(L2,paus->info.valor, paus->info.naipe, paus->info.flag);
            L4 = Insere_Fim(L2,ouro->info.valor, ouro->info.naipe, ouro->info.flag);
        }

        if (i==2){
            L4 = Insere_Fim(L2,espadas->info.valor, espadas->info.naipe, espadas->info.flag);
            L4 = Insere_Fim(L2,ouro->info.valor, ouro->info.naipe, ouro->info.flag);
            L5 = Insere_Fim(L2,copas->info.valor, copas->info.naipe, copas->info.flag);
            L5 = Insere_Fim(L2,paus->info.valor, paus->info.naipe, paus->info.flag);
        }

        if (i==3){
            L5 = Insere_Fim(L2,paus->info.valor, paus->info.naipe, paus->info.flag);
            L5 = Insere_Fim(L2,copas->info.valor, copas->info.naipe, copas->info.flag);
            L5 = Insere_Fim(L2,ouro->info.valor, ouro->info.naipe, ouro->info.flag);
            L6 = Insere_Fim(L2,espadas->info.valor, espadas->info.naipe, espadas->info.flag);
        }

        if (i==4){
            L6 = Insere_Fim(L2,paus->info.valor, paus->info.naipe, paus->info.flag);
            L6 = Insere_Fim(L2,ouro->info.valor, ouro->info.naipe, ouro->info.flag);
            L6 = Insere_Fim(L2,espadas->info.valor, espadas->info.naipe, espadas->info.flag);
            L6 = Insere_Fim(L2,copas->info.valor, copas->info.naipe, copas->info.flag);
        }

        if (i==5){
            L6 = Insere_Fim(L2,ouro->info.valor, ouro->info.naipe, ouro->info.flag);
            L7 = Insere_Fim(L2,espadas->info.valor, espadas->info.naipe, espadas->info.flag);
            L7 = Insere_Fim(L2,copas->info.valor, copas->info.naipe, copas->info.flag);
            L7 = Insere_Fim(L2,paus->info.valor, paus->info.naipe, paus->info.flag);
        }

        if (i==6) {
            L7 = Insere_Fim(L2,copas->info.valor, copas->info.naipe, copas->info.flag);
            L7 = Insere_Fim(L2,ouro->info.valor, ouro->info.naipe, ouro->info.flag);
            L7 = Insere_Fim(L2,paus->info.valor, paus->info.naipe, paus->info.flag);
            L7 = Insere_Fim(L2,espadas->info.valor, espadas->info.naipe, espadas->info.flag);
        }



    }


}