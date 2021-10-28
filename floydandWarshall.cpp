#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Floyd–Warshall algorithm is an algorithm for finding shortest paths in a directed weighted graph with positive or negative edge weights. 

void floyds(int graph[4][4],int v)//2d array dimension should be specified
{
   vector<vector<int>> dist(v,vector<int>(v, 0));
   for(int i=0;i<v;++i)
   {
       for(int j=0;j<v;++j)
       {
           dist[i][j]=graph[i][j];
       }
   }
   for(int k=0;k<v;++k)
   {
       for(int i=0;i<v;++i)
       {
           for(int j=0;j<v;++j)
           {
               if(i==k or j==k or i==j)
               continue;
               if(dist[i][k]!=INT_MAX and dist[k][j]!=INT_MAX)
               dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);//this all should be dist matrixes since we update them again and again using dp
           }
       }
   }
   for(int i=0;i<v;++i)
   {
       for(int j=0;j<v;++j)
       {
           if(dist[i][j]==INT_MAX)
           cout<<"infinity"<< "     ";
           else 
           cout<<dist[i][j]<< "     ";
       }
       cout<<endl;
   }
}
    
    
    
int main()
 {
   int graph[4][4]={{0    , 5   , INT_MAX,  10},
                {INT_MAX,0    ,  3   ,INT_MAX},
                {INT_MAX,INT_MAX,   0,   1},
                {INT_MAX,INT_MAX,INT_MAX,0}} ;  

    floyds(graph,4);

 }
