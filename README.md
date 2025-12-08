# Game Time Metrics

Este projeto compara como diferentes estruturas de dados de árvore performam ao buscar dados de tempo de jogo. Ele lê um arquivo CSV de jogos da Steam com seu tempo médio de jogo, carrega-os em várias estruturas de árvore e mede quanto tempo o usuário levaria para jogar os jogos da sua lista de desejos.

## As estruturas de dados

Três implementações de árvore binária de pesquisa foram feitas:

- **Árvore Binária de Busca (BST)** - Simples, mas pode se tornar desbalanceada com dados ordenados
- **Árvore AVL** - Auto-balanceada com restrições de altura rigorosas
- **Árvore Rubro-Negra** - Auto-balanceada com restrições mais flexíveis que AVL

Todas as árvores são case-insensitive ao comparar nomes de jogos.

## Construindo o projeto

Você precisa ter GCC e Make instalados. Para compilar:

```bash
make
```

Isso cria o executável `measurer.o`.

Para limpar os artefatos de compilação:

```bash
make clean
```

## Executando

O programa recebe três argumentos de linha de comando:

```bash
./measurer.o <games_csv> <player_list_txt> <output_txt>
```

Exemplo:

```bash
./measurer.o dataset/dataset.csv dataset/player_list.txt output/results.txt
```

**Arquivos de entrada:**
- `games_csv` - Arquivo CSV com nomes de jogos e horas médias (formato: `Nome do Jogo,Horas`)
- `player_list_txt` - Arquivo de texto com um nome de jogo por linha

**Saída:**
O programa escreve estatísticas das árvores e resultados no arquivo de saída.

## Visualizando as árvores

Se você tiver o Graphviz instalado, pode gerar representações visuais:

```bash
make visualize
```

Isso cria arquivos SVG no diretório `visualization/` mostrando a estrutura de cada tipo de árvore.

## Estrutura do projeto

```
├── src/           # Arquivos de implementação
│   ├── main.c     # Ponto de entrada e coordenação
│   ├── bst.c      # Árvore Binária de Busca
│   ├── avl.c      # Árvore AVL
│   ├── rbt.c      # Árvore Rubro-Negra
│   ├── utils.c    # E/S de arquivos e utilitários
│   └── visualizer.c # Geração de Graphviz
├── include/       # Arquivos de cabeçalho
├── dataset/       # Arquivos CSV de amostra com dados de jogos
├── output/        # Resultados são salvos aqui
└── visualization/ # Diagramas de árvores (após make visualize)
└── report/        # Relatório final do trabalho
```

## Autores

[André Schaidhauer Luckmann](https://github.com/Edigueh)

[Vitor da Cunha Pimentel da Rosa](https://github.com/VitorPimentel17)
