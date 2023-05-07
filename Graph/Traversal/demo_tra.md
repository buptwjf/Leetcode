
// 记录被遍历过的节点
vector<bool> visited;
// 记录从起点到当前节点的路径
vector<bool> onPath;

/* 图遍历框架 */
void traverse(Graph graph, int s) {
    if (visited[s]) return;
    // 经过节点 s，标记为已遍历
    visited[s] = true;
    // 做选择：标记节点 s 在路径上
    onPath[s] = true;
    for (int neighbor : graph.neighbors(s)) {
        traverse(graph, neighbor);
    }
    // 撤销选择：节点 s 离开路径
    onPath[s] = false;
}

在 visited 中被标记为 true 的节点用灰色表示，在 onPath 中被标记为 true 的节点用绿色表示，类比贪吃蛇游戏，visited 记录蛇经过过的格子，而 onPath 仅仅记录蛇身。在图的遍历过程中，onPath 用于判断是否成环，类比当贪吃蛇自己咬到自己（成环）的场景，