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
    Node *RBTRoot = NULL;
    RBTRoot = (Node *)malloc(sizeof(Node));

    //checkInsertion(root);
    RBTRoot = insertNode(RBTRoot, 8);
    RBTRoot = insertNode(RBTRoot, 3);
    RBTRoot = insertNode(RBTRoot, 10);
    RBTRoot = insertNode(RBTRoot, 1);
    RBTRoot = insertNode(RBTRoot, 6);
    RBTRoot = insertNode(RBTRoot, 14);
    RBTRoot = insertNode(RBTRoot, 4);
    RBTRoot = insertNode(RBTRoot, 7);
    RBTRoot = insertNode(RBTRoot, 13);
    
    displayTree(RBTRoot);
    fixTree(RBTRoot, 14);



}

