# Jogo de Batalha Naval em C

Projeto desenvolvido para a disciplina de **Introdução à Programação de Computadores**.

Este trabalho tem como objetivo aplicar os conceitos fundamentais da linguagem C, incluindo vetores, matrizes, estruturas de repetição, condicionais e manipulação de dados bidimensionais, por meio da implementação progressiva de um jogo simplificado de Batalha Naval.

---

## Estrutura do Projeto

O projeto foi desenvolvido em três níveis de complexidade crescente:

### Nível Novato – Posicionamento Básico de Navios
- Criação de um tabuleiro 10x10 utilizando matriz bidimensional.
- Inicialização do tabuleiro com valor `0` (água).
- Posicionamento de navios horizontais e verticais utilizando valor `3`.
- Validação de limites e prevenção de sobreposição.
- Exibição do tabuleiro utilizando loops aninhados.

---

### Nível Aventureiro – Navios Diagonais
- Ampliação do tabuleiro para suportar quatro navios.
- Implementação de navios posicionados na diagonal.
- Validação de coordenadas e controle de sobreposição.
- Uso de estruturas de repetição aninhadas para manipulação matricial.

---

### Nível Mestre – Habilidades Especiais
Implementação de habilidades estratégicas com áreas de efeito distintas:

-  Cone (expansão progressiva)
-  Cruz (linha e coluna centrais)
-  Octaedro (formato losango – distância Manhattan)

Características técnicas:
- Construção dinâmica das matrizes de habilidade utilizando condicionais dentro de loops aninhados.
- Sobreposição das habilidades ao tabuleiro com validação de limites.
- Representação visual padronizada:

| Valor | Representação |
|--------|--------------|
| 0 | Água |
| 3 | Navio |
| 5 | Área afetada pela habilidade |

---

## Conceitos Aplicados

- Matrizes bidimensionais
- Vetores unidimensionais
- Estruturas de repetição (`for`)
- Loops aninhados
- Estruturas condicionais (`if`)
- Controle de limites de matriz
- Distância Manhattan para construção geométrica
- Organização e documentação de código

---

## Compilação e Execução

### Compilar:
```bash
gcc batalha_naval.c -o batalha

./batalha
````
## Objetivo Acadêmico

Este projeto demonstra a aplicação prática dos fundamentos da lógica de programação e da manipulação de estruturas de dados em C, reforçando o desenvolvimento do raciocínio computacional e a organização de algoritmos estruturados.

Desenvolvido por Yago Nardin Disciplina: Introdução à Programação de Computadores Linguagem: C
