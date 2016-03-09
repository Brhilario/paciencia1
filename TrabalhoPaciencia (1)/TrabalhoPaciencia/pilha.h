struct pilha {
	 Carta * prim;
};
typedef struct pilha Pilha;

Pilha* pilha_cria (void);
void pilha_push (Pilha* p, float v);
float pilha_pop (Pilha* p);
int pilha_vazia (Pilha* p);
void pilha_libera (Pilha* p);

Pilha* pilha_cria (void) {
    Pilha* p = (Pilha*) malloc (sizeof(Pilha));
    p->prim = NULL;
    return p;
}

void Insere_PilhaDescarte (Pilha* carta, float v){


}