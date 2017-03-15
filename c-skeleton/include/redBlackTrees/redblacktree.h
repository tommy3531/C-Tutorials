typedef enum NodeColor {
    BLACK,
    RED,
    EMPTY
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
int compare(int, int);






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

Node *insertNode(Node *treeRoot, Node *nodeInsert, int data)
{
    //Node * newNode = NULL;
    // Check if the tree is NULL
    if(treeRoot == NULL)
    {
        // If the tree is NULL add the data to tree
        treeRoot = createNode(data);
        treeRoot->color = BLACK;
        treeRoot->parent = treeRoot;
        return treeRoot;
    }
    else {
        int is_left = 0;
        int compareValue = 0;
        nodeInsert = treeRoot;
        Node *prev = NULL;

        while (nodeInsert != NULL)
        {
            nodeInsert = createNode(data);
            compareValue = compare(nodeInsert->value, treeRoot->value);
            prev = nodeInsert;
            if (compareValue <= 0)
            {
                is_left = 1;
                prev = treeRoot;
                nodeInsert = nodeInsert->left;
            }
            else if (compareValue >= 0)
            {
                is_left = 0;
                nodeInsert = nodeInsert->right;
            }

        }

        if (is_left) {
            prev->left = createNode(data);
        } else {
            prev->right = createNode(data);
        }

    }
    return treeRoot;
}

void fixTree(Node *insertNode, int data)
{
    printf("This is the FixTree Function\n");
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