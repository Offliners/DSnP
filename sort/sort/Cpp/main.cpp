#include <iostream>
#include <vector>
#include <algorithm>

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

    if(!flag)
        sort(data.begin(), data.end());
    else
        sort(data.begin(), data.end(), greater<>());

    for(auto d : data)
        cout << d << endl;

    return 0;
}