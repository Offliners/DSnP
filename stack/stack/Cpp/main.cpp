#include <iostream>
#include <string>
#include <map>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

enum selection {PUSH, POP, DISPLAY, CHECK, EMPTY, FULL};
map<string, selection> selections;

void register_selections()
{
    selections["PUSH"]     = PUSH;
    selections["POP"]      = POP;
    selections["DISPLAY"]  = DISPLAY;
    selections["CHECK"]    = CHECK;
    selections["IS_EMPTY"] = EMPTY;
    selections["IS_FULL"]  = FULL;
}

list<int> toList(stack<int> stack_copy)
{
    list<int> return_list;
    while(!stack_copy.empty())
    {
        return_list.push_back(stack_copy.top());
        stack_copy.pop();
    }
    reverse(return_list.begin(), return_list.end());
    return return_list;
}

int main(void)
{
    int num_cmd;
    cin >> num_cmd;

    int stack_maxsize;
    cin >> stack_maxsize;

    stack<int> s;
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
                if(s.size() < stack_maxsize)
                    s.push(n);
                else
                    cout << "Full" << endl;
                break;
            case POP:
                if(!s.empty())
                    s.pop();
                else
                    cout << "Empty" << endl;
                break;
            case DISPLAY:
                for(auto item : toList(s))
                    cout << item << " ";
                cout << endl;
                break;
            case CHECK:
                cout << s.size() << endl;
                break;
            case EMPTY:
                if(s.empty())
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
                break;
            case FULL:
                if(s.size() >= stack_maxsize)
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
                break;
            default:
                cout << "Unknown command" << endl;
                break;
        }
    }

    return 0;
}