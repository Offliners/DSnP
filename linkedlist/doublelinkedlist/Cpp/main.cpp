#include <iostream>
#include <string>
#include <map>
#include "doublelinkedlist.h"

using namespace std;

enum selection {
    UNKNOWN,
    APPEND,
    INSERT,
    POP,
    DISPLAY,
    REMOVE,
    CHECK,
    EMPTY,
    MIDDLE,
    REVERSE
};

map<string, selection> selections;

void register_selections()
{
    selections["APPEND"]  = APPEND;
    selections["INSERT"]  = INSERT;
    selections["POP"]  = POP;
    selections["DISPLAY"] = DISPLAY;
    selections["REMOVE"]  = REMOVE;
    selections["CHECK"]   = CHECK;
    selections["EMPTY"]   = EMPTY;
    selections["MIDDLE"]  = MIDDLE;
    selections["REVERSE"] = REVERSE;
}

int main(void)
{
    int num_cmd;
    cin >> num_cmd;

    DoubleLinkedList dll;
    string cmd;
    register_selections();
    for(int i = 0; i < num_cmd; ++i)
    {
        cin >> cmd;
        switch(selections[cmd])
        {
            int n, index;
            case APPEND:
                cin >> n;
                dll.append(n);
                break;
            case INSERT:
                cin >> index >> n;
                dll.insert(index, n);
                break;
            case POP:
                dll.pop();
                break;
            case DISPLAY:
                dll.display();
                break;
            case REMOVE:
                cin >> n;
                dll.remove(n);
                break;
            case CHECK:
                n = dll.check();
                cout << n << endl;
                break;
            case EMPTY:
                if(dll.empty())
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
                break;
            case MIDDLE:
                n = dll.find_middle();
                if(n == -1)
                    cout << "Empty" << endl;
                else
                    cout << n << endl;
                break;
            case REVERSE:
                dll.reverse();
                break;
            default:
                cout << "Unknown command" << endl;
                break;
        }
    }

    dll.free_list();

    return 0;
}