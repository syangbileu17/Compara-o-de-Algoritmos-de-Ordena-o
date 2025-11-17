#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



void gerar_aleatorio(int s[], int n, int max_val) {
    for (int i = 0; i < n; i++) {
        s[i] = rand() % (max_val + 1); 
    }
}


void bubble_sort(int s[], int n, long *steps) { //bubble_sort
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            (*steps)++;
            if (s[j] > s[j + 1]) {
                aux = s[j];
                s[j] = s[j + 1];
                s[j + 1] = aux;
                (*steps)++; 
            }
        }
    }
}


void insertion_sort(int s[], int n, long *steps) { // insertion_sort
    int i, j, chave;
    // 
    for (i = 1; i < n; i++) {
        chave = s[i];
        (*steps)++;
        j = i - 1;

        while (j >= 0) {
            (*steps)++;
            if (s[j] > chave) {
                s[j + 1] = s[j];
                (*steps)++;
                j--;
            } else break;
        }
        s[j + 1] = chave;
        (*steps)++;
    }
}


void testar_metodo (void (*sort_func)(int*, int, long*), const char *nome,
              int s[], int n) {
    long total_steps = 0;
    double total_time = 0.0;

    for (int k = 0; k < 5; k++) {
        int w[n]; 
        for (int i = 0; i < n; i++) w[i] = s[i];
        
        long steps = 0;
        clock_t t0 = clock();
        sort_func(w, n, &steps);
        clock_t t1 = clock();
        
        double tempo_ms = 1000.0 * (t1 - t0) / CLOCKS_PER_SEC; 
        total_steps += steps;
        total_time += tempo_ms;
    }

    printf("%s,%d,original,%ld,%.3f\n", nome, n, total_steps / 5, total_time / 5);
}


int main() {
    srand(time(NULL));

    char rgm[9];
    printf("Digite seu RGM (8 digitos): ");
    scanf("%8s", rgm);
    while (strlen(rgm) != 8) {
        printf("RGM invalido! Digite exatamente 8 digitos: ");
        scanf("%8s", rgm);
    }

    int n = 8;
    int digits[8];
    for (int i = 0; i < 8; i++)
        digits[i] = rgm[i] - '0';

    printf("\nmetodo,n,caso,passos,tempo_ms\n");

    testar_metodo(bubble_sort, "bubble", digits, n);
    testar_metodo(insertion_sort, "insertion", digits, n);
    
    int tamanhos[] = {100, 1000, 10000};
    int num_tam = sizeof(tamanhos)/sizeof(tamanhos[0]);

    for (int t = 0; t < num_tam; t++) {
        int size = tamanhos[t];
        int *v = (int*)malloc(sizeof(int) * size); 
        
        gerar_aleatorio(v, size, size*10); 

        testar_metodo(bubble_sort, "bubble", v, size);
        testar_metodo(insertion_sort, "insertion", v, size);

        free(v); 
    }

    return 0;
}