# Game Time Metrics

This project compares how different tree data structures perform when looking up game playtime data. It reads a CSV file of Steam games with their average playtime, loads them into various tree structures, and measures how long it takes to search for specific games.

## What does it do?

The program helps you understand the performance tradeoffs between Binary Search Trees (BST), AVL trees, and Red-Black trees. You give it a dataset of games and their playtime stats, then a list of games you want to look up. It'll tell you:

- How long each tree structure took to build
- How long searches took in each structure  
- Total estimated playtime for your game list
- Which games weren't found in the dataset

It also generates visualizations of the tree structures so you can see how they're organized internally.

## The data structures

Three tree implementations are included:

- **Binary Search Tree (BST)** - Simple but can become unbalanced with sorted data
- **AVL Tree** - Self-balancing with strict height constraints
- **Red-Black Tree** - Self-balancing with looser constraints than AVL

All trees are case-insensitive when comparing game names.

## Building the project

You need GCC and Make installed. To compile:

```bash
make
```

This creates the `measurer.o` executable.

To clean up build artifacts:

```bash
make clean
```

## Running it

The program takes three command-line arguments:

```bash
./measurer.o <games_csv> <player_list_txt> <output_txt>
```

Example:

```bash
./measurer.o dataset/dataset.csv dataset/player_list.txt output/results.txt
```

**Input files:**
- `games_csv` - CSV file with game names and average hours (format: `Game Name,Hours`)
- `player_list_txt` - Text file with one game name per line

**Output:**
The program writes timing statistics and results to the output file and also prints them to the console.

## Visualizing the trees

If you have Graphviz installed, you can generate visual representations:

```bash
make visualize
```

This creates SVG files in the `visualization/` directory showing the structure of each tree type.

## Project structure

```
├── src/           # Implementation files
│   ├── main.c     # Entry point and coordination
│   ├── bst.c      # Binary Search Tree
│   ├── avl.c      # AVL Tree  
│   ├── rbt.c      # Red-Black Tree
│   ├── utils.c    # File I/O and utilities
│   └── visualizer.c # Graphviz generation
├── include/       # Header files
├── dataset/       # Sample CSV files with game data
├── output/        # Results go here
└── visualization/ # Tree diagrams (after make visualize)
```

## Dataset

The CSV files contain Steam game data with average playtime in hours. The original dataset came from public Steam statistics. Each line has:

```
Game Name,Average Hours Played
```

Some sample datasets are included:
- `dataset.csv` - Full dataset
- `dataset_sorted.csv` - Sorted alphabetically (worst case for BST)
- `dataset_reversed.csv` - Reverse sorted
- `dataset_random.csv` - Shuffled order

## Performance notes

You'll notice different behaviors depending on the input order:

- **Sorted data** causes BST to degenerate into a linked list (O(n) operations)
- **AVL trees** maintain strict balance, good for read-heavy workloads
- **Red-Black trees** have cheaper insertions than AVL but slightly slower searches

Try running with different dataset orders to see the performance differences.

## Background

This was originally an assignment for a data structures course at UFRGS, focused on understanding how tree balancing affects real-world performance. The specific use case (game time estimation) was chosen to make the comparison more tangible than abstract benchmark data.

## Authors

**ANDRÉ SCHAIDHAUER LUCKMANN**  
**VITOR DA CUNHA PIMENTEL DA ROSA**
