#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include <wincon.h>

static const char senha1[] = "123456";

void cursorVisivel(bool status);
void gotoxy(int x, int y);

void main()
{
    setlocale(LC_ALL, "Portuguese");

    SetConsoleTitle("Trabalho 2 (strings) - Eduardo Conde Pires");

    cursor(true);
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
