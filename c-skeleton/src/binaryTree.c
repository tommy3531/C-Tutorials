#include <stdio.h>
#include <stdlib.h>
#include "../include/binaryTrees/binaryTree.h"

struct jsw_node
{
    int red;
    int data;
    struct jsw_node *link[2];
};

struct jsw_tree
{
    struct jsw_node *root;
};

int main(int argc, const char *argv[])
{



}

struct jsw_node *jsw_insert(struct jsw_node *root, int data)
{
    if (root == NULL)
    {
        root = make_node(data);
    }
    else
    {
        int dir = root->data < data;
        
        root->link[dir] = jsw_insert(root->link[dir], data);
    }
    
    return root;
}

int is_red(struct jsw_node *root)
{
    return root != NULL && root->red == 1;
}

struct jsw_node *jsw_single(struct jsw_node *root, int dir)
{
    struct jsw_node *save = root->link[!dir];
    
    root->link[!dir] = save->link[dir];
    save->link[dir] = root;
    
    root->red = 1;
    save->red = 0;
    
    return save;
}

struct jsw_node *jsw_double(struct jsw_node *root, int dir)
{
    root->link[!dir] = jsw_single(root->link[!dir], !dir);
    
    return jsw_single(root, dir);
}

int jsw_rb_assert(struct jsw_node *root)
{
    int lh, rh;
    
    if (root == NULL)
    {
        return 1;
    }
    else
    {
        struct jsw_node *ln = root->link[0];
        struct jsw_node *rn = root->link[1];
        
        /* Consecutive red links */
        if (is_red(root))
        {
            if (is_red(ln) || is_red(rn))
            {
                puts("Red violation");
                return 0;
            }
        }
        
        lh = jsw_rb_assert(ln);
        rh = jsw_rb_assert(rn);
        
        /* Invalid binary search tree */
        if ((ln != NULL && ln->data >= root->data) || (rn != NULL && rn->data <= root->data))
        {
            puts("Binary tree violation");
            return 0;
        }
        
        /* Black height mismatch */
        if (lh != 0 && rh != 0 && lh != rh)
        {
            puts("Black violation");
            return 0;
        }
        
        /* Only count black links */
        if (lh != 0 && rh != 0)
        {
            return is_red(root) ? lh : lh + 1;
        }
        else
        {
            return 0;
        }
    }
}

