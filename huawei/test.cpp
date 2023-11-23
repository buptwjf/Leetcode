#include "vector"
#include "iostream"
#include "math.h"
#include "bits/stdc++.h"

using namespace std;
int main() {
    string a, b, ope;
    getline(cin, a);
    getline(cin, b);
    getline(cin, ope);
    vector<int> v1, v2;
    string temp = "";
    for (char i: a) {
        if (i != '[' && i != ']') {
            temp += i;
        }
        if ((i == ' ' || i == ']') && !temp.empty()) {
            v1.emplace_back(stoi(temp));
            temp = "";
        }
    }
    for (char i: b) {
        if (i != '[' && i != ']') {
            temp += i;
        }
        if ((i == ' ' || i == ']') && !temp.empty()) {
            v2.emplace_back(stoi(temp));
            temp = "";
        }
    }

    vector<int> res;
    if (ope == "+") {
         int posa, posb;
         for(posa = v1.size()-1, posb = v2.size()-1; posa>=0 && posb >= 0; posa--, posb--){
             res.emplace_back(v1[posa] + v2[posb]);
         }
         if(posa < 0){
             while (posb >= 0){
                 res.emplace_back(v2[posb]);
                 posb--;
             }
         }else{
             while (posa >= 0){
                 res.emplace_back(v1[posa]);
                 posa--;
             }
         }
    }
    if (ope == "-") {
        int posa, posb;
        for(posa = v1.size()-1, posb = v2.size()-1; posa>=0 && posb >= 0; posa--, posb--){
            res.emplace_back(v1[posa] - v2[posb]);
        }
        if(posa < 0){
            while (posb >= 0){
                res.emplace_back(v2[posb]);
                posb--;
            }
        }else{
            while (posa >= 0){
                res.emplace_back(v1[posa]);
                posa--;
            }
        }
    }

    cout << "[";
    bool flag = false;
    for(int i = res.size() -1; i>= 0; i--){
        if(res[i] != 0) flag = true;
        if(flag){
            cout << res[i];
            if(i!=0) cout << " ";
        }
    }
    if(!flag) cout << 0;
    cout << "]" << endl;

    return 0;
}