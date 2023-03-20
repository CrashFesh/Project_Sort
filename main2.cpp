#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

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

//CLEANING
void cleaning() {
    std::ofstream rewrite("out.dat");
    rewrite.write("", 0);
    rewrite.close();

    return;
}

//QUICKSORT
inline void swap(int * const pa, int * const pb)
{
    int const a = *pa;
    *pa = *pb;
    *pb = a;
}

inline int *partition(IntRange range, auto const pred, IntRange h)
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

            /* ################################################################################################################################################################################ */
            std::string output_string = "";

            for (int i = 0; i < 100; i++) {
                std::string new_string = std::to_string(i);
                new_string += " ";
                new_string += std::to_string(h.begin[i]);
                new_string += '\n';
                output_string += new_string;
            }

            cleaning();

            std::cout << output_string;
	    usleep(200000);
            /* ################################################################################################################################################################################ */
        }
    }
}

inline void quicksort(IntRange const range, IntRange h)
{
    if(range.end - range.begin < 2)
        return;
    int const y = *range.begin;
    int * const mid1 = partition(range,             [y](int x) {return x <  y;}, h);
    int * const mid2 = partition({mid1, range.end}, [y](int x) {return x == y;}, h);
    quicksort({range.begin, mid1}, h);
    quicksort({mid2,   range.end}, h);
}

//SORT TUPAI
void sort_tup(IntRange const range, IntRange h)
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

                /* ################################################################################################################################################################################ */
                std::string output_string = "";

                for (int i = 0; i < 100; i++) {
                    std::string new_string = std::to_string(i);
                    new_string += " ";
                    new_string += std::to_string(h.begin[i]);
                    new_string += '\n';
                    output_string += new_string;
                }

                cleaning();

                std::cout << output_string;
		usleep(200000);
                /* ################################################################################################################################################################################ */
            }
    }
}

//SORT BUBLESORT
void bubblesort(IntRange const range, auto compare, IntRange h)
{
    auto a = range.begin;
    auto const n = range.end - range.begin;
    for(auto i =     0u; i + 1 < n; ++i)
    for(auto j = i + 1u; j     < n; ++j)
        if(!compare(a[i], a[j]))
        {
            swap(a + i, a + j);

            /* ################################################################################################################################################################################ */
            std::string output_string = "";

            for (int i = 0; i < 100; i++) {
                std::string new_string = std::to_string(i);
                new_string += " ";
                new_string += std::to_string(h.begin[i]);
                new_string += '\n';
                output_string += new_string;
            }

            cleaning();

            std::cout << output_string;
	    usleep(200000);
            /* ################################################################################################################################################################################ */
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

inline void selection_sort(IntRange const range, IntRange h)
{
    for(auto it = range.begin; it + 1 < range.end; ++it)
    {
        swap(it, max_element(IntRange{it, range.end}));

        /* ################################################################################################################################################################################ */
        std::string output_string = "";

        for (int i = 0; i < 100; i++) {
            std::string new_string = std::to_string(i);
            new_string += " ";
            new_string += std::to_string(h.begin[i]);
            new_string += '\n';
            output_string += new_string;
        }

        cleaning();

        std::cout << output_string;
	usleep(200000);
        /* ################################################################################################################################################################################ */
    }
}

void reset(int* a) {
    for (int i = 0; i < 200; i++) {
        int first = rand()%100;
        int second = rand()%100;

        swap(a + first, a + second);
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
    int mas[100];
    int i,j;
    srand(time(0));
    for(i = 0;i < 100; i++)
    {
        do
        {
            mas[i] = 1 + rand()%100;
        }
        while(prov(i, mas, mas[i]));
    }

    usleep(2 * 10000000);
    //быстрая сортировка
    IntRange d = {mas, mas + 100};
    IntRange h = d;
    quicksort(d, h);

    reset(mas);

    usleep(2 * 10000000);
    reset(mas);
    usleep(2 * 10000000);
    //тупая сортировка
    d = {mas, mas + 100};
    h = d;
    sort_tup(d, h);

    reset(mas);

    usleep(2 * 10000000);
    reset(mas);
    usleep(2 * 10000000);
    //bublesort от меньшего к большему
    d = {mas, mas + 100};
    h = d;
    bubblesort(d,[](int x, int y){return x < y;}, h);

    reset(mas);

    usleep(2 * 10000000);
    reset(mas);
    usleep(2 * 10000000);
    //bublesort от большего к меньшему
    d = {mas, mas + 100};
    h = d;
    bubblesort(d,[](int x, int y){return x > y;}, h);

    reset(mas);

    usleep(2 * 10000000);
    reset(mas);
    usleep(2 * 10000000);
    //selection_sort
    d = {mas, mas + 100};
    h = d;
    selection_sort(d, h);

    usleep(5 * 10000000);

    return 0;
}
