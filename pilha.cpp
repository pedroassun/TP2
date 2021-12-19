#include <iostream>
#include "pilha.hpp"

using namespace std;

int id = 0;

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
        return 1;
        system("pause");
    }
    return 0;
}
void TPilha_Empilha(TPilha *p, Pedido x)
{
    if (TPilha_Cheia(p) == 1)
    {
        cout << "\nPilha cheia\n";
    }
    else
    {
        p->Topo++;
        p->Pilha[p->Topo] = x;
    }
}

int TPilha_Desempilha(TPilha *p, Pedido x)
{
    int aux; // Receber o valor da pilha que será desempilhado
    if (TPilha_Vazia(p) == 1)
    {
        cout << "\nImpossível desempilhar. Pilha vazia\n";
    }
    else
    {
        aux = p->Topo;
        p->Topo--;
        cout << "Pedido entregue.\n\n";
        return aux;
    }
}


void TPilha_Imprime(TPilha *p)
{
    if (TPilha_Vazia(p) == 1)
    {
        cout << "\nPilha vazia\n";
        return;
    }
    for (int i = p->Topo; i >= 0; i--)
    {
        cout << p->Pilha[i].codigo << "\n";
        cout << p->Pilha[i].valor_pedido << "\n";
        cout << p->Pilha[i].distancia << "\n";
    }
}

int TPilha_Tamanho(TPilha *p)
{
    return p->Topo + 1;
}

void cardapio()
{
    cout << "\n******************************************************* \n";
    cout << "Listagem de produtos disponíveis na lanchonete\n";
    cout << "******************************************************* \n\n";
    cout << "Produtos\tCódigo do produto\tPreços\n";
    cout << "Suco.......\t"
         << "1"
         << "\t\t\tR$ 2,00" << endl;
    cout << "Hambúrguer.\t"
         << "2"
         << "\t\t\tR$ 6,00" << endl;
    cout << "Pizza......\t"
         << "3"
         << "\t\t\tR$ 10,00" << endl;
    cout << "Misto......\t"
         << "4"
         << "\t\t\tR$ 3,00" << endl
         << endl;
}

void Menu(Pedido *pi, TPilha *pilha)
{
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

    switch (opcao)
    {
    case 1:
        if(pi->codigo = MAXTAM){
            cout << "Pilha cheia\n";
            system("pause");
            return Menu(pi, pilha);
        }
        cardapio();
        int quantidade, codigo;
        cout << "Digite a distância até sua casa: ";
        cin >> pi->distancia;
        cout << "Digite o código do produto que você deseja: ";
        cin >> codigo;
        cout << "Digite a quantidade que você deseja: ";
        cin >> quantidade;
        while (quantidade <= 0)
        { // Exige pelo menos 1 unidade
            cout << "Quantidade precisa ser maior que zero\n";
            cout << "Quantidade: ";
            cin >> quantidade;
            cout << "\n";
        }

        switch (codigo)
        {
        case 1:
            cout << "\n******************************************************* \n";
            cout << "   " << quantidade << " SUCO(S) ADICIONADO(S) À SACOLA    \n";
            cout << "******************************************************* \n";
            cout << "\n";
            p.codigo = pi->codigo++;
            p.valor_pedido += 2 * quantidade;

            system("pause");
            TPilha_Empilha(pilha, p);
            system("cls");
            break;

        case 2:
            cout << "\n******************************************************* \n";
            cout << "" << quantidade << " HAMBURGUER(S) ADICIONADO(S) À SACOLA \n";
            cout << "******************************************************* \n";
            cout << "\n";
            p.codigo = pi->codigo++;
            p.valor_pedido += 6 * quantidade;

            system("pause");
            TPilha_Empilha(pilha, p);
            system("cls");
            break;

        case 3:
            cout << "\n******************************************************* \n";
            cout << "   " << quantidade << " PIZZA(S) ADICIONADO(S) À SACOLA   \n";
            cout << "******************************************************* \n";
            cout << "\n";
            p.codigo = pi->codigo++;
            p.valor_pedido += 10 * quantidade;

            system("pause");
            TPilha_Empilha(pilha, p);
            system("cls");
            break;

        case 4:
            cout << "\n******************************************************* \n";
            cout << "  " << quantidade << " MISTO(S) ADICIONADO(S) À SACOLA    \n";
            cout << "******************************************************* \n";
            cout << "\n";
            p.codigo = pi->codigo++;
            p.valor_pedido += 3 * quantidade;

            system("pause");
            TPilha_Empilha(pilha, p);
            system("cls");
            break;

        default:
            cout << "\nERRO ~~ CÓDIGO DE PRODUTO INEXISTENTE \n";
            cout << "\n";
            system("cls");
            break;
        }
        return Menu(pi, pilha);
        break;
    case 2:
        listagem(pi, pilha);
        system("pause");
        system("cls");
        Menu(pi, pilha);
        break;
    case 3:
        cardapio();
        Menu(pi, pilha);
    case 4:
        consulta(pi, pilha);
        system("pause");
        Menu(pi, pilha);
    case 5:
        TPilha_Desempilha(pilha, );
        Menu(pi, pilha);
    }
}

void listagem(Pedido *pi, TPilha *p)
{
    cout << "\n******************************************************* \n";
    cout << "                    Pedido nº " << pi->codigo << "                \n";
    cout << "******************************************************* \n\n";
    for (int i = p->Topo; i > 0; i--)
    {
        cout << "Código do pedido: " << p->Pilha[i].codigo << "\n";
        cout << "Valor total do pedido: R$ " << p->Pilha[i].valor_pedido << "\n";
    }
}
void consulta(Pedido *pi, TPilha *p)
{
    int cod;
    cout << pi->codigo << endl;
    cout << "Digite o código do pedido que você está procurando: ";
    cin >> cod;
    if (cod == pi->codigo)
    {
        for (int i = p->Topo; i > 0; i--)
        {
            cout << "Código do pedido: " << pi->codigo << endl;
            cout << "Valor total do pedido: R$ " << p->Pilha[i].valor_pedido << "\n\n";
        }
    }
    else
    {
        cout << "Pedido não encontrado";
    }
}