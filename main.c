#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

typedef struct {
    int comparacoes;
    int trocas;
    double tempo_ms;
} Estatisticas;

void trocar(Pessoa *a, Pessoa *b, Estatisticas *e) {
    Pessoa temp = *a;
    *a = *b;
    *b = temp;
    e->trocas++;
}

// Insertion Sort
void insertionSort(Pessoa arr[], int n, Estatisticas *e) {
    for (int i = 1; i < n; i++) {
        Pessoa chave = arr[i];
        int j = i - 1;
        while (j >= 0) {
            e->comparacoes++;
            if (strcmp(arr[j].nome, chave.nome) > 0) {
                arr[j + 1] = arr[j];
                e->trocas++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = chave;
        e->trocas++;
    }
}

// Merge Sort
void merge(Pessoa arr[], int l, int m, int r, Estatisticas *e) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Pessoa *L = malloc(n1 * sizeof(Pessoa));
    Pessoa *R = malloc(n2 * sizeof(Pessoa));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        e->comparacoes++;
        if (strcmp(L[i].nome, R[j].nome) <= 0) {
            arr[k++] = L[i++];
            e->trocas++;
        } else {
            arr[k++] = R[j++];
            e->trocas++;
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
        e->trocas++;
    }
    while (j < n2) {
        arr[k++] = R[j++];
        e->trocas++;
    }
    free(L);
    free(R);
}

void mergeSort_rec(Pessoa arr[], int l, int r, Estatisticas *e) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort_rec(arr, l, m, e);
        mergeSort_rec(arr, m + 1, r, e);
        merge(arr, l, m, r, e);
    }
}

void mergeSort(Pessoa arr[], int n, Estatisticas *e) {
    mergeSort_rec(arr, 0, n - 1, e);
}

// Quick Sort
int partition(Pessoa arr[], int low, int high, Estatisticas *e) {
    Pessoa pivo = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        e->comparacoes++;
        if (strcmp(arr[j].nome, pivo.nome) <= 0) {
            i++;
            trocar(&arr[i], &arr[j], e);
        }
    }
    trocar(&arr[i + 1], &arr[high], e);
    return i + 1;
}

void quickSort_rec(Pessoa arr[], int low, int high, Estatisticas *e) {
    if (low < high) {
        int pi = partition(arr, low, high, e);
        quickSort_rec(arr, low, pi - 1, e);
        quickSort_rec(arr, pi + 1, high, e);
    }
}

void quickSort(Pessoa arr[], int n, Estatisticas *e) {
    quickSort_rec(arr, 0, n - 1, e);
}

void imprimePessoas(Pessoa arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s (%d)\n", arr[i].nome, arr[i].idade);
}

void copiaArray(Pessoa origem[], Pessoa destino[], int n) {
    for (int i = 0; i < n; i++)
        destino[i] = origem[i];
}

void executaOrdenacao(void (*alg)(Pessoa[], int, Estatisticas*), Pessoa dados[], int n, Estatisticas *e) {
    Estatisticas soma = {0, 0, 0.0};
    Pessoa temp[n];
    for (int rep = 0; rep < 5; rep++) {
        copiaArray(dados, temp, n);
        Estatisticas atual = {0, 0, 0.0};
        clock_t inicio = clock();
        alg(temp, n, &atual);
        clock_t fim = clock();
        atual.tempo_ms = ((double)(fim - inicio)) * 1000.0 / CLOCKS_PER_SEC;
        soma.comparacoes += atual.comparacoes;
        soma.trocas += atual.trocas;
        soma.tempo_ms += atual.tempo_ms;
    }
    e->comparacoes = soma.comparacoes / 5;
    e->trocas = soma.trocas / 5;
    e->tempo_ms = soma.tempo_ms / 5.0;
    // Copia o último array ordenado de volta para 'dados'
    copiaArray(temp, dados, n);
    printf("Lista ordenada:\n");
    imprimePessoas(dados, n);
}

