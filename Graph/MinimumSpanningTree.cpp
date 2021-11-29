#include<iostream>
#include<iomanip>
using namespace std;
const int MAXVEX=100;
const int INFI=65535;

struct Edge
{
    int begin;
    int end;
    int weigh;
};

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
            if(i==j)
            {
                G->arc[i][j]=0;
            }
            else G->arc[i][j]=INFI;
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

void MST_Prim(MGraph *G)
{
    int sum=0;
    int min,i,j,k;
    int adjvex[MAXVEX];
    int lowcost[MAXVEX];
    adjvex[0]=0;
    lowcost[0]=0;
    for (i=1;i<G->numNodes;i++)
    {
        lowcost[i]=G->arc[0][i];
        adjvex[i]=0;
    }

    for(i=1;i<G->numNodes;i++)
    {
        min=INFI;
        j=1;k=0;
        while(j<G->numNodes)
        {
            if(lowcost[j]!=0&&lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;
            }
            j++;
        }
        sum+=lowcost[k];
        lowcost[k]=0;
        cout<<"("<<adjvex[k]<<","<<k<<") ";
        for(j=1;j<G->numNodes;j++)
        {
            if(lowcost[j]!=0&&G->arc[k][j]<lowcost[j])
            {
                lowcost[j]=G->arc[k][j];
                adjvex[j]=k;
            }
        }
    }
    cout<<endl;
    cout<<sum<<endl;
}

int ChangeToEdges(MGraph *G,Edge *edges)
{
    int i,j,k;
    k=0;
    for (i=0;i<G->numNodes;i++)
    {
        for(j=i+1;j<G->numNodes;j++)
        {
            if(G->arc[i][j]!=INFI)
            {
                edges[k].begin=i;
                edges[k].end=j;
                edges[k].weigh=G->arc[i][j];
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        for(j=k-2;j>=i;j--)
        {
            Edge temp;
            if(edges[j].weigh>edges[j+1].weigh)
            {
                temp=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;
            }
        }
    }
    return k;
}

int Find(int *parent,int f)
{
    while(parent[f]>0)
    {
        f=parent[f];
    }
    return f;
}

void MST_Kruskal(MGraph *G)
{
    int i,j,n,m,k;
    Edge edges[MAXVEX];
    int parent[MAXVEX];
    k=ChangeToEdges(G,edges);
    for(i=0;i<k;i++)
        parent[i]=0;
    for(i=0;i<G->numEdges;i++)
    {
        n=Find(parent,edges[i].begin);
        m=Find(parent,edges[i].end);
        if(n!=m)
        {
            parent[n]=m;
            cout<<"("<<edges[i].begin<<","<<edges[i].end<<")"<<" "<<edges[i].weigh<<endl;
        }
    }
}

int main()
{
    MGraph *Graph=new MGraph;
    CreateMGraph(Graph); //4 4 a b c d 0 1 10 0 2 9 1 3 8 2 3 7
    MST_Kruskal(Graph);
    //MST_Prim(Graph);
    return 0;
}