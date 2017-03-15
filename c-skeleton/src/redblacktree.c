/*
 * Tom Marler
 * CS 3050 Hashtable
 * TJM5ND
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <redBlackTrees/redblacktree.h>
#include <redBlackTrees/redblackTreePrint.h>
#include <redBlackTrees/redBlackTreeOperations.h>

int main() {

   // Node *root = NULL;
    Node *treeRoot = NULL;
    Node *nodeCreatePtr = NULL;
    Node *dummyTreeRoot = NULL;
    
    treeRoot = (Node *)malloc(sizeof(Node));
    nodeCreatePtr = (Node *)malloc(sizeof(Node));

    // Insert Node need treeRoot and Number
    // return pointer to tree root
//    treeRoot = insertNode(dummyTreeRoot, nodeCreatePtr, 9);
//    treeRoot = insertNode(treeRoot, nodeCreatePtr, 25);
//    treeRoot = insertNode(treeRoot, nodeCreatePtr, 43);
    
    treeRoot = insertNode(dummyTreeRoot, nodeCreatePtr, 11);
    treeRoot = insertNode(treeRoot, nodeCreatePtr, 2);
    treeRoot = insertNode(treeRoot, nodeCreatePtr, 14);
//    treeRoot = insertNode(treeRoot, 1);
//    treeRoot = insertNode(treeRoot, 7);
//    treeRoot = insertNode(treeRoot, 15);
//    treeRoot = insertNode(treeRoot, 5);
//    treeRoot = insertNode(treeRoot, 8);
    
    printf("Level Order\n");
    printLevelOrder(treeRoot);

    
    
    // Insert node need tree Root and Node to insert
    // returns pointer to root of tree

    
    
    
    
//    displayTree(treeRoot);
//    printf("\n");
//    printf("Printing Parent\n");
//    printParent(treeRoot);
//    printf("This is preorder\n");
//    preorder(treeRoot);
    
    //fixTree(RBTRoot, 14);
    //treeFixCase1(RBTRoot);
    //displayTree(RBTRoot);



}

