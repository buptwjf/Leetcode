//
// Created by 86188 on 2023/4/29.
//
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <deque>
#include <stack>
#include <list>
#include <queue>
using namespace std;

int main() {
//    array<int, 8> a = {7,6,5,4,3,8,5,5};
//    sort(a.begin(), a.end());
//    for(auto i: a){
//        cout << i << " ";
//    }
//    multiset<int> b = {5,2,3,4};
//    for(auto i : b){
//        cout << i << " ";
//    }
//    cout <<endl;
//    cout <<sizeof(a) << endl;
    list<int> a = {1, 7, 5, 2, 3};
    for (auto i: a) {
        cout << i << " ";
    }
    std::is_sorted(a.begin(), a.end());
    sort(a.begin(),a.end());
}