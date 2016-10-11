#include <bits/stdc++.h>

using namespace std;

std::vector<std::vector<long long int > > graph;
std::vector<long long int> visited;
std::queue<long long int> Q;
long long int c_count;

long long int BFS(long long int node)
{
  visited[node] = ++c_count;
  Q.push(node);
  long long int result = 1;
  while(!Q.empty())
  {
     long long int u = Q.front();
     Q.pop();
     for(long long int i = 0; i < graph[node].size(); i++)
     {
       long long int v = graph[node][i];
       if(visited[v]==0)
       {
           visited[v] = c_count;
           result++;
           Q.push(v);
       }
     }
  }
  return result;
}

int main()
{
  long long int number, edges;
  cin >> number >> edges;

  graph.resize(number);
  visited.resize(number,0);

  for (long long int i = 0; i < edges; i++)
  {
    long long int a,b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  long long int result = 0;
  long long int sum = 0;
  long long int x_count;

  for (long long int i = 0; i < graph.size(); i++)
  {
    if (visited[i] == 0)
    {
      x_count = BFS(i);
      result+=sum*x_count;
      sum+=x_count;
    }
  }

  std::cout << result << std::endl;

  return 0;
}
