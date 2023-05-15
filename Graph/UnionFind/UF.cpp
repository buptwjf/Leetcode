//
// Created by 86188 on 2023/5/9.
//

/*
 * 创建一个并查集：对应于无向图
 *
 */
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


// 寻找某个节点的根节点
//int find(int x) {
//    int root = x;
//    while (parent[root] != root) {
//        root = parent[root];
//    }
//    // 然后把 x 到根节点之间的所有节点直接接到根节点下面
//    int old_parent = parent[x];
//    while (x != root) {
//        parent[x] = root;
//        x = old_parent;
//        old_parent = parent[old_parent];
//    }
//    return root;
//}