# 🚀Algoritmos de Ordenação

Este projeto demonstra como ordenar um array de pessoas usando três algoritmos clássicos de ordenação em **C**. Cada pessoa tem nome e idade, e a ordenação é feita em ordem alfabética pelo nome. Além disso, o programa exibe estatísticas de desempenho para cada algoritmo.

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

> 💡 **Dica:** Para que acentos apareçam corretamente no terminal do Windows, use:
> ```
> chcp 65001
> ```

## 📋 Exemplo de Saída

```
==== Insertion Sort ====
Lista ordenada:
Agatha Chaves (20)
...
Comparacoes: 5276, Trocas: 5284, Tempo medio: 0.00 ms

==== Merge Sort ====
...

==== Quick Sort ====
...
```

## 📚 Algoritmos Implementados

- 📝 Insertion Sort
- 🪄 Merge Sort
- ⚡ Quick Sort

Você pode adaptar o projeto para outros algoritmos de ordenação se desejar.

## 👨‍💻 Autor

Feito por **Joniel Mendes**.

---
