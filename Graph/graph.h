#ifdef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<iomanip>
using namespace std;
const int MAXVEX=100;

struct MGraph
{
    string vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];//邻接矩阵
    int numNodes,numEdges;
};

void CreateMGraph(MGraph* &G)
{
    int i,j,k,w;
    cout<<"enter numNodes and numEdges"<<endl;
    cin>>G->numNodes>>G->numEdges;
    cout<<"enter the vexs"<<endl;
    for(i=0;i<G->numNodes;i++)
    {
        
        cin>>G->vexs[i];
    }
    for(i=0;i<G->numNodes;i++)
    {
        for(j=0;j<G->numNodes;j++)
        {
            G->arc[i][j]=65535;
        }
    }
    for(k=0;k<G->numEdges;k++)
    {
        cout<<"enter (i,j) of the edge and the weight w "<<endl;
        cin>>i>>j>>w;
        G->arc[i][j]=w;
        G->arc[j][i]=w;//无向图
    }
}

struct EdgeNode
{
    int adjvex;
    int weight;
    EdgeNode *next;
};

struct VertexNode
{
    string data;
    EdgeNode *first;
};

struct GraphAdjList
{
    VertexNode adjList[MAXVEX];
    int numNodes,numEdges;
};

void CreateALGraph(GraphAdjList *G)
{
    EdgeNode *e=new EdgeNode;
    int i,j,k;
    cout<<"enter num of nodes and edges"<<endl;
    cin>>G->numNodes>>G->numEdges;
    for (i=0;i<G->numNodes;i++)
    {
        cin>>G->adjList[i].data;
        G->adjList[i].first=NULL;
    }

    for(k=0;k<G->numEdges;k++)
    {
        cout<<"enter (i,j)"<<endl;
        cin>>i>>j;
        e=new EdgeNode;
        e->adjvex=j;
        e->next=G->adjList[i].first;
        G->adjList[i].first=e;
        e=new EdgeNode;//无向图，对（j,i）同理；
        e->adjvex=i;
        e->next=G->adjList[j].first;
        G->adjList[j].first=e;
    }
}

#endif
