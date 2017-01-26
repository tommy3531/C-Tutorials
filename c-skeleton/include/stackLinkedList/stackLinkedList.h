struct node
{
    int info;
    struct node *link;
};

struct node *top;

void initializeStack();
int isEmpty();
int size();
void push(int x);
int pop();
int peek();
void display();

void initializeStack()
{
    top = NULL;
}

int size()
{
    int nodeCount = 0;
    struct node *current;

    current = top;

    while(current != NULL)
    {
        current = current->link;
        nodeCount++;
    }

    return nodeCount;
}

void push(int valueToStack)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("No memory: Stack Overflow \n");
        return;
    }

    temp->info = valueToStack;
    temp->link = top;
    top = temp;
}

int pop()
{
    struct node *temp;

    int valueOffStack;
    if(isEmpty())
    {
        printf("Stack UnderFlow\n");
        exit(1);
    }

    temp = top;
    valueOffStack = temp->info;
    top = top->link;
    free(temp);
    return valueOffStack;
}

int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return top->info;
}

int isEmpty()
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    struct node *current;
    current = top;

    if(isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack is : \n\n");
    while(current != NULL)
    {
        printf("%d\n", current->info);
        current = current->link;
    }

    printf("\n");
}


