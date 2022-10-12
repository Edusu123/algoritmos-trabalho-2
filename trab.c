#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include <wincon.h>

// salvar o arquivo com codifica��o ISO 8859-1

static const char senha1[] = "123456";

void cursorVisivel(bool status);
void gotoxy(int x, int y);
void cursorVisivel(bool status);
bool senha(bool repete);
bool menu(bool repete);
void saque();
void cheque();

void main()
{
    setlocale(LC_ALL, "Portuguese");

    SetConsoleTitle("Trabalho 2 (strings) - Eduardo Conde Pires");

    cursorVisivel(true);

    int repete = false;
    while (!senha(repete))
    {
        repete = true;
    }

    repete = false;
    while (menu(repete))
    {
        repete = true;
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

bool menu(bool repete)
{
    system("cls");
    gotoxy(3, 5);
    printf("Sistema banc�rio da Weblands!!");

    gotoxy(5, 7);
    printf("1. Saque");
    gotoxy(5, 8);
    printf("2. Cheque");
    gotoxy(5, 9);
    printf("3. Sair");

    if (repete)
    {
        gotoxy(7, 13);
        printf("� necess�rio inserir uma op��o v�lida!");
    }

    cursorVisivel(true);
    int dec = 0;

    gotoxy(5, 11);
    printf("Op��o: ");

    do
    {
        scanf("%d", &dec);

        switch (dec)
        {
        case 1:
            saque();
            return true;
            break;
        case 2:
            cheque();
            return true;
            break;
        case 3:
            return false;
            break;
        default:
            return true;
            break;
        }
    } while (dec < 1 || dec > 2);
}

void saque()
{
    system("cls");
}

void cheque()
{
    system("cls");

    double num;
    gotoxy(5, 11);
    printf("Digite a quantidade de Bits desejada para o cheque: ");
    scanf("%lf", &num);

    gotoxy(10, 13);
    printf("| Ilhas Weblands | Banco Central | Ag�ncia 01 | Conta 19502022-0 | B$ %.2lf |", num);
    gotoxy(10, 14);
    printf("| Pague por este cheque a quantia de:");
    // centena(num);
    // dezena(num);
    // unidade(num);
    system("pause>NUL");
}
