#ifndef PILHA_H
#define PILHA_H

# define MAXTAM 3
# define MAX_ENTREGA 7

typedef struct {
    int codigo=0;
    float valor_pedido = 0.00;
    int distancia;
} Pedido;

typedef struct {
    Pedido Pilha[MAX_ENTREGA];
    int Topo;
} TPilha;

void TPilha_Inicializa (TPilha *p);
int TPilha_Vazia (TPilha *p);
int TPilha_Cheia (TPilha *p);
void TPilha_Empilha (TPilha *p, Pedido x);
int TPilha_Desempilha (TPilha *p, Pedido x);
void TPilha_Imprime (TPilha *p);
int TPilha_Tamanho (TPilha *p);

void Menu(TPilha *p);
void cardapio();
void listagem(Pedido *pi, TPilha *p);
void finalizaPedido();
void consulta(Pedido *p,TPilha *pi);

#endif