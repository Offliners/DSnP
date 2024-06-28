#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree.h"

#define PREORDER   1
#define INORDER    2
#define POSTORDER  3
#define LEVELORDER 4
#define UNKNOWN    -1

typedef struct SELECTIONS{
    char *key;
    int val;
} selections;

static selections register_selections[] = {
    {"PREORDER"   , PREORDER},
    {"INORDER"    , INORDER},
    {"POSTORDER"  , POSTORDER},
    {"LEVELORDER" , LEVELORDER}
};

#define NUM_KEY (sizeof(register_selections)/sizeof(selections))

int keyfromstring(char *key)
{
    for(int i = 0; i < NUM_KEY; ++i)
    {
        selections select = register_selections[i];
        if(!strcmp(select.key, key))
            return select.val;
    }

    return UNKNOWN;
}

int main(void)
{
    int num_data;
    scanf("%d", &num_data);

    int *data = (int*)malloc(num_data * sizeof(int));
    for(int i = 0; i < num_data; ++i)
        scanf("%d", &data[i]);

    int num_cmd;
    scanf("%d", &num_cmd);

    char cmd[10];
    char temp;
    int n;
    for(int i = 0; i < num_cmd; ++i)
    {
        scanf("%s", cmd);
        switch(keyfromstring(cmd))
        {
            case PREORDER:
                break;
            case INORDER:
                break;
            case POSTORDER:
                break;
            case LEVELORDER:
                break;
            default:
                printf("Unknown command\n");
                break;
        }
    }


    return 0;
}