# 🧮 Algoritmos de Ordenação em C

Este algoritmo ordena um array de pessoas (nome e idade) em **C** utilizando três algoritmos clássicos de ordenação: **Insertion Sort**, **Merge Sort** e **Quick Sort**. A ordenação é feita em ordem alfabética pelo nome, e o programa exibe estatísticas de desempenho para cada algoritmo.

## 👤 Estrutura da Pessoa

```c
typedef struct {
    char nome[100];
    int idade;
} Pessoa;
```

## ✨ Funcionalidades

- Ordenação de um array de pessoas pelo nome (alfabética), usando `strcmp`
- Implementação dos algoritmos:
  - 📝 Insertion Sort
  - 🪄 Merge Sort
  - ⚡ Quick Sort
- Estatísticas exibidas após cada ordenação:
  - 🔎 Número de comparações
  - 🔀 Número de trocas
  - ⏱️ Tempo médio de execução (milissegundos, média de 5 execuções)
- Impressão da lista ordenada de pessoas

---

## 📖 Explicação dos Algoritmos Escolhidos

### 1. 📝 Insertion Sort

**Como funciona:**  
O Insertion Sort percorre o array da esquerda para a direita e, para cada elemento, insere-o na posição correta entre os elementos já ordenados à esquerda.  
É eficiente para pequenas quantidades de dados e listas quase ordenadas.

**Complexidade:**  
- Melhor caso: O(n) (lista já ordenada)
- Pior caso: O(n²) (lista inversamente ordenada)
- Espaço: O(1), é um algoritmo in-place

### 2. 🪄 Merge Sort

**Como funciona:**  
O Merge Sort é um algoritmo recursivo que divide o array em duas partes, ordena cada parte e depois as combina (merge) em uma sequência ordenada.  
É eficiente para grandes quantidades de dados e garante boa performance em qualquer situação.

**Complexidade:**  
- Melhor caso: O(n log n)
- Pior caso: O(n log n)
- Espaço: O(n), devido ao array auxiliar

### 3. ⚡ Quick Sort

**Como funciona:**  
O Quick Sort seleciona um “pivô” e particiona o array em duas partes: elementos menores (à esquerda) e maiores (à direita) que o pivô. Ordena cada parte recursivamente.  
É muito rápido na prática para dados aleatórios, mas pode ser O(n²) em casos extremos (pivot ruim).

**Complexidade:**  
- Melhor caso: O(n log n)
- Pior caso: O(n²) (pivot sempre mínimo/máximo)
- Espaço: O(log n), devido à recursão

---

## 📊 Tabela de Resultados

Resultados obtidos para um array de 100 pessoas, ordenando pelo nome:

| Algoritmo       | Comparações | Trocas | Tempo Médio (ms) |
|-----------------|-------------|--------|------------------|
| 📝 Insertion Sort  | 2638        | 2642   | 0.00             |
| 🪄 Merge Sort      | 574         | 704    | 0.20             |
| ⚡ Quick Sort      | 667         | 495    | 0.00             |

> Os valores podem variar em diferentes execuções e máquinas.

---

## 🛠️ Como Executar

1. **Compile o código:**
   ```sh
   gcc main.c -o main.exe
   ```
2. **Execute o programa:**
   ```sh
   ./main.exe
   ```
   Ou no Windows:
   ```sh
   main.exe
   ```
---

## 👨‍💻 Autor

Feito por **Joniel Mendes**.

---

