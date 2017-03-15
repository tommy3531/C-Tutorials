typedef enum NodeColor {
    BLACK,
    RED,
}NodeColor;

typedef struct Node
{
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    int value;
    NodeColor color;
    
}Node;

typedef struct Info
{
    int numRed;
    int numBlack;
    
}Info;

Node *mainRBTree = NULL;

// Function Prototype
int compare(int left, int right);






// This function creates a red node with the parameters passed in
// Returns a fully initialized Red node that is ready to be inserted into the Tree
Node* createNode(int value)
{
    // Need a pointer to a Node
    Node* newNode = NULL;
    
    // Malloc space for new node
    newNode = (Node *)malloc(sizeof(Node));
    
    // fill struct members
    newNode->color = RED;
    newNode->value = value;
    newNode->left  = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    
    // return the newly created node
    return newNode;
}

Node *insertNode(Node *insertNode, int data)
{
    // Check if the tree is NULL
    if(mainRBTree == NULL)
    {
        // If the tree is NULL add the data to tree
        mainRBTree = createNode(data);
    }
    else {
        int is_left = 0;
        int compareValue = 0;
        insertNode = mainRBTree;
        Node *prev = NULL;
        
        while (insertNode != NULL)
        {
            compareValue = compare(data, insertNode->value);
            prev = insertNode;
            if (compareValue < 0)
            {
                is_left = 1;
                insertNode = insertNode->left;
            }
            else if (compareValue > 0)
            {
                is_left = 0;
                insertNode = insertNode->right;
            }
        
        }
        if (is_left) {
            prev->left = createNode(data);
        } else {
            prev->right = createNode(data);
        }
    
    }
    return mainRBTree;
}

void fixTree(Node *insertNode, int data)
{
    printf("This is the FixTree Function\n");
}