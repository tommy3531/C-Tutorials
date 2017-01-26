#include <stdio.h>
#include <stdlib.h>
#include "../include/binaryTrees/binaryTree.h"


int main(int argc, const char *argv[])
{
    printf("This is from the binaryTree.c\n");
    struct node *tree = NULL;
    tree = insert(tree, 50);
    insert(tree, 30);
    insert(tree, 20);
    insert(tree, 40);
    insert(tree, 70);
    insert(tree, 60);
    insert(tree, 80);

    display(tree, 0);
    printf("\n\n");

    display(tree, 1);
    printf("\n\n");


    printf("Preorder: ");
    preOrder(tree);
    printf("\n\n");

    printf("Inorder: ");
    inOrder(tree);
    printf("\n\n");

    printf("PostOrder: ");
    postOrder(tree);
    printf("\n\n");

    printf("Level order: ");
    levelOrder(tree);
    printf("\n\n");

    printf("Height of tree is %d\n", height(tree));


}
