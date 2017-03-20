#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



struct node
{
    struct node *leftNode;
    int info;
    struct node *rightNode;
    struct node *parent;
    
};

struct node *createNode(int x);
struct node *insert(struct node *root, int data);
void display(struct node *root, int level);
void preOrder(struct node *root);
void inOrder(struct node *root);
void postOrder(struct node *root);
void levelOrder(struct node *root);
int height(struct node *root);
struct node* search(struct node *root, int data);
struct node* minNode(struct node *root);
struct node* maxNode(struct node *root);
int searchNodeLevel(struct node *root, int data, int level);
int getLeafCount(struct node *root);
struct node * inOrderSuccessor(struct node *root, int data);


#define MAX 100
struct node *queue[MAX];
struct node *root = NULL;

int front = -1;
int rear = -1;

void insertQueue(struct node *item);
struct node *deleteQueue();
int queueEmpty();
struct node *deleteQueue();

int main(int argc, char** argv)
{
    //printf("This is from the binaryTree.c\n");
    struct node *tree = NULL;
    struct node *succ = NULL;
    struct node *temp = NULL;
    tree = insert(tree, 50);
    tree = insert(tree, 30);
    tree = insert(tree, 20);
    tree = insert(tree, 40);
    tree = insert(tree, 70);
    tree = insert(tree, 60);
    tree = insert(tree, 80);
    temp = tree->leftNode->rightNode->rightNode;

    display(tree, 0);
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
    int searchNode = 40;
    
    struct node *newNode = NULL;
    newNode = search(tree, searchNode);
    int value = searchNodeLevel(root, searchNode, 0);
    
    printf("Found %d at level %d\n", newNode->info, value);
    
    struct node *min = NULL;
    min = minNode(tree);
    printf("Min Value is %d\n", min->info);
    
    struct node *max = NULL;
    max = maxNode(tree);
    printf("Max Value is %d\n", max->info);
    
    int leafCount = getLeafCount(tree);
    printf("There are %d leafs in the BST\n", leafCount);

    
    succ = inOrderSuccessor(tree, searchNode);
    printf("Inorder successor node of %d is : %d ", searchNode, succ->info);
        
}

struct node *createNode(int x)
{
    struct node *current;
    current = (struct node *)malloc(sizeof(struct node));
    current->info = x;
    current->leftNode = NULL;
    current->rightNode = NULL;
    current->parent = NULL;
    
    return current;
}

struct node *insert(struct node *node, int data)
{
    struct node *temp = NULL;
    
    if(node == NULL)
    {
        return createNode(data);
    }
    else if(data < node->info)
    {
        temp = insert(node->leftNode, data);
        node->leftNode = temp;
        temp->parent = node;
    }
    else
    {
        temp = insert(node->rightNode, data);
        node->rightNode = temp;
        temp->parent = node;
    }
    return node;
}

/*
 * Visits left subtree first, then root node and then right subtree
 */
struct node * inOrderSuccessor(struct node *root, int data)
{
    struct node *successor = NULL;
    struct node *current = root;
    
    // CHeck if root is null
    // 1. Start with root
    if(!root)
    {
        return NULL;
    }
    
    // while the value does not equal the value in the tree check the left and right nodes
    while(current->info != data)
    {
        // If node > data go left
        if(current->info > data)
        {
            // current->to successor
            successor = current;
            
            // Check the left node
            current = current->leftNode;
        }
        else
        {
            current = current->rightNode;
        }
    }
    
    // Once the node is found, check if it has a right subtree
    if(current && current->rightNode)
    {
        successor = minNode(current->rightNode);
    }
    return successor;
}

int getLeafCount(struct node *root)
{
    // check if root is null
    if(root == NULL)
    {
        return 0;
    }
    
    // Check if left and right child are null
    if(root->leftNode == NULL && root->rightNode == NULL)
    {
        
        // Only one
        return 1;
    }
    
    // Keep on checking left and right child
    return getLeafCount(root->leftNode) + getLeafCount(root->rightNode);
}

int searchNodeLevel(struct node *root, int data, int level)
{
    if(root == NULL)
    {
        return 0;
    }
    
    if(root->info == data)
    {
        return level;
    }
    
    int downlevel = searchNodeLevel(root->leftNode, data, level+1);
    if(downlevel != 0)
    {
        return downlevel;
    }
    
    downlevel = searchNodeLevel(root->rightNode, data, level+1);
    return downlevel;
        
}

struct node* minNode(struct node *root)
{
    // Check if root is null if so return it
    if(root == NULL)
    {
        return NULL;
    }
    
    // Check the left side of the subtree for null
    while(root->leftNode != NULL)
    {
        //If it is not NULL move to the next left node
        root = root->leftNode;
    }
    
    // Return the root because it is the min
    return root;
}

struct node* maxNode(struct node *root)
{
    // Check if root is null if so return it
    if(root == NULL)
    {
        return NULL;
    }
    
    // Check if the right side of the subtree is NULL
    while(root->rightNode != NULL)
    {
        // Check right until its null
        root = root->rightNode;
    }
    
    // The max is the root
    return root;
    
}


/*
 * Searching the tree depends on the height of the tree
 */
struct node* search(struct node *root, int data)
{
    //While the root is not null look through tree for the number
    while(root !=NULL)
    {
        // Move to left child
        if(data < root->info)
        {
            root = root->leftNode;
        }
        else if(data > root->info)
        {
            root = root->rightNode;
        }
        
        // Root has the number
        else
        {
            return root;
        }
    }
    return NULL;
}

int height(struct node *root)
{
    int heightLeft = 0;
    int heightRight = 0;
    
    if(root == NULL)
    {
        return 0;
    }
    
    heightLeft = height(root->leftNode);
    heightRight = height(root->rightNode);
    
    if(heightLeft > heightRight)
    {
        heightLeft++;
        return heightLeft;
    }
    else
    {
        heightRight++;
        return heightRight;
    }
}



void display(struct node *root, int level)
{
    int i = 0;
    if(root == NULL)
    {
        return;
    }
    
    display(root->rightNode, level+1);
    printf("\n");
    
    for(i = 0; i < level; i++)
    {
        printf("  ");
    }
    printf("%d", root->info);
    //printf("%d", root->Color);
    display(root->leftNode, level+1);
}

void preOrder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ", root->info);
    preOrder(root->leftNode);
    preOrder(root->rightNode);
}

void inOrder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    
    inOrder(root->leftNode);
    printf("%d ", root->info);
    inOrder(root->rightNode);
}

void postOrder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    
    postOrder(root->leftNode);
    postOrder(root->rightNode);
    printf("%d ", root->info);
}

int queueEmpty()
{
    if(front == -1 || front == rear + 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *deleteQueue()
{
    struct node *item;
    if(front == -1 || front == rear + 1)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    
    item = queue[front];
    front = front + 1;
    return item;
}

void levelOrder(struct node *root)
{
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    
    insertQueue(root);
    while(!queueEmpty())
    {
        root = deleteQueue();
        printf("%d ", root->info);
        
        if(root->leftNode != NULL)
        {
            insertQueue(root->leftNode);
        }
        
        if(root->rightNode != NULL)
        {
            insertQueue(root->rightNode);
        }
    }
}

void insertQueue(struct node *item)
{
    if(rear == MAX - 1)
    {
        printf("Queue OverFlow\n");
        return;
    }
    
    if(front == -1)
    {
        front = 0;
    }
    
    rear = rear + 1;
    queue[rear] = item;
}