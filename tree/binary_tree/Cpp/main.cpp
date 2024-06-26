#include <iostream>
#include <vector>
#include <map>
#include "binarytree.h"

using namespace std;

enum selection {
    PREORDER,
    INORDER,
    POSTORDER,
    LEVELORDER
};
map<string, selection> selections;

void register_selections()
{
    selections["PREORDER"]  = PREORDER;
    selections["INORDER"]  = INORDER;
    selections["POSTORDER"] = POSTORDER;
    selections["LEVELORDER"]  = LEVELORDER;
}

int main(void)
{
    int num_data;
    cin >> num_data;
    vector<int> data;
    int in;
    for(int i = 0; i < num_data; ++i)
    {
        cin >> in;
        data.push_back(in);
    }

    BinaryTree bt(data);
    register_selections();

    string cmd;
    int num_cmd;
    cin >> num_cmd;
    for(int i = 0; i < num_cmd; ++i)
    {
        cin >> cmd;
        switch(selections[cmd])
        {
            case PREORDER:
                bt.preorder_traversal(bt.root);
                cout << endl;
                break;
            case INORDER:
                bt.inorder_traversal(bt.root);
                cout << endl;
                break;
            case POSTORDER:
                bt.postorder_traversal(bt.root);
                cout << endl;
                break;
            case LEVELORDER:
                bt.levelorder_traversal();
                cout << endl;
                break;
            default:
                cout << "Unknown command" << endl;
                break;
        }
    }

    bt.free_tree();
    return 0;
}