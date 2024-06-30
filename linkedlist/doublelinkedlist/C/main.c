#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublelinkedlist.h"

#define APPEND  1
#define INSERT  2
#define DISPLAY 3
#define POP     4
#define REMOVE  5
#define CHECK   6
#define EMPTY   7
#define MIDDLE  8
#define REVERSE 9
#define UNKNOWN -1

typedef struct SELECTIONS{
    char *key;
    int val;
} selections;

static selections register_selections[] = {
    {"APPEND"  , APPEND},
    {"INSERT"  , INSERT},
    {"POP"     , POP},
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

    doublelinkedlist *dll = (doublelinkedlist*)malloc(sizeof(doublelinkedlist));
    initialize(dll);

    char cmd[10];
    int index, n, temp;
    for(int i = 0; i < num_cmd; ++i)
    {
        scanf("%s", cmd);
        switch(keyfromstring(cmd))
        {
            case APPEND:
                scanf("%d", &n);
                append(dll, n);
                break;
            case INSERT:
                scanf("%d %d", &index, &n);
                insert(dll, index, n);
                break;
            case POP:
                pop(dll);
                break;
            case DISPLAY:
                display(dll);
                break;
            case REMOVE:
                scanf("%d", &index);
                remove_node(dll, index);
                break;
            case CHECK:
                printf("%d\n", check(dll));
                break;
            case EMPTY:
                if(empty(dll))
                    printf("True\n");
                else
                    printf("False\n");
                break;
            case MIDDLE:
                temp = find_middle(dll);
                if(temp == -1)
                    printf("Empty\n");
                else
                    printf("%d\n", temp);
                break;
            case REVERSE:
                reverse(dll);
                break;
            default:
                printf("Unknown command\n");
                break;
        }
    }

    free_list(dll);

    return 0;
}