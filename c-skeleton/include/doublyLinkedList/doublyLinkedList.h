/*
 * Advantages
 *  - Can be traversed in both forward and backward directions
 *  - Insertion and deletion can be done with a single pointer
 *  -
 */




/*******************************************************************************************************************
 *
 * Prev         Info          Next
 * *********** ************* ***********
 * *         * *           * *         *
 * *         * *           * *         *
 * *         * *           * *         *
 * *********** ************* ***********
 *
 ********************************************************************************************************************/

struct node
{
    struct node *prev;
    int value;
    struct node *next;
};

