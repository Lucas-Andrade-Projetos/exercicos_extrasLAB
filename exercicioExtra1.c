#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NMAX 100

int verifica_palindromo(char palavra[]);

int main() {
    char palavra[NMAX];

    printf("Digite uma palavra para verificar se é um palíndromo: ");
    fgets(palavra, NMAX, stdin);
    
    palavra[strcspn(palavra, "\n")] = '\0';

    if (verifica_palindromo(palavra)) {
        printf("A palavra é um palíndromo!\n");
    } else {
        printf("A palavra não é um palíndromo.\n");
    }

    return 0;
}

// Função para verificar se a palavra é um palíndromo
int verifica_palindromo(char palavra[]) {
    int inicio = 0;
    int fim = strlen(palavra) - 1;

    while (inicio < fim) {
        if (!isalnum(palavra[inicio])) {
            inicio++;
        } else if (!isalnum(palavra[fim])) {
            fim--;
        } else {
            if (tolower(palavra[inicio]) != tolower(palavra[fim])) {
                return 0;
            }
            inicio++;
            fim--;
        }
    }
    return 1;
}
