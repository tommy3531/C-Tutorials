

void treeFixCase1(Node *root)
{
    if(root == NULL)
    {
        root->color = BLACK;
    }
    else
    {
        printf("We have a different problem\n");
    }
}

int getLevelCount(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftMaxLevel = 1 + getLevelCount(root->left);
    int rightMaxLevel = 1 + getLevelCount(root->right);
    if (leftMaxLevel > rightMaxLevel)
    {
        return leftMaxLevel;
    }
    else
    {
        return rightMaxLevel;
    }
}