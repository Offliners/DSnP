#include <iostream>
#include <string>
#include <map>
#include "minstack.h"

using namespace std;

enum selection {
    UNKNOWN,
    PUSH, 
    POP, 
    TOP, 
    DISPLAY, 
    CHECK, 
    EMPTY, 
    FULL, 
    MIN
};

map<string, selection> selections;

void register_selections()
{
    selections["PUSH"]     = PUSH;
    selections["POP"]      = POP;
    selections["GET_TOP"]  = TOP;
    selections["DISPLAY"]  = DISPLAY;
    selections["CHECK"]    = CHECK;
    selections["IS_EMPTY"] = EMPTY;
    selections["IS_FULL"]  = FULL;
    selections["GET_MIN"]  = MIN;
}

int main(void)
{
    int num_cmd;
    cin >> num_cmd;

    int stack_maxsize;
    cin >> stack_maxsize;

    MinStack min_s(stack_maxsize);
    string cmd;
    register_selections();
    for(int i = 0; i < num_cmd; ++i)
    {
        cin >> cmd;
        switch(selections[cmd])
        {
            case PUSH:
                int n;
                cin >> n;
                min_s.push(n);    
                break;
            case POP:
                min_s.pop();    
                break;
            case TOP:
                if(!min_s.empty())
                    cout << min_s.top();
                cout << endl;
                break;
            case DISPLAY:
                if(!min_s.empty())
                    min_s.display();
                cout << endl;
                break;
            case CHECK:
                cout << min_s.check() << endl;
                break;
            case EMPTY:
                if(min_s.empty())
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
                break;
            case FULL:
                if(min_s.full())
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
                break;
            case MIN:
                if(!min_s.empty())
                    cout << min_s.get_min() << endl;
                else
                    cout << "Empty" << endl;
                break;
            default:
                cout << "Unknown command" << endl;
                break;
        }
    }

    return 0;
}