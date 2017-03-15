void printGivenLevel(Node* root, int level);


void printTreeValue(int value)
{
    printf("%d\n", value);
}

void printParent(Node *root)
{
    if(root != NULL) {
        if (root->parent != NULL) {
            printTreeValue(root->color);
            printTreeValue(root->value);
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

//void checkFamilyNode(Node *root)
//{
//
//    printParent(root);
//    printUncle(root);
//
//
//}

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
    if(root->parent != NULL)
    {
        printf("%d-P %d", root->parent->value, root->parent->color);
//        displayTree(root->left);
//        displayTree(root->right);
    }
    /* display node data */
    printf("%d",root->value);
    if(root->left != NULL) {
        printf("(%d-L %d)", root->left->value, root->left->color);
    }
    
    if(root->right != NULL) {
        printf("(%d-R %d)", root->right->value, root->right->color);
    }
    //printf("\n");
//    displayTree(root->parent);
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

void preorder(Node *temp) {
    if (temp != NULL) {
        printf("%d-%d ", temp->value, temp->color);
        preorder(temp->left);
        preorder(temp->right);
    }
}
int height(Node* root)
{
    if (root==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

void printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}

void printGivenLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d-%d, ", root->value, root->color);
    else if (level > 1)
    {
        
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
    //free(root);
}



//Node *searchforparentnode(Node *root, int value)
//{
//    if (root == NULL)
//        return NULL;
//
//    if(root->left == NULL && root->right == NULL)
//        return NULL;
//
//    if( (root->left != NULL && root->left->value == value)
//        || (root->right != NULL && root->right->value == value))
//        return root;
//
//    if(root->value > value)
//        return searchforparentnode(root->left,value);
//
//    if(root->value < value)
//        return searchforparentnode(root->right,value);
//    return root;
//}
