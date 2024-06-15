#include <iostream>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

enum selection {PUSH, POP, FRONT, DISPLAY, CHECK, EMPTY, FULL};
map<string, selection> selections;

void register_selections()
{
    selections["PUSH"]      = PUSH;
    selections["POP"]       = POP;
    selections["GET_FRONT"] = FRONT;
    selections["DISPLAY"]   = DISPLAY;
    selections["CHECK"]     = CHECK;
    selections["IS_EMPTY"]  = EMPTY;
    selections["IS_FULL"]   = FULL;
}

list<int> toList(queue<int> queue_copy)
{
    list<int> return_list;
    while(!queue_copy.empty())
    {
        return_list.push_back(queue_copy.front());
        queue_copy.pop();
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

    queue<int> q;
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
                if(q.size() < stack_maxsize)
                    q.push(n);
                else
                    cout << "Full" << endl;
                break;
            case POP:
                if(!q.empty())
                    q.pop();
                else
                    cout << "Empty" << endl;
                break;
            case FRONT:
                if(!q.empty())
                    cout << q.front();
                cout << endl;
                break;
            case DISPLAY:
                if(!q.empty())
                    for(auto item : toList(q))
                        cout << item << " ";
                cout << endl;
                break;
            case CHECK:
                cout << q.size() << endl;
                break;
            case EMPTY:
                if(q.empty())
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
                break;
            case FULL:
                if(q.size() >= stack_maxsize)
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