int main() {
  Pessoa pessoas[] = {
    {"Helena Dias", 60}, {"Gustavo Barbosa", 38}, {"Alice Fernandes", 24}, {"Nicolas Barros", 31},
    {"Beatriz Azevedo", 49}, {"Daniel Pinto", 26}, {"Luiza Cardoso", 37}, {"Joaquim Correia", 65},
    {"Cecília Teixeira", 23}, {"Samuel Castro", 50}, {"Heloísa Mendes", 19}, {"Bernardo Rocha", 34},
    {"Mariana Cunha", 28}, {"Heitor Moreira", 42}, {"Yasmin Nunes", 22}, {"Davi Lopes", 36},
    {"Giovanna Ramos", 26}, {"Arthur Fogaça", 55}, {"Lívia Araujo", 30}, {"Lorenzo Cavalcanti", 21},
    {"Lorena Vieira", 44}, {"Benjamin Moraes", 29}, {"Maria Eduarda Freitas", 20}, {"Vinícius Melo", 39},
    {"Gabriela Monteiro", 27}, {"Francisco Pinto", 70}, {"Nicole da Silva", 25}, {"Eduardo da Costa", 48},
    {"Sarah da Cruz", 23}, {"Leonardo Pires", 32}, {"Melissa Tavares", 28}, {"Davi Lucca Sales", 18},
    {"Ester Brandão", 58}, {"Bryan Siqueira", 24}, {"Rebeca Arruda", 31}, {"Igor Vasconcelos", 40},
    {"Marina Campos", 26}, {"Murilo Rezende", 35}, {"Clara Macedo", 22}, {"Theo Caldeira", 19},
    {"Elisa Pacheco", 46}, {"Miguel Borges", 29}, {"Ana Júlia Neves", 21}, {"Caio Drummond", 33},
    {"Estela Portela", 53}, {"Erick Viana", 27}, {"Letícia Maciel", 30}, {"Isaac Cordeiro", 25},
    {"Bianca Peixoto", 20}, {"Yuri Dantas", 43}, {"Lavínia Silveira", 28}, {"Emanuel Quintela", 37},
    {"Carolina Paiva", 24}, {"André Gusmão", 51}, {"Isadora Santana", 22}, {"Lucca Bezerra", 18},
    {"Agnes Torres", 62}, {"Bruno Guedes", 36}, {"Olívia Amorim", 29}, {"Cauã Bernardes", 23},
    {"Emilly Novais", 26}, {"Rodrigo Farias", 47}, {"Agatha Chaves", 20}, {"Vítor Nogueira", 34},
    {"Maria Clara Barreto", 25}, {"Fernando Valente", 59}, {"Alana Pimentel", 21}, {"Diego Bernardes", 30},
    {"Luna Xavier", 23}, {"Otávio Navarro", 68}, {"Stella Queiroz", 27}, {"Antônio Castilho", 72},
    {"Maya Dorneles", 19}, {"Breno Dorneles", 28}, {"Ayla Padrão", 22}, {"Ricardo Junqueira", 44},
    {"Aurora Bicalho", 26}, {"Danilo Franco", 38}, {"Catarina Boaventura", 31}, {"Alex Mesquita", 24},
    {"Liz Bastos", 20}, {"Marcos Proença", 49}, {"Maria Alice Amaral", 25}, {"Thiago Goulart", 33},
    {"Eloá Salgado", 29}, {"Amanda Diniz", 36}, {"João Pedro Almeida", 23}, {"Felipe Moreira", 27},
    {"Juliana Antunes", 22}, {"Pedro Henrique Reis", 21}, {"Vivian Duarte", 41}, {"Rafaela Rangel", 30},
    {"Vinicius Fonseca", 28}, {"Camila Vasquez", 20}, {"Patrícia Prado", 26}, {"Henrique Miranda", 34},
    {"Luana Martins", 25}, {"Cristiano Paiva", 60}, {"Laura Figueiredo", 19}, {"Guilherme Barcellos", 23},
    {"Eduarda Lima", 24}, {"Sofia Carvalho", 31}, {"Matheus Sampaio", 35}, {"Rafael Braga", 26}
};
    int n = sizeof(pessoas) / sizeof(pessoas[0]);

    Pessoa teste[n];
    Estatisticas estat;

    printf("==== Insertion Sort ====\n");
    copiaArray(pessoas, teste, n);
    executaOrdenacao(insertionSort, teste, n, &estat);
    printf("Comparacoes: %d, Trocas: %d, Tempo medio: %.2f ms\n\n", estat.comparacoes, estat.trocas, estat.tempo_ms);

    printf("==== Merge Sort ====\n");
    copiaArray(pessoas, teste, n);
    executaOrdenacao(mergeSort, teste, n, &estat);
    printf("Comparacoes: %d, Trocas: %d, Tempo medio: %.2f ms\n\n", estat.comparacoes, estat.trocas, estat.tempo_ms);

    printf("==== Quick Sort ====\n");
    copiaArray(pessoas, teste, n);
    executaOrdenacao(quickSort, teste, n, &estat);
    printf("Comparacoes: %d, Trocas: %d, Tempo medio: %.2f ms\n\n", estat.comparacoes, estat.trocas, estat.tempo_ms);

    return 0;
}