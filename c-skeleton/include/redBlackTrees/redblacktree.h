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
void fixTree(Node *root, Node *newNode);






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

Node *insertNode(Node* root, Node * int data)
{
    /* If the tree is empty, return a new node */
    if (root == NULL) {
        root = createNode(data);
        root->color = BLACK;
        return root;
    }
    
    Node *nodeInsert = NULL;
    nodeInsert = createNode(data);
    /* Otherwise, recur down the tree */
    if (root->value > nodeInsert->value) {
        root->right = insertNode(root->right, data);
        root->right->parent = nodeInsert;
    }
    else if (root->value < nodeInsert->value) {
    
        root->left = insertNode(root->left, data);
        root->left->parent = nodeInsert;
    
    }
    
    /* return the (unchanged) node pointer */
    //return root;

    fixTree(root, nodeInsert);
    // This is an issue
    return root;
}


//Everything is inserted fix the color and properites

void fixTree(Node *root, Node *newNode)
{
    //Node *uncle = NULL;
    if(root == newNode){
        newNode->color = BLACK;
        printf("Node is black\n");
    }
    else
    {
        printf("Root is not null next node should be red\n");
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