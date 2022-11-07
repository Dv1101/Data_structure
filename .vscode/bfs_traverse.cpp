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


int main()
{
    for(int i =0; i<N; i++)
        vis[i] = 0;
    int n,m;
    cout<<"Number of nodes: ";
    cin>>n;
    cout<<"\n Number of edges: ";
    cin>>m;
    //Edge input;
    int x,y;
    for (int i = 0; i < m; i++)
    {
        cin >> x  >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty())
    {
        int node = q.front();

        q.pop();
        cout<< node << " ";

        vector<int> :: iterator it;
        for(it= adj[node].begin() ; it != adj[node].end();it++)
        {
            if(!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
  
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";

    //File handling
    // Create and open a text file
    
    string filename("bfscomplexity.txt");
    ofstream file_out;

    file_out.open(filename, std::ios_base::app);
    file_out <<elapsed_seconds.count() << endl;
    cout << "Data stored Successfully !" << endl;
    return 0;
}
//  system("gnuplot -p -e \"set ylabel 'mileseconds' ; set xlabel 'data set' ; p 'D:/SEM 5 programming/DAA Lab/.vscode/bfscomplexity.txt' using 1:2 w lp lc rgb 'red' lw 2 pt 7 title 'BFS','D:/SEM 5 programming/DAA Lab/.vscode/dfscomplexity.txt' using 1:2 w lp lc rgb 'blue' lw 2 pt 7 title 'DFS',/"");

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