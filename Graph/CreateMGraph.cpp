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

int main()
{
    MGraph *Graph=new MGraph;
    CreateMGraph(Graph);//4 4 a b c d 0 1 1 0 3 1 1 2 1 2 3 1
    ShowGraph(Graph);
    return 0;
}