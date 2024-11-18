#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

// Definindo o tipo Polinomio como um struct com um vetor de coeficientes e o grau
typedef struct {
    int grau;       // Grau do polinômio
    double* coef;   // Vetor de coeficientes
} Polinomio;

// Função para criar um polinômio com um grau especificado
Polinomio cria_polinomio(int grau) {
    Polinomio p;
    p.grau = grau;
    p.coef = (double*)malloc((grau + 1) * sizeof(double));  // Alocando memória para os coeficientes

    printf("Digite os coeficientes do polinômio (do grau 0 ao grau %d):\n", grau);
    for (int i = 0; i <= grau; i++) {
        printf("Coeficiente de x^%d: ", i);
        scanf("%lf", &p.coef[i]);
    }

    return p;
}

// Função para imprimir o polinômio
void imprime_polinomio(Polinomio p) {
    for (int i = p.grau; i >= 0; i--) {
        if (i != p.grau && p.coef[i] >= 0) {
            printf("+");
        }
        printf("%.2lfx^%d ", p.coef[i], i);
    }
    printf("\n");
}

// Função para adicionar dois polinômios
Polinomio soma_polinomios(Polinomio p1, Polinomio p2) {
    int grau_max = (p1.grau > p2.grau) ? p1.grau : p2.grau;
    Polinomio resultado;
    resultado.grau = grau_max;
    resultado.coef = (double*)calloc(grau_max + 1, sizeof(double));  // Inicializando com zeros

    // Somando os coeficientes
    for (int i = 0; i <= grau_max; i++) {
        if (i <= p1.grau) resultado.coef[i] += p1.coef[i];
        if (i <= p2.grau) resultado.coef[i] += p2.coef[i];
    }

    return resultado;
}

// Função para subtrair dois polinômios
Polinomio subtrai_polinomios(Polinomio p1, Polinomio p2) {
    int grau_max = (p1.grau > p2.grau) ? p1.grau : p2.grau;
    Polinomio resultado;
    resultado.grau = grau_max;
    resultado.coef = (double*)calloc(grau_max + 1, sizeof(double));  // Inicializando com zeros

    // Subtraindo os coeficientes
    for (int i = 0; i <= grau_max; i++) {
        if (i <= p1.grau) resultado.coef[i] += p1.coef[i];
        if (i <= p2.grau) resultado.coef[i] -= p2.coef[i];
    }

    return resultado;
}

// Função para calcular a derivada de um polinômio
Polinomio derivada_polinomio(Polinomio p) {
    Polinomio resultado;
    resultado.grau = p.grau - 1;
    resultado.coef = (double*)malloc(resultado.grau + 1 * sizeof(double));

    // Calculando a derivada
    for (int i = 1; i <= p.grau; i++) {
        resultado.coef[i - 1] = p.coef[i] * i;
    }

    return resultado;
}

// Função para calcular as raízes de um polinômio de grau 2 (fórmula de Bhaskara)
void raiz_polinomio(Polinomio p) {
    if (p.grau == 2) {
        double delta = p.coef[1] * p.coef[1] - 4 * p.coef[2] * p.coef[0]; // Fórmula do delta
        
        if (delta > 0) {
            // Duas raízes reais
            double r1 = (-p.coef[1] + sqrt(delta)) / (2 * p.coef[2]);
            double r2 = (-p.coef[1] - sqrt(delta)) / (2 * p.coef[2]);
            printf("Raízes reais: %.2f e %.2f\n", r1, r2);
        } else if (delta == 0) {
            // Uma raiz real (raiz dupla)
            double r = -p.coef[1] / (2 * p.coef[2]);
            printf("Raiz real dupla: %.2f\n", r);
        } else {
            // Raízes complexas
            double real = -p.coef[1] / (2 * p.coef[2]);
            double imaginario = sqrt(-delta) / (2 * p.coef[2]);
            printf("Raízes complexas: %.2f + %.2fi e %.2f - %.2fi\n", real, imaginario, real, imaginario);
        }
    } else {
        printf("Esta função só pode calcular raízes para polinômios de grau 2.\n");
    }
}

int main() {
    // Criando dois polinômios de grau 2
    Polinomio p1 = cria_polinomio(2);
    Polinomio p2 = cria_polinomio(2);

    // Imprimindo os polinômios
    printf("Polinômio 1: ");
    imprime_polinomio(p1);
    printf("Polinômio 2: ");
    imprime_polinomio(p2);

    // Adição de polinômios
    Polinomio soma = soma_polinomios(p1, p2);
    printf("Soma dos polinômios: ");
    imprime_polinomio(soma);

    // Subtração de polinômios
    Polinomio subtracao = subtrai_polinomios(p1, p2);
    printf("Subtração dos polinômios: ");
    imprime_polinomio(subtracao);

    // Derivada do polinômio 1
    Polinomio derivada = derivada_polinomio(p1);
    printf("Derivada do Polinômio 1: ");
    imprime_polinomio(derivada);

    // Raízes do polinômio 1 (apenas para grau 2)
    printf("Raízes do Polinômio 1: ");
    raiz_polinomio(p1);

    // Raízes do polinômio 2 (apenas para grau 2)
    printf("Raízes do Polinômio 2: ");
    raiz_polinomio(p2);

    // Liberando a memória
    free(p1.coef);
    free(p2.coef);
    free(soma.coef);
    free(subtracao.coef);
    free(derivada.coef);

    return 0;
}
