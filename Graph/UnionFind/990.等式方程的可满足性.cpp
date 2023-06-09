/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class UF {
    // 将 p 和 q 连接
private:
    int count; // 连通区域的个数
    int *parent; // 记录各个节点的父亲

public:
    // 构造函数
    UF(int n) {
        // 一开始互不相连
        count = n; // 记录联通区域的总数
        parent = new int[n]; // 申请 n 个大小来放置父节点的位置

        for (int i = 0; i < n; i++) {
            parent[i] = i; // 在初始时候每个节点的父节点指向自己
        }
    }

    // 连接两个节点
    // 当两个节点的祖先相同时，将他们指向同一个祖先
    void combine(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) {
            return;
        }
        parent[rootQ] = rootP;
        count--;
    }

    // 判断两个节点是否具有联通性
    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }


    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }


    int getCount() {
        return count;
    }
};

/*
 * 以有 = 的关系创建并查集合，然后看 != 能不能破坏之间的连接关系
 */


class Solution {
public:
    bool equationsPossible(vector<string> &equations) {
        // 26 个字母
        UF uf(26);
        // 以 == 关系创建并查集
        for (const string &eq: equations) {
            if (eq[1] == '=') {
                char x = eq[0];
                char y = eq[3];
                uf.combine(x - 'a', y - 'a');
            }
        }

        // 以 != 关系创建并查集
        for (const string &eq: equations) {
            if (eq[1] == '!') {
                char x = eq[0];
                char y = eq[3];
                if (uf.connected(x - 'a', y - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

