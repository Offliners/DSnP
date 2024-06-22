#include <iostream>
#include <vector>
#include "bubblesort.h"

BubbleSort::BubbleSort(std::vector<int> &data_in, int flag_in)
{
    data = data_in;
    flag = flag_in;
}

void BubbleSort::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort::sort()
{
    for(int i = 0; i < data.size(); ++i)
    {
        for(int j = i + 1; j < data.size(); ++j)
        {
            if(flag)
                if(data[i] > data[j])
                    swap(data[i], data[j]);
            else
                if(data[i] < data[j])
                    swap(data[i], data[j]);
        }
    }
}

void BubbleSort::display()
{
    for(auto d : data)
        std::cout << d << std::endl;
}
