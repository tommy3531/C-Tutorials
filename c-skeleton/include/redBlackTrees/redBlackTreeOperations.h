int height(Node *root)
{
    int heightLeft;
    int heightRight;
    
    if(root == NULL)
    {
        return 0;
    }
    
    heightLeft = height(root->left);
    heightRight = height(root->right);
    
    if(heightLeft > heightRight)
    {
        return 1+heightLeft;
    }
    else
    {
        return 1+heightRight;
    }
}

int compare(int left, int right)
{
    if(left > right)
    {
        return 1;
    }
    if(left < right)
    {
        return -1;
    }
    return 0;
}