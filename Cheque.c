#include <conio.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include <wincon.h>
// Corrigir o 117
static const char senha1[] = "123456";
static const char *centenas[] = {"", "Cento", "Duzentos", "Trezentos", "Quatrocentos", "Quinhentos", "Seiscentos", "Setecentos", "Oitocentos", "Novecentos"};
static const char *onze_dezenove[] = {"", "Onze", "Doze", "Treze", "Quatorze", "Quinze", "Dezesseis", "Dezessete", "Dezoito", "Dezenove"};
static const char *unidades[] = {"Zero", "Um", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove"};
static const char *dez_noventa[] = {"", "Dez", "Vinte", "Trinta", "Quarenta", "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa"};

void cursorVisivel(bool status);
void gotoxy(int x, int y);
void cursor(bool status);
bool senha(bool repete);
void cheque();
void centena(double numero);
void dezena(double num);
void unidade(double num);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    SetConsoleTitle("Trabalho 2 (strings) - Eduardo Conde Pires");

    cursorVisivel(true);
    int repete = false;

    // while (!senha(repete))
    // {
    //     repete = true;
    // }

    cheque();
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

void cheque()
{
    double num;

    system("cls");
    printf("Digite a quantidade de Bits desejada para o cheque: ");
    scanf("%lf", &num);

    system("cls");
    printf("\t\t| Ilhas Weblands | Banco Central | Agência 01 | Conta 19502022-0 | B$ %.2lf |\n", num);
    printf("\t\t| Pague por este cheque a quantia de:");
    centena(num);
    dezena(num);
    unidade(num);
    printf("\n\n");
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
