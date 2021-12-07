#include <iostream>
#include <windows.h>
using namespace std;

# define MAXTAM 10
# define MAX_ENTREGA 7

int total=0;

typedef struct {
int codigo ;
int produtos [ MAXTAM ];
float valor_pedido ;
float distancia ;
} Pedido ;

typedef struct {
Pedido Pilha [ MAX_ENTREGA ];
int Topo ;
} TPilha ;

void TPilha_Inicializa ( TPilha *p);
int TPilha_Vazia ( TPilha *p);
int TPilha_Cheia ( TPilha *p);
void TPilha_Empilha ( TPilha *p, Pedido x);
int TPilha_Desempilha ( TPilha *p);
void TPilha_Imprime ( TPilha *p);
int TPilha_Tamanho ( TPilha *p);
void cardapio();
void Menu();
void listagem();

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

    Menu();
    
    return 0;
}
void TPilha_Inicializa ( TPilha *p){
    p->Topo = 0;
}
int TPilha_Vazia ( TPilha *p){
    if(p->Topo == 0){
        return true;
    }else return false;
}
int TPilha_Cheia ( TPilha *p){
    if(p->Topo == MAXTAM){
        cout << "Pilha cheia!";
    }
}
void cardapio(){
    cout << "Listagem de produtos dispiníveis na lanchonete\n";
    cout << "Produtos\tCódigo do produto\tPreços\n";
    cout << "Suco.......\t" << "10" << "\t\t\tR$ 2,00" << endl;
    cout << "Hambúrguer.\t" << "20" << "\t\t\tR$ 6,00" << endl;
    cout << "Pizza......\t" << "30" << "\t\t\tR$ 10,00" << endl;
    cout << "Misto......\t" << "40" << "\t\t\tR$ 3,00" << endl;
}

void Menu(){

    Pedido p;
    int opcao;

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
    cout << " |                         |\n";
    cout << "  *************************\n";

    cout << "Escolha uma opção: " << endl;
    cin >> opcao;

    system("cls");

    switch (opcao){
    case 1:
        cardapio();
        cout << "Digite o código do produto que você deseja. ";
        cin >> p.codigo;
        if(p.codigo == 10){
            cout << "Suco\n";
            total += 2;
        }
        if(p.codigo == 20){
            cout << "Hambúrguer";
            total += 6;
        }
        if(p.codigo == 30){
            total += 10;
        }
        if(p.codigo == 40){
            total += 3;
        }


        return Menu();
        break;
    case 2:
    listagem();
    }
}

void listagem(){
    cout << "Valor do pedido: " << total;
}