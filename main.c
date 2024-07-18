

#include <stdio.h>
#include <stdlib.h>

int soma(int *numeros, int offset, int len);
int soma(int *numeros, int offset, int len) {
  if (offset < len) {
    return numeros[offset] + soma(numeros, offset + 1, len);
  }
  return 0;
}

void quatro_um();
void quatro_um() {
  int numeros[] = {2, 4, 6};
  printf("[4.1] Soma: %d\n", soma(numeros, 0, 3));
}

int pega_maior(int *numeros, int maior, int offset, int len);
int pega_maior(int *numeros, int maior, int offset, int len) {
  if (offset < len) {
    int m = maior;
    if (numeros[offset] > maior)
      m = numeros[offset];
    return pega_maior(numeros, m, offset + 1, len);
  }
  return maior;
}

void quatro_tres();
void quatro_tres() {
  int numeros[] = {2, 4, 6, 8, 1, 3, 2};
  printf("[4.3] Maior numero: %d\n", pega_maior(numeros, *numeros, 0, 7));
}

void print_numeros(int *numeros, int len);
void print_numeros(int *numeros, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", numeros[i]);
  }
  printf("\n");
}

void quick_sort(int *numeros, int len);
void quick_sort(int *numeros, int len) {
  if (len == 1 || len == 0)
    return;

  int pivot_pos = len / 2;
  int pivot = numeros[pivot_pos];

  int *smaller_than_pivot = malloc(sizeof(int));
  int smaller_len = 0;
  int *bigger_than_pivot = malloc(sizeof(int));
  int bigger_len = 0;

  for (int i = 0; i < len; i++) {
    if (i != pivot_pos) {
      if (numeros[i] <= pivot) {
        smaller_than_pivot =
            (int *)realloc(smaller_than_pivot, sizeof(int) * (smaller_len + 1));
        smaller_than_pivot[smaller_len] = numeros[i];
        smaller_len += 1;
      } else {
        bigger_than_pivot =
            (int *)realloc(bigger_than_pivot, sizeof(int) * (bigger_len + 1));
        bigger_than_pivot[bigger_len] = numeros[i];
        bigger_len += 1;
      }
    }
  }
  quick_sort(smaller_than_pivot, smaller_len);
  quick_sort(bigger_than_pivot, bigger_len);

  for (int i = 0; i < smaller_len; i++) {
    numeros[i] = smaller_than_pivot[i];
  }

  numeros[smaller_len] = pivot;
  for (int i = 0; i < bigger_len; i++) {
    numeros[i + smaller_len + 1] = bigger_than_pivot[i];
  }

  free(smaller_than_pivot);
  free(bigger_than_pivot);
}

void quick_sort_try();
void quick_sort_try() {
  int numeros[] = {2, 6, 4, 8, 1, 3, 5};
  printf("Numeros nao ordenados: ");
  print_numeros(numeros, 7);
  quick_sort(numeros, 7);
  printf("Numeros ordenados: ");
  print_numeros(numeros, 7);
}

int main() {
  quatro_um();
  quatro_tres();
  quick_sort_try();
  return 0;
}
