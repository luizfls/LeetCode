class Solution {
private:
    using Graph = std::unordered_map<int, std::vector<int>>;

    Graph buildGraph(int numCourses,
                     const std::vector<std::vector<int>>& prerequisites)
    {
        Graph g;

        for(int i = 0; i < numCourses; ++i)
            g[i];

        for(const auto& prerequisite : prerequisites)
            g[prerequisite[1]].push_back(prerequisite[0]);

        return g;
    }

    void computeInDegrees(const Graph& g, std::vector<int>& in)
    {
        for(const auto& [v, edges] : g)
            for(auto e : edges)
                ++in[e];
    }

    bool hasCycle(const Graph& g, int numCourses)
    {
        std::vector<int> in(numCourses, 0);
        computeInDegrees(g, in);
        std::queue<int> next;
        for(int i = 0; i < in.size(); ++i)
            if(in[i] == 0)
                next.push(i);
        if(next.empty()) return true;
        while(!next.empty())
        {
            auto curr = next.front();
            next.pop();
            for(auto n : g.at(curr))
                if(--in[n] == 0)
                    next.push(n);
        }
        return std::any_of(in.begin(), in.end(), [](int i){ return i != 0; });
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        auto g = buildGraph(numCourses, prerequisites);
        return !hasCycle(g, numCourses);
    }
};
