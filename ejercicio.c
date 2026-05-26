#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *entrada, *salida;
    int *numeros = NULL;
    int cantidad = 0;
    int num;
    double suma = 0.0, promedio;

    // Abrir archivo de entrada
    entrada = fopen("numeros.txt", "r");
    if (entrada == NULL) {
        printf("Error: no se pudo abrir numeros.txt\n");
        return 1;
    }

    // Leer números y reservar memoria dinámicamente
    while (fscanf(entrada, "%d", &num) == 1) {
        // Reservar (o ampliar) memoria para un número más
        numeros = (int *)realloc(numeros, (cantidad + 1) * sizeof(int));
        if (numeros == NULL) {
            printf("Error al reservar memoria\n");
            fclose(entrada);
            return 1;
        }
        numeros[cantidad] = num;
        suma += num;
        cantidad++;
    }

    fclose(entrada);

    if (cantidad == 0) {
        printf("El archivo esta vacio.\n");
        return 1;
    }

    // Calcular promedio
    promedio = suma / cantidad;

    // Abrir archivo de salida
    salida = fopen("resultado.txt", "w");
    if (salida == NULL) {
        printf("Error: no se pudo crear resultado.txt\n");
        free(numeros);
        return 1;
    }

    // Escribir lista original
    fprintf(salida, "Numeros leidos:");
    for (int i = 0; i < cantidad; i++) {
        fprintf(salida, " %d", numeros[i]);
    }
    fprintf(salida, "\n");

    // Escribir promedio
    fprintf(salida, "Promedio: %.2f\n", promedio);

    // Escribir números mayores al promedio
    fprintf(salida, "Numeros mayores que el promedio:");
    for (int i = 0; i < cantidad; i++) {
        if (numeros[i] > promedio) {
            fprintf(salida, " %d", numeros[i]);
        }
    }
    fprintf(salida, "\n");

    fclose(salida);

    // Liberar memoria
    free(numeros);

    printf("Los resultados se guardaron en: resultado.txt\n");

    return 0;
}