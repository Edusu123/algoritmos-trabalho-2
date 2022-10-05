#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include <wincon.h>

static const char senha1[] = "123456";

void cursorVisivel(bool status);
void gotoxy(int x, int y);
void cursor(bool status);
bool senha(bool repete);

void main()
{
    setlocale(LC_ALL, "Portuguese");

    SetConsoleTitle("Trabalho 2 (strings) - Eduardo Conde Pires");

    cursor(true);
    int repete = false;

    while (!senha(repete))
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

void cursor(bool status)
{
    if (status)
    {
        CONSOLE_CURSOR_INFO cursor = {1, TRUE};
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    }
    else
    {
        CONSOLE_CURSOR_INFO cursor = {1, FALSE};
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    }
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
            putch(NULL);
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
