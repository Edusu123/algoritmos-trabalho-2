# Problemas com o código
## Saque - Centavos:

````c
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
````

- ### Ao executar a seguinte linha de código:
````c
int qtdNota = num / notas[i];
````
- ### A divisão do número 0,1 pela nota de valor 0,1 retorna o valor 0, levando o programa a imprimir 10 moedas de 0,01 ao invés de somente imprimir 1 moeda de 0,1.