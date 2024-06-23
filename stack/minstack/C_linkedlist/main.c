#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minstack.h"

#define PUSH    1
#define POP     2
#define TOP     3
#define DISPLAY 4
#define CHECK   5
#define EMPTY   6
#define FULL    7
#define MIN     8
#define UNKNOWN -1

typedef struct SELECTIONS{
    char *key;
    int val;
} selections;

static selections register_selections[] = {
    {"PUSH"    , PUSH},
    {"POP"     , POP},
    {"GET_TOP" , TOP},
    {"DISPLAY" , DISPLAY},
    {"CHECK"   , CHECK},
    {"IS_EMPTY", EMPTY},
    {"IS_FULL" , FULL},
    {"GET_MIN" , MIN}
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

    int stack_maxsize;
    scanf("%d", &stack_maxsize);

    minstack *min_s = (minstack*)malloc(sizeof(minstack));
    initialize(min_s, stack_maxsize);

    char cmd[10];
    char temp;
    int n;
    for(int i = 0; i < num_cmd; ++i)
    {
        scanf("%s", cmd);
        switch(keyfromstring(cmd))
        {
            case PUSH:
                scanf("%d", &n);
                push(min_s, n);
                break;
            case POP:
                pop(min_s);
                break;
            case TOP:
                top(min_s);
                break;
            case DISPLAY:
                display(min_s);
                break;
            case CHECK:
                check(min_s);
                break;
            case EMPTY:
                empty(min_s);
                break;
            case FULL:
                full(min_s);
                break;
            case MIN:
                get_min(min_s);
                break;
            default:
                printf("Unknown command\n");
                break;
        }
    }

    free_stack(min_s);

    return 0;
}