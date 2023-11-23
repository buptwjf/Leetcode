//
// Created by 86188 on 2023/9/27.
//
#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int res = 0;
    stack<int> st;
    st.push(nums[0]);
    for (int i = 1; i < n; i++) {
        if (nums[i] < st.top()) {
            st.push(nums[i]);
        } else {
            res += st.top();
            st.push(nums[i]);
        }
    }
    cout << res << endl;
    return 0;

}