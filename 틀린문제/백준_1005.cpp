/*
!!!YOU Wrong!!!
*/


/*
Claude 설명 
:

1. dp[i]는 i번째 건물을 짓기까지 필요한 최소시간을 저장
2. dp[next] = max(dp[next], dp[current] + build_time[next])
(생각해보니 굳이 priority가 뭐가 우선인지 계산 안하고 max함수로 총합을 비교해줬으면 되었음..아)
3. 이전에 계산된 결과를(dp[current])를 이용해 다음 건물의 최소 시간을 계산하는 것이 DP의 핵심 원리 

*/


/*

*/

#include <iostream>
#include <vector>
#include <queue>

int find_min_time(int N, std::vector<int>& build_time, 
std::vector<std::vector<int>>& graph,std::vector<int>& in_degree, int winning)
{
    // dp[i] : i번의 건물까지 짓는데 필요한 최소 시간을 저장하는 DP 테이블
    // 이 값은 해당 건물의 건설 시간 + 선행 건물들의 건설 시간 중 최대값이 됨

    std::vector<int> dp(N+1);

    // DP 테이블 초기화 
    // 처음에는 각 건물들의 단독 건설 시간으로 초기화 

    // 위상 정렬을 위한 큐
    // 진입 차수가 0인 건물들을 먼저 큐에 삽입 (시작점이 되는 건물들)
    std::queue<int>q;

    for(int i = 1; i <=N; i++)
    {
        if(in_degree[i] == 0)
        {
            q.push(i);
            dp[i] = build_time[i];
        }
    }

    // 위상정렬을 수행 
    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        // 현재 건물에서 건설할 수 있는 다음 건물들을 확인
        for (auto next : graph[current]){
            // DP의 점화식이 적용되는 부분
            // dp[next]는 다음 건물까지의 최소 건설 시간
            // dp[current] + build_time[next]는 현재 건물을 거쳐서 다음 건물을 짓는 경우의 시간
            // max 연산을 사용하는 이유 : 여러 선행 건물이 있을 때 가장 오래 걸리는 경우를 선택해야함.
            dp[next] = std::max(dp[next], dp[current]);
            
            // 진입 차수를 감소시키고 건설 가능한 상태가 되면 큐에 추가
            in_degree[next]--;
            if(in_degree[next] == 0)
            {
                dp[next] +=build_time[next];
                q.push(next);
            }
        }
    }

    return dp[winning];
}  

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        int N,K;
        std::cin >> N >> K;

        std::vector<int> build_time(N+1);
        for(int i = 1; i <= N ; i++)
        {
            std::cin >> build_time[i];
        }

        // 그래프 초기화 : 건설 순서를 표현하는 인접 리스트
        std::vector<std::vector<int>> graph(N+1);
        // 진입차수 배열 : 각 건물들의 선행 건물 수를 저장.
        // 즉 Rule에서 앞에 오는 게 있는 경우 
        std::vector<int> in_degree(N+1,0);
        for(int i = 0; i < K ; i++)
        {
            int X, Y;
            std::cin >> X >> Y;
            graph[X].push_back(Y);
            in_degree[Y]++;
        }

        int W;
        std::cin >> W;
        std::cout << find_min_time(N, build_time, graph, in_degree, W) << std::endl;
    }

    return 0;
}