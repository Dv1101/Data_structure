#include<bits/stdc++.h>
#include <algorithm>
#include<bits/stdc++.h> 
#include <chrono>
#include <ctime>
#include <fstream>

using namespace std;
using namespace std::chrono;

const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];

void dfs(int node)
{
    //preorder
    vis[node] = 1;
    cout<< node << " ";
    // inorder
    vector<int> :: iterator it;
    for(it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if(vis[*it]);
        else
        {
            dfs(*it);
        }
    } 
    //  For postorder remove from above
    // cout<< node << " ";
}

int main()
{
    int n,m;
    cout<<"Number of nodes: ";
    cin>>n;
    cout<<"\n Number of edges: ";
    cin>>m;

    for(int i =0 ; i<=n ; i++)
        vis[i] = false;
    int x,y;
    for (int i = 0; i < m; i++)
    {
        cin >> x  >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    dfs(1); 
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
  
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
    
    //File handling
    // Create and open a text file
    string filename("dfscomplexity.txt");
    ofstream file_out;

    file_out.open(filename, std::ios_base::app);
    file_out <<elapsed_seconds.count() << endl;
    cout << "Data stored Successfully !" << endl;

    return 0;
}
/*
7
7


1 2
1 3
2 4
2 5
2 6
2 7
3 7
*/

/*
        1
       / \
      2   3
    /|\ \  \ 
   / | \  \ \   
  /  |  \   \\    
 4   5   6    7  
*/  