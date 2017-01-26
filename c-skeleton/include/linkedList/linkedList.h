struct node
{
    int info;
    struct node *link;
};

struct node *createList(struct node *head);
void displayList(struct node *head);
struct node *insertAtBeginning(struct node *head, int nodeValue);
void insertAtEnd(struct node *head, int nodeValue);
void insertAfter(struct node *head, int insertValueIntoNewNode, int insertAfterThisValue);
struct node *insertBefore(struct node *head, int insertValueIntoNewNode, int insertAfterThisValue );
struct node *insertAtPosition(struct node *head, int insertValueIntoNewNode, int listPosition);

struct node *createList(struct node *head)
{
    int numberOfNodes;
    int nodeValue = 0;

    // Ask how many nodes they would like
    printf("Enter the number of nodes you would like: \n");
    scanf("%d", &numberOfNodes);

    // if number of nodes is zero return head
    if(numberOfNodes == 0)
    {
        return head;
    }

    printf("Enter the first element to be inserted: ");
    scanf("%d", &nodeValue);

    // Insert at the beginning
    head = insertAtBeginning(head, nodeValue);

    // Start at second node and insertAtTheEnd
    for(int i = 2; i <= numberOfNodes; i++)
    {
        printf("Enter the next element to be insert: ");
        scanf("%d", &nodeValue);
        insertAtEnd(head, nodeValue);
    }
    return head;

}

struct node *insertAtBeginning(struct node *head, int nodeValue)
{
    struct node *temp;

    // Malloc space for the temp node according to the struct size
    temp=(struct node *)malloc(sizeof(struct node));

    // Initialized the info part
    temp->info = nodeValue;

    // temp link points to head
    temp->link = head;

    // make temp the head
    head = temp;

    return head;


}

void insertAtEnd(struct node *head, int nodeValue)
{
    struct node *current;
    struct node *temp;

    // Malloc space for temp
    temp = (struct node *)malloc(sizeof(struct node));

    // Initialize info with the nodeValue
    temp->info = nodeValue;

    // The current node is the head
    current = head;

    // Using the current node run thorugh the links until it is not NULL
    while(current->link != NULL)
    {
        // Once you get to the next node link make it the current node until you reach NULL
        current = current->link;
    }

    // Since we are not the end of the list store the temp in the current->link
    current->link = temp;

    // Know make the temp link NULL so it will be at the end
    temp->link = NULL;
}

void displayList(struct node *head)
{
    // Declare a new struct to store current position
    struct node *current;

    // Check if the head pointer is null
    if(head == NULL)
    {
        // The list is empty
        printf("The list is empty: \n");
    }

    printf("List is: ");

    // Current node points to head
    current = head;

    // Print out the values from the until you reach the end AKA NULL
    while(current != NULL)
    {
        // Print out the value
        printf("%d", current->info);

        // Move to the next node by use the link
        current = current->link;
    }

    printf("\n");
}

void countNodes(struct node *head)
{
    int count = 0;
    struct node *current;
    current = head;

    while(current != NULL)
    {
        count++;
        current = current->link;
    }
    printf("Number of nodes in the list = %d\n", count);
}

void search(struct node *head, int numberToSearchFor)
{
    struct node *current;
    int position = 1;
    current = head;

    while(head != NULL)
    {
        // Check to see this the value == to the search int
        if(current->info == numberToSearchFor)
        {
            break;
        }
        position++;
        current = current->link;
    }
    if(current == NULL)
    {
        printf("%d not found in list\n", numberToSearchFor);
    }
    else
    {
        printf("%d is at position %d\n", numberToSearchFor, position);
    }
}

void insertAfter(struct node *head, int insertValueIntoNewNode, int insertAfterThisValue)
{
    struct node *temp;
    struct node *current;

    // Make the current pointer the head
    current = head;

    // Move through the links of current while it does not equal null
    while(current != NULL)
    {
        // When you reach a new struct check info to see if it is equal to searchValue
        if(current->info == insertAfterThisValue)
        {
            break;
        }

        // Move to the next struct link
        current = current->link;
    }

    if(current == NULL)
    {
        printf("%d not present in the list\n", insertAfterThisValue);
    }

    // Found the nodeValue lets create a new node and insert after
    else
    {
        // Need to malloc space for temp
        temp = (struct node *)malloc(sizeof(struct node));

        // Initalize info with nodeValueToInsert
        temp->info = insertValueIntoNewNode;

        // Initialize temp link with current link info
        temp->link = current->link;

        // Have current->link point to temp
        current->link = temp;

    }

}

struct node *insertBefore(struct node *head, int insertValueIntoNewNode, int insertAfterThisValue)
{
    struct node *current;
    struct node *temp;

    // Check if Head if NULL
    if(head == NULL)
    {
        printf("Head is empty: \n");
        return head;
    }

    // Check to see if head is the value to insert Before
    if(insertAfterThisValue == head->info)
    {
        // Malloc space for temp
        temp = (struct node *)malloc(sizeof(struct node));

        // Initialize temp info with the nodeValueToInsert
        temp->info = insertValueIntoNewNode;

        // Initialize temp link with head
        temp->link = head;

        // Make temp head
        head = temp;

        // Return the head node
        return head;
    }

    // Have current points to head
    current = head;

    // Run through the links
    while(current->link != NULL)
    {
        if(current->link->info == insertAfterThisValue)
        {
            break;
        }
        current = current->link;
    }

    if(current->link == NULL)
    {
        printf("%d not present in the list\n", insertAfterThisValue);
    }

    // The value is found, insert before the node
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = insertValueIntoNewNode;
        temp->link = current->link;
        current->link = temp;

    }
    return head;
}

struct node *insertAtPosition(struct node *head, int insertValueIntoNewNode, int listPosition)
{
    struct node *temp;
    struct node *current;
    int i;

    if(listPosition == 1)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = insertValueIntoNewNode;
        temp->link = head;
        head = temp;
        return head;
    }

    current = head;
    for(i = 1; i < listPosition - 1 && current != NULL; i++)
    {
        current = current->link;
    }

    if(current == NULL)
    {
        printf("You can insert only upto %dth position \n", i);
    }
    else
    {
        // Need space for the new node
        temp = (struct node *)malloc(sizeof(struct node));

        // Initialize info with the vale
        temp->info = insertValueIntoNewNode;

        // Initialize temp link with current link
        temp->link = current->link;

        // Have the current link point to temp
        current->link = temp;

    }
    return head;
}

