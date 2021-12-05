#include<iostream>
#include<iomanip>
using namespace std;
const int MAXVEX=100;
const int INFINITY=65535;
const int MAXEDGE=20;

struct MGraph
{
    string vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];//邻接矩阵
    int numNodes,numEdges;
};
typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];


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
            G->arc[i][j]=INFINITY;
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
void ShowGraph(MGraph *G)
{
    int i,j;
    for (i=0;i<G->numNodes;i++)
    {
        for (j=0;j<G->numNodes;j++)
        {
            cout<<left;
            //cout.unsetf(ios_base::left);
            cout<<setw(5)<<G->arc[i][j]<<" ";
        }
        cout<<endl;
    }
}

void ShortestPath_Dijkstra(MGraph *G,int v0,int *P,int *D)
{
    int v,w,k,min;
    int final[MAXVEX];
    for(v=0;v<G->numNodes;v++)
    {
        final[v]=0;
        D[v]=G->arc[v0][v];
        P[v]=-1;
    }
    D[v0]=0;
    final[v0]=1;
    for(v=1;v<G->numNodes;v++)
    {
        min=INFINITY;
        for(w=0;w<G->numNodes;w++)
        {
            if(!final[w]&&D[w]<min)
            {
                k=w;
                min=D[w];
            }
        }
        final[k]=1;
        for(w=0;w<G->numNodes;w++)
        {
            if(!final[w]&&(min+G->arc[k][w]<D[w]))
            {
                D[w]=min+G->arc[k][w];
                P[w]=k;
            }
        }
    }
}

void ShortestPath_Floyd(MGraph *G,int (*P)[MAXVEX],int (*D)[MAXVEX])
{
    int v, w,k;
    for(v=0;v<G->numNodes;v++)
    {
        for(w=0;w<G->numNodes;w++)
        {
            D[v][w]=G->arc[v][w];
            P[v][w]=w;
        }
    }

    for(k=0;k<G->numNodes;k++)
    {
        for(v=0;v<G->numNodes;v++)
    {
        for(w=0;w<G->numNodes;w++)
        {
            if(D[v][w]>D[v][k]+D[k][w])
            {
                D[v][w]=D[v][k]+D[k][w];
                P[v][w]=P[v][k];
            }
        }
    }
    }
}


int main()
{
    int (*P)[MAXVEX]=new int [MAXVEX][MAXVEX];
    int (*D)[MAXVEX]=new int [MAXVEX][MAXVEX];
    MGraph *Graph=new MGraph;
    CreateMGraph(Graph);//4 4 a b c d 0 1 1 0 2 1 1 3 2 2 3 3
    //ShowGraph(Graph);
    //ShortestPath_Dijkstra(Graph,0,P,D);
    ShortestPath_Floyd(Graph,P,D);
    cout<<*(*P+3);
    return 0;
}