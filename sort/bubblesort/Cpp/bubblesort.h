#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_

#include <vector>

class BubbleSort {
    public:
        BubbleSort() {};
        BubbleSort(std::vector<int>&, int);
        void swap(int &, int &);
        void sort();
        void display();

    private:
        int flag = 0;
        std::vector<int> data = {};
};

#endif