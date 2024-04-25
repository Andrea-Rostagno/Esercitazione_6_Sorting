#include<iostream>
#include<chrono>
#include<unistd.h>
#include<vector>
#include<numeric>
#include<algorithm>
#include <random>
#include"src/SortingAlgorithm.hpp"

using namespace std;
using namespace chrono;

int BubbleTime(vector<int> v){
    steady_clock::time_point t_begin = steady_clock::now();
    _sleep(1);
    SortLibrary::BubbleSort(v);
    steady_clock::time_point t_end = steady_clock::now();
    double duration = duration_cast<milliseconds>(t_end - t_begin).count();
    //cout<<"la durata ammonta a: "<<duration<<" millisecondi"<<endl;
    return duration;
}

int MergeTime(vector<int> v){
    steady_clock::time_point t_begin = steady_clock::now();
    _sleep(1);
    SortLibrary::MergeSort(v);
    steady_clock::time_point t_end = steady_clock::now();
    double duration = duration_cast<milliseconds>(t_end - t_begin).count();
    //cout<<"la durata ammonta a: "<<duration<<" millisecondi"<<endl;
    return duration;
}

int main()
{
    double Somma1=0;
    double Somma2=0;
    int lunghezza=10;
    int n=5;
    cout<<"Lunghezza vettore "<<lunghezza<<endl;
    vector<int> v(lunghezza);
    for (int i = 0; i < n; ++i) {
        mt19937 rng(random_device{}());
        uniform_int_distribution<int> dist(1, 100);
        cout<<"Vettore casuale "<<i+1<<": ";
        for (int i = 0; i < lunghezza; ++i) {
            v[i]=dist(rng);
            cout<<v[i]<<" ";
        }
        cout<<endl;
        Somma1=Somma1+BubbleTime(v);
        Somma2=Somma2+MergeTime(v);
    }
    cout<<"La media dei tempi di BubbleSort: "<<Somma1/n<<" millisecondi"<<endl;
    cout<<"La media dei tempi di MergeSort: "<<Somma2/n<<" millisecondi"<<endl;

    return 0;
}


