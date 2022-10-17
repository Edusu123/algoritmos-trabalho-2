#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include <wincon.h>

// salvar o arquivo com codifição ISO 8859-1

static const char senha1[] = "123456";
static const char *centenas[] = {"", "Cento", "Duzentos", "Trezentos", "Quatrocentos", "Quinhentos", "Seiscentos", "Setecentos", "Oitocentos", "Novecentos"};
static const char *onze_dezenove[] = {"", "Onze", "Doze", "Treze", "Quatorze", "Quinze", "Dezesseis", "Dezessete", "Dezoito", "Dezenove"};
static const char *unidades[] = {"Zero", "Um", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove"};
static const char *dez_noventa[] = {"", "Dez", "Vinte", "Trinta", "Quarenta", "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa"};
static const float notas[] = {100, 50, 20, 10, 5, 2, 1, 0.5, 0.25, 0.1, 0.01};

void cursorVisivel(bool status);
void gotoxy(int x, int y);
void cursorVisivel(bool status);
bool senha(bool repete);
void menu();
void saque();
void calculoNotas(double num);
void cheque();
void centena(double num);
void dezena(double num);
void unidade(double num);
void centavos(double num);

void main()
{
    setlocale(LC_ALL, "Portuguese");

    SetConsoleTitle("Trabalho 2 (strings) - Eduardo Conde Pires e Renato Paes da Rosa Gonzaga de Oliveira");

    cursorVisivel(true);

    int repete = false;
    while (!senha(repete))
    {
        repete = true;
    }

    menu();
}

void cursorVisivel(bool status)
{
    if (status)
    {
        CONSOLE_CURSOR_INFO cursor = {1, FALSE};
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    }
    else
    {
        CONSOLE_CURSOR_INFO cursor = {1, TRUE};
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    }
}

void gotoxy(int x, int y)
{
    COORD c;

    c.X = x - 1;
    c.Y = y - 1;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

bool senha(bool repete)
{
    char password[128], c;
    int index = 0;

    system("cls");
    gotoxy(3, 10);
    printf("Bem-Vindo!");
    gotoxy(3, 12);
    printf("Insira a senha: ");

    if (repete)
    {
        gotoxy(3, 14);
        printf("Senha incorreta! Tente novamente.");
        gotoxy(19, 12);
    }

    while ((c = getch()) != 13) // ASCII do enter
    {
        if (index < 0)
            index = 0;

        if (c == 8) // ASCII do backspace
        {
            putch('\b');
            putch(' ');
            putch('\b');
            index--;
            continue;
        }

        password[index++] = c;
        putch('*');
    }

    password[index] = '\0';

    if (strcmp(password, senha1) == 0)
        return true;

    return false;
}

void menu()
{
    cursorVisivel(true);
    int dec = 0;

    do
    {
        system("cls");
        gotoxy(3, 5);
        printf("Sistema bancário da Weblands!!");

        gotoxy(5, 7);
        printf("1. Saque");
        gotoxy(5, 8);
        printf("2. Cheque");
        gotoxy(5, 9);
        printf("3. Sair");

        gotoxy(5, 11);
        printf("Opção: ");

        scanf("%d", &dec);

        switch (dec)
        {
        case 1:
            saque();
            break;
        case 2:
            cheque();
            break;
        case 3:
            return;
            break;
        default:
            break;
        }
    } while (dec < 1 || dec > 2);
}

void saque()
{
    system("cls");

    double num;
    gotoxy(5, 11);
    printf("Digite o valor do saque: ");
    scanf("%lf", &num);

    calculoNotas(num);
}

void calculoNotas(double num)
{
    int linha = 13;

    for (int i = 0; i < 11; i++)
    {
        int qtdNota = num / notas[i];

        if (qtdNota > 0)
        {
            gotoxy(10, linha);

            if (notas[i] > 1)
                printf("%d notas de B$%.2lf", qtdNota, notas[i]);
            else
                printf("%d moedas de B$%.2lf", qtdNota, notas[i]);

            linha += 1;
        }

        num = num - (qtdNota * notas[i]);
    }
}

void cheque()
{
    system("cls");

    double num;
    gotoxy(5, 11);
    printf("Digite a quantidade de Bits desejada para o cheque: ");
    scanf("%lf", &num);

    gotoxy(10, 13);
    printf("| Ilhas Weblands | Banco Central | Agência 01 | Conta 19502022-0 | B$ %.2lf |", num);
    gotoxy(10, 14);
    printf("| Pague por este cheque a quantia de:");

    centena(num);
    dezena(num);
    unidade(num);
    centavos(num);

    system("pause>NUL");
}

void centena(double num)
{

    if (num == 100)
    {
        printf(" Cem");
        return;
    }

    int c;
    c = floor(num) / 100;

    if (c == 0)
    {
        return;
    }

    printf(" %s", centenas[c]);
}

void dezena(double num)
{
    int c, d, u, od, i_num;
    i_num = floor(num);
    c = i_num / 100;
    d = (i_num / 10) - (c * 10);
    u = i_num % 10;
    od = (d * 10) + u;

    if (c > 0 && d > 0)
    {
        printf(" e");
    }

    if (c == 0 && d == 0)
    {
        return;
    }

    if (od > 10 && od < 20)
    {
        printf(" %s", onze_dezenove[od - 10]);
    }
    else
    {
        if (u == 0)
        {
            printf(" %s", dez_noventa[d]);
        }
        else
        {
            printf(" %s", dez_noventa[d]);
        }
    }
}

void unidade(double num)
{
    int u, d, c, i_num;
    i_num = floor(num);
    d = (i_num % 100) / 10;
    u = i_num % 10;
    c = i_num / 100;

    if (u == 0 && d == 0 && c == 0)
    {
        printf(" %s", unidades[0]);
        return;
    }

    if (u == 0)
    {
        return;
    }

    if (d == 1)
    {
        return;
    }

    if (c > 0 || d > 1)
    {
        printf(" e");
    }

    if (d != 1)
    {
        printf(" %s", unidades[u]);
    }
}

void centavos(double num)
{
    double corrigido = (num - floor(num)) * 100;

    printf(" e");

    dezena(corrigido);
    unidade(corrigido);

    printf(" centBits");
}
