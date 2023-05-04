/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * 采用回溯算法
 * 1. 回溯停止条件：一共有 n 趟航班，当找到一条 n+1 的路之后，就停止
 * 2. 如何记录航班的信息？
 *      2.1
 * 每个机场可能能到达多个机场，每个机场用过以后就不能再用，如何处理映射关系 2.2
 * 最终的结果必须有序，字母越小的越要靠前 采用 unordered_map<出发地机场,
 * map<目的机场, 使用次数> 不能采用 unordered_map<string, multiset<string>>
 * 这样去过一个机场后，进行删除，multi_set 的迭代器就会失效
 * 3. 怎样保证航班的值最小
 *      3.1 map 会对里面的 key 进行自动排序
 * 4. 必须从 JKF 开始
 *      4. 先将 JKF push 进result
 *
 *
 */

class Solution {
private:
    unordered_map<string, map<string, int>> target; // 存储基本信息
    bool backtracking(const int &ticketsNum, vector<string> &result) {
        if (result.size() == ticketsNum + 1) {
            return true;
        }

        string start = *(result.end() - 1);
        for (auto &i: target[start]) {
            if (i.second > 0) { // 用过
                i.second--;
                result.push_back(i.first);
                if (backtracking(ticketsNum, result)) {
                    return true; // 只要发现一个结果，就马上返回。因为第一个满足的一定就是最小的
                }
                result.pop_back();
                i.second++;
            }
        }
        return false;
    }

    void getTarget(vector<vector<string>> &tickets) {
        // 读入数据
        for (auto i: tickets) {
            target[i[0]][i[1]]++; // 初始化 target
        }
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        target.clear();
        getTarget(tickets);
        int ticketsNum = tickets.size(); // 记录飞机票的张数
        vector<string> result;   // 存储结果

        result.push_back("JFK");
        backtracking(ticketsNum, result);
        return result;
    }
};
// @lc code=end

namespace vecTest {
    vector<vector<string>> tickets_1 = {
            {"MUC", "LHR"},
            {"JFK", "MUC"},
            {"SFO", "SJC"},
            {"LHR", "SFO"}};
    vector<vector<string>> tickets_2 = {{"ATL", "JFK"},
                                        {"ATL", "SFO"},
                                        {"JFK", "SFO"},
                                        {"JFK", "ATL"},
                                        {"SFO", "ATL"}};
    vector<vector<string>> tickets_3 = {
            {"JFK", "KUL"},
            {"JFK", "NRT"},
            {"NRT", "JFK"}};

    vector<vector<string>> tickets_4 = {
            {"JFK"}
    };

} // namespace vecTest

int main() {
    Solution s;

    s.findItinerary(vecTest::tickets_2);
    return 0;
}
