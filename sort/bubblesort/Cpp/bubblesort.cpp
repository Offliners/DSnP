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
    for(int i = 0; i < data.size() - 1; ++i)
    {
        bool swaped = false;
        for(int j = 0; j < data.size() - 1 - i; ++j)
        {
            if(flag)
            {
                if(data[j + 1] > data[j])
                {
                    swap(data[j + 1], data[j]);
                    swaped = true;
                }
            }
            else
            {
                if(data[j + 1] < data[j])
                {
                    swap(data[j + 1], data[j]);
                    swaped = true;
                }
            }
        }

        if(!swaped)
            break;
    }
}

void BubbleSort::display()
{
    for(auto d : data)
        std::cout << d << std::endl;
}
