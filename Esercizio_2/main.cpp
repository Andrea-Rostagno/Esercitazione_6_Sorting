#include<iostream>
#include<chrono>
#include<unistd.h>
#include<vector>
#include<numeric>
#include<algorithm>
#include"src/SortingAlgorithm.hpp"


using namespace std;
using namespace chrono;

int main()
{
    int lunghezza=10;
    cout<<"lunghezza "<<lunghezza<<endl;
    vector<int> v;
    int a=0;
    for (int i = 0; i < lunghezza; ++i) {
        a=rand()%100;
        v.push_back(a);
        cout<<v[i]<<" ";

    }
    cout<<endl;

    std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
    _sleep(1);
    //SortLibrary::BubbleSort(v);
    SortLibrary::MergeSort(v);
    std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count();
    cout<<"la durata e "<<duration<<endl;
    cout<<"v nuovo ";
    for (int i = 0; i < lunghezza; ++i) {
        cout<<v[i]<<" ";

    }
    //SortLibrary::MergeSort(v);














    return 0;
}

