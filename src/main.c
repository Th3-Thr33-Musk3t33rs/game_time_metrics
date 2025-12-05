#include <stdbool.h>

#include "avl.h"
#include "bst.h"
#include "rbt.h"
#include "visualizer.h"

#define READ_ACCESS "r"
#define WRITE_ACCESS "w"
#define EXPECTED_INPUTS 4
#define MAX_LINE_LENGTH_DATASET 90
#define MAX_LINE_LENGTH_WISHLIST 57

void buildTrees(FILE *dataset, BstNode **bst, AvlNode **avl, RbtNode **rbt) {
    char line[MAX_LINE_LENGTH_DATASET];
    while (fgets(line, MAX_LINE_LENGTH_DATASET, dataset) != NULL) {
        NodeInfo newInfo;
        bool ok;

        char *name = strtok(line, ",");
        float time = strtof(strtok(NULL, ","), NULL);

        newInfo.name = strdup(name);
        newInfo.avg_play_time = time;

        *bst = insertBstNode(*bst, newInfo);
        *avl = insertAvlNode(*avl, newInfo, &ok);
        *rbt = insertRbtNode(*rbt, newInfo);
    }
}

bool isEqualNodeInfo(NodeInfo bstInfo, NodeInfo avlInfo, NodeInfo rbtInfo) {
    bool namesEqual = (!strcasecmp(bstInfo.name, avlInfo.name)) && (!strcasecmp(avlInfo.name, rbtInfo.name));

    bool timesEqual = (bstInfo.avg_play_time == avlInfo.avg_play_time) && (avlInfo.avg_play_time == rbtInfo.avg_play_time);

    return namesEqual && timesEqual;
}

float queryTrees(FILE *playerWishlist, BstNode **bst, AvlNode **avl, RbtNode **rbt) {
    char line[MAX_LINE_LENGTH_WISHLIST];
    int totalEstimateTime = 0;
    while (fgets(line, MAX_LINE_LENGTH_WISHLIST, playerWishlist) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char *gameName = line;
        size_t len = strlen(gameName);
        if (len >= 2 && gameName[0] == '"' && gameName[len-1] == '"') {
            gameName[len-1] = '\0';
            gameName++;
        }

        BstNode *bstResult = queryBst(*bst, gameName);
        AvlNode *avlResult = queryAvl(*avl, gameName);
        RbtNode *rbtResult = queryRbt(*rbt, gameName);

        if (bstResult == NULL || avlResult == NULL || rbtResult == NULL) {
            printf("ERROR: Game '%s' not found in one or more trees!\n", gameName);
            return -1;
        }

        if (isEqualNodeInfo(bstResult->info, avlResult->info, rbtResult->info)){
            totalEstimateTime += bstResult->info.avg_play_time;
        } else {
            printf("ERROR: Result of query nodes are not equal!");
            return -1;
        }
    }
    return totalEstimateTime;
}

/*
    int argc: counts the number of given parameters.
    char *argv[]: stores the strings of given parameters.
*/
int main(int argc, char *argv[]) {
    if (argc != EXPECTED_INPUTS) {
        printf("Expected %d parameters but found %d.\n  Correct usage: <dataset.csv> <player_wishlist.txt> <output.txt>\n", EXPECTED_INPUTS, argc);
        return EXIT_FAILURE;
    }

    FILE *dataset = fopen(argv[1], READ_ACCESS), *playerWishlist = fopen(argv[2], READ_ACCESS), *output = fopen(argv[3], WRITE_ACCESS);
    if (dataset == NULL || playerWishlist == NULL || output == NULL) {
        printf("Error on opening one or more files, please check %s, %s or %s!\n", argv[1], argv[2], argv[3]);
        return EXIT_FAILURE;
    }

    BstNode *bst = newBinSearchTree();
    AvlNode *avl = newAvlTree();
    RbtNode *rbt = newRedBlackTree();

    buildTrees(dataset, &bst, &avl, &rbt);

    if (ENABLE_GENERATE_DOT_FILES) {
        generateDotFiles(bst, avl, rbt);
    }

    fprintf(output, "Tempo total estimado: %.1f horas\n\n", queryTrees(playerWishlist, &bst, &avl, &rbt));

    bstWriteStats(output, bst);
    avlWriteStats(output, avl);
    rbtWriteStats(output, rbt);

    fclose(dataset);
    fclose(playerWishlist);
    fclose(output);
}
