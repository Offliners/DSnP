#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

#define APPEND  1
#define INSERT  2
#define DISPLAY 3
#define REMOVE  4
#define CHECK   5
#define EMPTY   6
#define MIDDLE  7
#define REVERSE 8
#define UNKNOWN -1

typedef struct SELECTIONS{
    char *key;
    int val;
} selections;

static selections register_selections[] = {
    {"APPEND"  , APPEND},
    {"INSERT"  , INSERT},
    {"DISPLAY" , DISPLAY},
    {"REMOVE"  , REMOVE},
    {"CHECK"   , CHECK},
    {"EMPTY"   , EMPTY},
    {"MIDDLE"  , MIDDLE},
    {"REVERSE" , REVERSE}
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
    int num_cmd;
    scanf("%d", &num_cmd);

    linkedlist *ll = (linkedlist*)malloc(sizeof(linkedlist));
    initialize(ll);

    char cmd[10];
    char temp;
    int index, n;
    for(int i = 0; i < num_cmd; ++i)
    {
        scanf("%s", cmd);
        switch(keyfromstring(cmd))
        {
            case APPEND:
                scanf("%d", &n);
                append(ll, n);
                break;
            case INSERT:
                scanf("%d %d", &index, &n);
                insert(ll, index, n);
                break;
            case DISPLAY:
                display(ll);
                break;
            case REMOVE:
                scanf("%d", &index);
                remove_node(ll, index);
                break;
            case CHECK:
                printf("%d\n", check(ll));
                break;
            case EMPTY:
                empty(ll);
                break;
            case MIDDLE:
                find_middle(ll);
                break;
            case REVERSE:
                reverse(ll);
                break;
            default:
                printf("Unknown command\n");
                break;
        }
    }

    free_list(ll);

    return 0;
}