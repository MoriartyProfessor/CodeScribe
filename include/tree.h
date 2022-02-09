#ifndef TREE_H
#define TREE_H

#include <string.h>
#include <gtk/gtk.h>

#define NODES_MAX 100
#define STRING_MAX 255

struct TreeNode
{
    const char* str[STRING_MAX];
    int lastNode;
    struct TreeNode* nodes[NODES_MAX];
};

typedef struct TreeNode TreeNode;

void node_init(TreeNode **src, const char* str)
{
    (*src) = (TreeNode*) malloc(sizeof(int));
    (*src)->lastNode = 0;
    strcpy((*src)->str, str);
}

void node_insert(TreeNode *src, TreeNode** to_ins, const char* str)
{
    if(src->lastNode==NODES_MAX)
        return;

    node_init(to_ins, str);
    src->nodes[src->lastNode] = *to_ins;
    src->lastNode++;
}

void free_tree(TreeNode *src)
{
    if(src==NULL)
        return;
    for(int i=0;i<src->lastNode;++i)
    {
        free_tree(src->nodes[i]);
    }
    free(src);
}

#endif
