enum color { BLACK, RED };

struct node
{
    struct node *leftNode;
    int info;
    enum color Color;
    struct node *rightNode;
    
};

struct node *createNode(int x);
struct node *insert(int data);
void display(struct node *root, int level);
void preOrder(struct node *root);
void inOrder(struct node *root);
void postOrder(struct node *root);
void levelOrder(struct node *root);
int height(struct node *root);


#define MAX 100
struct node *queue[MAX];
struct node *root = NULL;

int front = -1;
int rear = -1;

void insertQueue(struct node *item);
struct node *deleteQueue();
int queueEmpty();
struct node *deleteQueue();

struct node *createNode(int x)
{
    struct node *current;
    current = (struct node *)malloc(sizeof(struct node));
    current->info = x;
    current->Color = RED;
    current->leftNode = NULL;
    current->rightNode = NULL;

    return current;
}

struct node *insert(int data)
{
    if(root == NULL)
    {
        root = createNode(data);
        root->Color = BLACK;
        return root;
    }

    else if(data < root->info)
    {
        if(root->leftNode == NULL)
        {
            root->leftNode = root;
        }
        else
        {
            root = root->leftNode;
        }

    }

    else if(data > root->info)
    {
        if(root->rightNode == NULL)
        {
            root->rightNode = root;
        }
        else
        {
            root = root->rightNode;
        }
    }


    return root;
}

void display(struct node *root, int level)
{
    int i;
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
    printf("%d", root->Color);
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

int height(struct node *root)
{
    int heightLeft;
    int heightRight;

    if(root == NULL)
    {
        return 0;
    }

    heightLeft = height(root->leftNode);
    heightRight = height(root->rightNode);

    if(heightLeft > heightRight)
    {
        return 1+heightLeft;
    }
    else
    {
        return 1+heightRight;
    }
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

//printf("This is from the binaryTree.c\n");
//struct node *tree = NULL;
//tree = insert(50);
//tree = insert(30);
//tree = insert(20);
//tree = insert(40);
//tree = insert(70);
//tree = insert(60);
//tree = insert(80);
//
//display(tree, 0);
//printf("\n\n");
//
//display(tree, 1);
//printf("\n\n");
//
//
//printf("Preorder: ");
//preOrder(tree);
//printf("\n\n");
//
//printf("Inorder: ");
//inOrder(tree);
//printf("\n\n");
//
//printf("PostOrder: ");
//postOrder(tree);
//printf("\n\n");
//
//printf("Level order: ");
//levelOrder(tree);
//printf("\n\n");
//
//printf("Height of tree is %d\n", height(tree));