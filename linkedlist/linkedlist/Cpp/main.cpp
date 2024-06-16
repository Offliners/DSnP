#include <iostream>
#include <string>
#include <map>
#include "linkedlist.h"

using namespace std;

enum selection {
    APPEND,
    INSERT,
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

    LinkedList ll;
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
                ll.append(n);
                break;
            case INSERT:
                cin >> index >> n;
                ll.insert(index, n);
                break;
            case DISPLAY:
                ll.display();
                break;
            case REMOVE:
                cin >> n;
                ll.remove(n);
                break;
            case CHECK:
                n = ll.check();
                cout << n << endl;
                break;
            case EMPTY:
                if(ll.empty())
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
                break;
            case MIDDLE:
                n = ll.find_middle();
                if(n == -1)
                    cout << "Empty" << endl;
                else
                    cout << n << endl;
                break;
            case REVERSE:
                ll.reverse();
                break;
            default:
                cout << "Unknown command" << endl;
                break;
        }
    }

    ll.free_list();

    return 0;
}