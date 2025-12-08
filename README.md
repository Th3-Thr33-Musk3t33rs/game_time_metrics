# Game Time Metrics

Este projeto compara como diferentes estruturas de dados de árvore performam ao buscar dados de tempo de jogo. Ele lê um arquivo CSV de jogos do Steam com seu tempo médio de jogo, carrega-os em várias estruturas de árvore e mede quanto tempo leva para procurar por jogos específicos.

## O que ele faz?

O programa ajuda você a entender as compensações de desempenho entre Árvores Binárias de Busca (BST), árvores AVL e árvores Rubro-Negras. Você fornece um conjunto de dados de jogos e suas estatísticas de tempo de jogo, depois uma lista de jogos que deseja buscar. Ele informará:

- Quanto tempo cada estrutura de árvore levou para ser construída
- Quanto tempo as buscas levaram em cada estrutura
- Tempo total estimado de jogo para sua lista de jogos
- Quais jogos não foram encontrados no conjunto de dados

Ele também gera visualizações das estruturas de árvore para que você possa ver como elas estão organizadas internamente.

## As estruturas de dados

Três implementações de árvore estão incluídas:

- **Árvore Binária de Busca (BST)** - Simples, mas pode se tornar desbalanceada com dados ordenados
- **Árvore AVL** - Auto-balanceada com restrições de altura rigorosas
- **Árvore Rubro-Negra** - Auto-balanceada com restrições mais flexíveis que AVL

Todas as árvores são insensíveis a maiúsculas/minúsculas ao comparar nomes de jogos.

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
O programa escreve estatísticas de tempo e resultados no arquivo de saída e também os imprime no console.

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
```

## Conjunto de dados

Os arquivos CSV contêm dados de jogos do Steam com tempo médio de jogo em horas. O conjunto de dados original veio de estatísticas públicas do Steam. Cada linha tem:

```
Nome do Jogo,Horas Médias Jogadas
```

Alguns conjuntos de dados de amostra estão incluídos:
- `dataset.csv` - Conjunto de dados completo
- `dataset_sorted.csv` - Ordenado alfabeticamente (pior caso para BST)
- `dataset_reversed.csv` - Ordenado inversamente
- `dataset_random.csv` - Ordem embaralhada

## Notas de desempenho

Você notará comportamentos diferentes dependendo da ordem de entrada:

- **Dados ordenados** fazem com que a BST degenere em uma lista encadeada (operações O(n))
- **Árvores AVL** mantêm equilíbrio rigoroso, boas para cargas de trabalho com muitas leituras
- **Árvores Rubro-Negras** têm inserções mais baratas que AVL, mas buscas ligeiramente mais lentas

Tente executar com diferentes ordens de conjuntos de dados para ver as diferenças de desempenho.

## Contexto

Este foi originalmente um trabalho para um curso de estruturas de dados na UFRGS, focado em entender como o balanceamento de árvores afeta o desempenho no mundo real. O caso de uso específico (estimativa de tempo de jogo) foi escolhido para tornar a comparação mais tangível do que dados abstratos de benchmark.

## Autores

**ANDRÉ SCHAIDHAUER LUCKMANN**  
**VITOR DA CUNHA PIMENTEL DA ROSA**
