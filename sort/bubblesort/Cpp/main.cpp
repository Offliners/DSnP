#include <iostream>
#include <vector>
#include "bubblesort.h"

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int flag;
    cin >> flag;

    vector<int> data;
    for(int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        data.push_back(temp);
    }

    BubbleSort s(data, flag);
    s.sort();
    s.display();

    return 0;
}