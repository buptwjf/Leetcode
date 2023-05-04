#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main(int argc, char const *argv[]) {
//    cout << __cplusplus << endl;  // 201402
    unordered_set<int> s;
    pair<unordered_set<int>::iterator, bool> ret;
    ret = s.insert(1);
    if (ret.second == false) {
        cout << "false" << endl;
    }
    ret = s.insert(1);
    if (ret.second == false) {
        cout << "false" << endl;
    }
    ret = s.insert(2);
    if (ret.second == false) {
        cout << "false" << endl;
    }
    ret = s.insert(1);
    if (ret.second == false) {
        cout << "false" << endl;
    }
    return 0;
}
