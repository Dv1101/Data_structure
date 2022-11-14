#include <iostream>
#include <algorithm>
#include<bits/stdc++.h> 
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;

class Edge
{
  public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
  return e1.weight<e2.weight; //increasing order sort
}

int findParent(int v, int *parent)
{
  if( parent[v]==v)
  {
  return v;
  }
  else
  {
  return findParent(parent[v],parent);
  }
}

void kruskals(Edge *input, int n, int E)
{
  //Sort the input array in ascending order based on weights.
  //using inbuilt sort function. passing starting % end of array.
  //we use our comparision for sort because array type is edge class, it will not compare by default e.g int, float values
  sort(input, input+E, compare);

  Edge *output=new Edge[n-1]; //Output array for mst
  int count=0;
  int i=0;

  int *parent = new int[n]; //parent array for checking loops in mst
  for (int i=0; i<n; i++)
  {
    parent[i]=i;    
  }
  
  while (count!=n-1)
  {
    Edge currentEdge = input[i];
    //check if we can add the current edge in mst or not
    int sourceParent = findParent(currentEdge.source, parent);
    int destParent = findParent(currentEdge.dest, parent);

    if (sourceParent!=destParent)
    {
      output[count]=currentEdge;
      count++;
      parent[sourceParent]=destParent; //update parent to child in parrent array
    }
    i++;
  }

  cout<<endl<<"Output-"<<endl;

  for(int i=0; i <n-1; i++)
  {
    if(output[i].source<output[i].dest)
    {
      cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    }
    else
    {
      cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
    }
    
  }
    
}

int main()
{ 
  int n, E,s,d,w; //n=total no vertices //E=total no edges //input array & its type is edge. no int,double...
  cout<<"Enter number of vertices and edges:- "<<endl; 
  cin>>n>>E;
  Edge *input=new Edge[E];
  cout<<"Source - Destination - Weight"<<endl; 

  for(int i=0; i<E; i++)
  {
    cin>>s>>d>>w;
    input[i].source= s;
    input[i].dest= d;
    input[i].weight= w;
  }
  
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  kruskals(input, n, E);
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout << "finished computation at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";

  return 0;
}

/* Data to enter  
 Enter number of vertices and edges:-  
 6 11 
 Source - Destination - Weight 
 0 1 2 
 1 3 1  
 0 2 4  
 2 4 9 
 4 5 5 
 3 5 7 
 4 3 11 
 2 5 10 
 0 3 3 
 2 1 8 
 2 3 6 
 */
/*  GRAPH:-

          {2}
   0---------------1        
   | -            -|
   |   -{3}  {2} - |
{4}|      -   -    |{1}
   |      -   -    |
   |    -       -  |
   |  -   {6}     -|
   2---------------3    
   | -            -|
   |   -{10} {11}- |
{9}|      -   -    |{1}
   |      -   -    |
   |    -       -  |
   |  -   {6}     -|
   4---------------5

*/

