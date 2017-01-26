struct node
{
    struct node *leftNode;
    int info;
    struct node *rightNode;
};

struct node *createNode(int x);
struct node *insert(struct node *root, int data);
void display(struct node *root, int level);
void preOrder(struct node *root);
void inOrder(struct node *root);
void postOrder(struct node *root);
void levelOrder(struct node *root);
int height(struct node *root);


#define MAX 100
struct node *queue[MAX];
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
    current->leftNode = NULL;
    current->rightNode = NULL;

    return current;
}

struct node *insert(struct node *root, int data)
{
    if(root == NULL)
    {
        return createNode(data);
    }

    if(data < root->info)
    {
        root->leftNode = insert(root->leftNode, data);
    }

    else if (data > root->info)
    {
        root->rightNode = insert(root->rightNode, data);
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

