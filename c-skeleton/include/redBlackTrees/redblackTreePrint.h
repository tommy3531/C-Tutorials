void printTreeValue(int value)
{
    printf("%d\n", value);
}

void printParent(Node *root)
{
    if(root != NULL) {
        if (root->left != NULL) {
            printTreeValue(root->left->color);
            printTreeValue(root->left->value);
        }
    }
    
}

void printUncle(Node *root)
{
    if(root != NULL) {
        if (root->right != NULL) {
            printTreeValue(root->right->color);
            printTreeValue(root->right->value);
        }
    }
}

void checkFamilyNode(Node *root)
{
    
    printParent(root);
    printUncle(root);
    
    
}

void printNode(Node *root)
{
    if(root != NULL)
    {
        printNode(root->left);
        printTreeValue(root->color);
        printTreeValue(root->value);
        printNode(root->right);
    }
}

void displayTree(Node *root)
{
    if (root == NULL)
        return;
    /* display node data */
    printf("%d",root->value);
    if(root->left != NULL)
        printf("(L:%d)",root->left->value);
    if(root->right != NULL)
        printf("(R:%d)",root->right->value);
    printf("\n");
    
    displayTree(root->left);
    displayTree(root->right);
}

void display(Node *root, int level)
{
    int i;
    if(root == NULL)
    {
        return;
    }
    
    display(root->right, level+1);
    printf("\n");
    
    for(i = 0; i < level; i++)
    {
        printf("  ");
    }
    printf("%d", root->value);
    //printf("%d", root->Color);
    display(root->left, level+1);
}