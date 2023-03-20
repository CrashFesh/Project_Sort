#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <ctime>
//RANGE
struct IntRange
{
    int *begin;
    int *  end;
};

struct IntConstRange
{
    int const * begin;
    int const * end;
};

//QUICKSORT
inline void swap(int * const pa, int * const pb)
{
    int const a = *pa;
    *pa = *pb;
    *pb = a;
}

inline int *partition(IntRange range, auto const pred, IntRange h, std::ofstream &file)
{
    int *b = range.begin;
    int *e = range.end - 1;
    while(true)
    {
        while(b < range.  end &&  pred(*b))
            ++b;
        while(range.begin < e && !pred(*e))
            --e;
        if(b >= e)
        {
            return b;
        }
        else
        {
            swap(b++, e--);
            for(int i=0; i<99; i++)
            {
                file << h.begin[i] << '\n';
            }
            file << h.begin[99];
            file << std::endl;
        }
    }
}

inline void quicksort(IntRange const range, std::ofstream &file, IntRange h)
{
    if(range.end - range.begin < 2)
        return;
    int const y = *range.begin;
    int * const mid1 = partition(range,             [y](int x) {return x <  y;}, h, file);
    int * const mid2 = partition({mid1, range.end}, [y](int x) {return x == y;}, h, file);
    quicksort({range.begin, mid1}, file, h);
    quicksort({mid2,   range.end}, file, h);
}

//SORT TUPAI
void sort(IntRange const range, IntRange h, std::ofstream &file)
{
    using i64 = std::int64_t;
    int * const a = range.begin;
    i64 const l = range.end - range.begin;
    for(i64 i = 0; i + 1 < l; ++i)
    {
        for(i64 j = i + 1; j < l; ++j)
            if(a[i] > a[j])
            {
                int const t = a[i];
                a[i] = a[j];
                a[j] = t;
                for(int i=0; i<99; i++)
                {
                    file << h.begin[i] << '\n';
                }
                file << h.begin[99];
                file << std::endl;
            }
    }
}

//SORT BUBLESORT
void bubblesort(IntRange const range, auto compare, IntRange h, std::ofstream &file)
{
    auto a = range.begin;
    auto const n = range.end - range.begin;
    for(auto i =     0u; i + 1 < n; ++i)
    for(auto j = i + 1u; j     < n; ++j)
        if(!compare(a[i], a[j]))
        {
            swap(a + i, a + j);
            for(int i=0; i<99; i++)
            {
                file << h.begin[i] << '\n';
            }
            file << h.begin[99];
            file << std::endl;

        }
}

//SELECTION_SORT
inline int *max_element(IntRange const range)
{
    auto max = range.begin;
    for(auto it = range.begin + 1; it < range.end; ++it)
        if(*max < *it)
            max = it;
    return max;
}

inline int const *max_element(IntConstRange const range)
{
    auto max = range.begin;
    for(auto it = range.begin + 1; it < range.end; ++it)
        if(*max < *it)
            max = it;
    return max;
}

inline void selection_sort(IntRange const range,IntRange h, std::ofstream &file)
{
    for(auto it = range.begin; it + 1 < range.end; ++it)
    {
        swap(it, max_element(IntRange{it, range.end}));
        for(int i=0; i<99; i++)
            {
                file << h.begin[i] << '\n';
            }
            file << h.begin[99];
            file << std::endl;
    }

}

//BUG SORT
void bug_sort(IntRange const range, IntRange h, std::ofstream &file) {
    bool flag = false;
    while (!flag) {
        flag = true;
        for (int i = 0; i < rand()%100; i++) {
            int ind1 = rand()%100;
            int ind2 = rand()%100;
            auto a = range.begin;
            swap(a + ind1, a + ind2);
        }

        for(int i=0; i<99; i++) {
            file << h.begin[i] << '\n';
        }
        file << h.begin[99];
        file << std::endl;

        for (int i = 0; i < 99; i++) {
            if (h.begin[i] > h.begin[i + 1]) {
                flag = false;
                break;
            }
        }
    }
    return;
}


int prov(int lim,int mas[],int digit)
{
    int i;
    for(i=0;i<lim;i++)
        if(mas[i]==digit)
            return 1;
    return 0;
}


int main(){
    // int 100;
    // cin >> n;
     int mas[100];
    int i,j;
    srand(time(NULL));
    for(i = 0;i < 100; i++)
    {
        do
        {
            mas[i] = 1 + rand()%100;
        }
        while(prov(i, mas, mas[i]));
    }
/*
    //Файл для быстрой сортировки
    std::ofstream myfile;
    myfile.open ("quick.txt");
    IntRange d = {mas, mas + 100};
    IntRange h = d;
    std::ofstream &chl = myfile;
    quicksort(d, chl, h);
    for(int i=0; i<99; i++){
        myfile << h.begin[i] << '\n';
    }
    myfile << h.begin[99];
    for (auto now : mas){
        std::cout << now << ",";
    }
    myfile.close();
*/
/*
    //Файл для тупой сортировки
    std::ofstream myfile;
    myfile.open ("tupsort.txt");
    IntRange d = {mas, mas + 100};
    IntRange h = d;
    std::ofstream &chl = myfile;
    sort(d, h, chl);
    for(int i=0; i<99; i++){
        myfile << h.begin[i] << '\n';
    }
    myfile << h.begin[99];
    for (auto now : mas){
        std::cout << now << ",";
    }
    myfile.close();
*/
/*
    //Файл bublesort от меньшего к большему
    std::ofstream myfile;
    myfile.open ("bublesortotmkB.txt");
    IntRange d = {mas, mas + 100};
    IntRange h = d;
    std::ofstream &chl = myfile;
    bubblesort(d,[](int x, int y){return x < y;}, h, chl);
    for(int i=0; i<99; i++){
        myfile << h.begin[i] << '\n';
    }
    myfile << h.begin[99];
    for (auto now : mas){
        std::cout << now << ",";
    }
    myfile.close();
*/
/*
    //Файл bublesort от большего к меньшему
    std::ofstream myfile;
    myfile.open ("bublesortotBkm.txt");
    IntRange d = {mas, mas + 100};
    IntRange h = d;
    std::ofstream &chl = myfile;
    bubblesort(d,[](int x, int y){return x > y;}, h, chl);
    for(int i=0; i<99; i++){
        myfile << h.begin[i] << '\n';
    }
    myfile << h.begin[99];
    for (auto now : mas){
        std::cout << now << ",";
    }
    myfile.close();
*/
/*
    //Файл selection_sort
    std::ofstream myfile;
    myfile.open ("selection_sort.txt");
    IntRange d = {mas, mas + 100};
    IntRange h = d;
    std::ofstream &chl = myfile;
    selection_sort(d, h, chl);
    for(int i=0; i<99; i++){
        myfile << h.begin[i] << '\n';
    }
    myfile << h.begin[99];
    for (auto now : mas){
        std::cout << now << ",";
    }
    myfile.close();
*/

    //Файл bug-sort
    std::ofstream myfile;
    myfile.open ("bug-sort.txt");
    IntRange d = {mas, mas + 100};
    IntRange h = d;
    std::ofstream &chl = myfile;
    bug_sort(d, h, chl);
    for(int i=0; i<99; i++){
        myfile << h.begin[i] << '\n';
    }
    myfile << h.begin[99];
    for (auto now : mas){
        std::cout << now << ",";
    }
    myfile.close();

    return 0;
}
