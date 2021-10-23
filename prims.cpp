#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
//how to pass graph in arguements without defining its vertex
#define V 4
#define IN INT_MAX

   //this is using adjacency matrix
void printGraph(int graph[V][V],vector<int> &parent)
{
    cout<<"edge\t cost"<<endl;
    for(int i=1;i<V;++i)
    cout<<parent[i]<<"-"<<i<<"\t"<<graph[parent[i]][i]<<endl;

}

int minKey(vector<int> &key,vector<bool> &mstSet)
{
    int minIndex,min=INT_MAX;
    for(int i=0;i<V;++i)
    {
        if(mstSet[i]==false and key[i]<min)
        min=key[i],minIndex=i;
    }
    return minIndex;
}

void prims(int graph[V][V])
{
    vector<int> key(V,INT_MAX);
    vector<bool> mstSet(V,false);
    vector<int> parent(V);
    key[0]=0;//to pick first one we intentionaly init to zero
    parent[0]=-1;//since first vertex doesn't have parent

    //to choose min key vertex from set of vertices not included in MST
    for(int i=0;i<V;++i)
    {
        int u = minKey(key,mstSet);// first time 0 is picked since we made it to zero
        mstSet[u]=true;

        //now update key values and parent index of adjacent vertices of picked vertex which are not in mstSet
        for(int v=0;v<V;++v)
        {   //graph[u][v]=0 means cost to travel to itself
            if(graph[u][v]!=0 and mstSet[v]==false and graph[u][v]<key[v])
                parent[v]=u,key[v]=graph[u][v];
        }
    }
    printGraph(graph,parent);
}




int main()
{
    int graph[V][V]={   {0,1,4,8},
                        {1,0,2,IN},
                        {4,2,0,3 },
                        {8,IN,3,0}};

            prims(graph);
}
