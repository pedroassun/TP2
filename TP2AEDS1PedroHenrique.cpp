#include <iostream>
#include <windows.h>
using namespace std;

#define MAXTAM 10
#define MAX_ENTREGA 7

int total = 0;

string A[4] = {"Suco", "Hambúrguer", "Misto", "Pizza"};

typedef struct
{
    int codigo;
    string produtos[MAXTAM];
    float valor_pedido;
    float distancia;
} Pedido;

typedef struct
{
    Pedido Pilha[MAX_ENTREGA];
    int Topo;
} TPilha;

void TPilha_Inicializa(TPilha *p);
int TPilha_Vazia(TPilha *p);
int TPilha_Cheia(TPilha *p);
void TPilha_Empilha(TPilha *p, Pedido x);
int TPilha_Desempilha(TPilha *p);
void TPilha_Imprime(TPilha *p);
int TPilha_Tamanho(TPilha *p);
void cardapio();
void Menu();
void listagem();
void finalizaPedido();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    Menu();

    return 0;
}
void TPilha_Inicializa(TPilha *p)
{
    p->Topo = 0;
}
int TPilha_Vazia(TPilha *p)
{
    if (p->Topo == 0)
    {
        return true;
    }
    else
        return false;
}
int TPilha_Cheia(TPilha *p)
{
    if (p->Topo == MAXTAM)
    {
        cout << "Pilha cheia!";
    }
}

void finalizaPedido(){
    Pedido p;

    cout << "Por favor, digite a distância em kms da sua casa até nossa lanchonete: ";
    cin >> p.distancia;
    Menu();
}

void cardapio()
{
    cout << "Listagem de produtos dispiníveis na lanchonete\n";
    cout << "Produtos\tCódigo do produto\tPreços\n";
    cout << "1 . " << A[0] << "\t"
         << "10"
         << "\t\t\tR$ 2,00" << endl;
    cout << "2 . " << A[1] << "\t"
         << "20"
         << "\t\t\tR$ 6,00" << endl;
    cout << "3 . " << A[2] << "\t"
         << "30"
         << "\t\t\tR$ 10,00" << endl;
    cout << "4 . " << A[3] << "\t"
         << "40"
         << "\t\t\tR$ 3,00" << endl;
}

void pedido()
{
    Pedido p;
    int opc;

    cout << "Digite o código do produto que você deseja. ";
    cin >> p.codigo;
    if (p.codigo == 10)
    {
        total += 2;
        p.produtos[0] = A[0];
    }
    if (p.codigo == 20)
    {
        total += 6;
    }
    if (p.codigo == 30)
    {
        total += 10;
    }
    if (p.codigo == 40)
    {
        total += 3;
    }
    cout << "Você deseja finalizar seu pedido?\n Se sim, digite 1, se não, digite 2: ";
    cin >> opc;
    if(opc == 1){
        finalizaPedido();
    }
    if(opc == 2){
        Menu();
    }
}

void Menu()
{

    Pedido p;
    int opcao;
    int escolha;

    cout << "  **************************\n";
    cout << " |                         |\n";
    cout << " |      MENU PRINCIPAL     |\n";
    cout << " |                         |\n";
    cout << " | [1] Fazer Pedido        |\n";
    cout << " | [2] Listar Pedidos      |\n";
    cout << " | [3] Ver Cardápio        |\n";
    cout << " | [4] Consultar Pedido    |\n";
    cout << " | [5] Imprimir Entrega    |\n";
    cout << " | [6] Lançar Entrega      |\n";
    cout << " | [7] Finalizar Pedido    |\n";
    cout << " |                         |\n";
    cout << "  *************************\n";

    cout << "Escolha uma opção: " << endl;
    cin >> opcao;

    system("cls");

    switch (opcao)
    {
    case 1:
        cardapio();
        pedido();
        break;
    case 2:
        listagem();
        break;
    case 3:
        cardapio();
        cout << "Deseja fazer um pedido? Digite 1 para sim ou 2 para não\n";
        cin >> escolha;
        if (escolha == 1)
        {
            pedido();
        }
        else
        {
            Menu();
        }
        break;
    case 4:
            break;
    case 5:
            break;
    case 6:
            break;
    case 7:
            finalizaPedido();    
    }
}

void listagem()
{
    Pedido p;
    for (int i = 0; i < 1; i++)
    {
        cout << "Itens pedidos: " << p.produtos[i];
    }
    cout << "Valor do pedido: " << total;
    cout << endl; 
    Menu();
}