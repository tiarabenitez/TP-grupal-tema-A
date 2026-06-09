#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *entrada, *salida;
    int *numeros = NULL;
    int cantidad = 0;
    int num;
    double suma = 0.0, promedio;

    entrada = fopen("numeros.txt", "r");
    if (entrada == NULL) {
        printf("Error: no se pudo abrir numeros.txt\n");
        return 1;
    }

    while (fscanf(entrada, "%d", &num) == 1) {
        int *nuevo = (int *)malloc((cantidad + 1) * sizeof(int));
        if (nuevo == NULL) {
            printf("Error al reservar memoria\n");
            free(numeros);
            fclose(entrada);
            return 1;
        }
        for (int i = 0; i < cantidad; i++) {
            nuevo[i] = numeros[i];
        }
        free(numeros);
        numeros = nuevo;
        numeros[cantidad] = num;
        suma += num;
        cantidad++;
    }

    fclose(entrada);

    if (cantidad == 0) {
        printf("El archivo esta vacio.\n");
        return 1;
    }

    promedio = suma / cantidad;

    salida = fopen("resultado.txt", "w");
    if (salida == NULL) {
        printf("Error: no se pudo crear resultado.txt\n");
        free(numeros);
        return 1;
    }

    fprintf(salida, "Numeros leidos:");
    for (int i = 0; i < cantidad; i++) {
        fprintf(salida, " %d", numeros[i]);
    }
    fprintf(salida, "\n");

    fprintf(salida, "Promedio: %.2f\n", promedio);

    fprintf(salida, "Numeros mayores que el promedio:");
    for (int i = 0; i < cantidad; i++) {
        if (numeros[i] > promedio) {
            fprintf(salida, " %d", numeros[i]);
        }
    }
    fprintf(salida, "\n");

    fclose(salida);

    free(numeros);

    printf("Los resultados se guardaron en: resultado.txt\n");

    return 0;
}