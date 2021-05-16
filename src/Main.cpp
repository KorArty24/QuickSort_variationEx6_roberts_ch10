#include <iostream>
#include "console.h"
#include "vector.h"
#include "random.h"
#include<iterator>
using namespace std;
void sort(vector<int> &vec);
void quicksort(vector<int> &vec, int start, int finish);
int partition (vector<int> &vec, int start, int finish);
int findMedian(vector<int> &vec, int begin, int mid, vector<int>::iterator end);
int main() {
  return 0;
}

void quicksort(vector<int> &vec, int start, int finish){
    if (start >=finish) return;
    int boundary = partition (vec,start, finish);
    quicksort(vec, start, boundary);
    quicksort(vec,boundary+1,finish);
}

int partition(vector<int> & vec, int start, int finish){
    int mid= (vec.size()%2==0)? vec.size()/2: (vec.size()-1)/2;
    int pivot = findMedian(vec,0,mid,vec.end());
    int lh=start;
    int rh=finish;
    while (true){
        while (lh<rh && vec[rh] >=pivot) rh--;
        while (lh<rh && vec[lh] < pivot) lh++;
        if (lh==rh) break;
        int tmp=vec[lh];
        vec[lh]=vec[rh];
        vec[rh]=tmp;
    }
    if (vec[lh] >= pivot) return start;
    vec[start]=vec[lh];
    vec[lh]=pivot;
    return lh;
}

int findMedian(vector<int> &vec, int begin, int mid, vector<int>::iterator end){
     if (vec.size()==1){
         int median=vec[0];
         return median;
     }

     vector<int>::iterator ptr;
     int pow=0;
     int random_n=randomInteger(begin,(vec.size()-1)-pow);
     int v=vec[random_n];
     end=vec.end();
     int count=0;
     int temp=0;
     for (ptr=vec.begin()+begin; ptr!=end; ++ptr) {
        if (*ptr<v) {
            temp=*ptr;
            vec.erase(ptr);
            vec.emplace(vec.begin(),temp);
         } else if (*ptr>v) {
             count++;
             temp=*ptr;
             vec.erase(ptr);
             vec.emplace(vec.end(),temp);
         }
 }

     pow=vec.size() - count;
     begin=pow;
     if (pow < mid){
        return findMedian(vec,pow,mid,end);
    } else if (pow == mid) {return vec[mid];
    } else {
        return findMedian (vec,0, mid, end-pow);
    }

 }


