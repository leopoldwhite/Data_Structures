#include<iostream>
using namespace std;
const int MAXVEX=100;
bool visited[MAXVEX]={0}; 

template<class t>
class Linkqueue
{
public:
    typedef struct node
    {
        t data;
        node *next;
    }Node;
    Linkqueue();
    ~Linkqueue();
    void Enqueue(t x);
    t Dequeue();
    t Getqueue();
    int Empty(){if(front==rear) return 1;else return 0;}
private:
    Node *front,*rear;
};

template<class t>
Linkqueue<t>::Linkqueue()
{
    Node *s=new Node;
    s->next=NULL;
    front = rear =s;
}

template<class t>
Linkqueue<t>::~Linkqueue()
{
    while(front!=NULL)
    {
        Node *s=front;
        front=front->next;
        delete s;
    }
}

template<class t>
void Linkqueue<t>::Enqueue(t x)
{
    Node *s=new Node;
    s->data=x;
    s->next=NULL;
    rear->next=s;
    rear=s;
}

template<class t>
t Linkqueue<t>::Dequeue()
{
    if(rear==front) throw "underflow";
    Node *p = front->next;
    t x =p->data;
    front->next=p->next;
    if(rear==p) rear=front;
    delete p;
    return x;
}

template<class t>
t Linkqueue<t>::Getqueue()
{
    t x=front->next->data;
    return x;
}

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

void DFS(MGraph *G,int i)
{
    int j;
    visited[i]=true;
    cout<<G->vexs[i];
    for(j=0;j<G->numNodes;j++)
    {
        if(G->arc[i][j]==1&&visited[j]==false) DFS(G,j);
    }
}

void DFS(GraphAdjList *G,int i)
{
    EdgeNode *p=new EdgeNode;
    visited[i]=true;
    cout<<G->adjList[i].data;
    p=G->adjList[i].first;
    while(p!=NULL)
    {
        if(visited[p->adjvex]==false) DFS(G,p->adjvex);
        p=p->next;
    }
}

void DFST(MGraph *G)
{
    int i;
    for(i=0;i<G->numNodes;i++)
    {
        visited[i]=false;
    }
    for(i=0;i<G->numNodes;i++)
    {
        if (visited[i]==false) DFS(G,i);
    }
}

void DFST(GraphAdjList *G)
{
    int i;
    for (i=0;i<G->numNodes;i++) visited[i]=false;
    for (i=0;i<G->numNodes;i++)
    {
        if(visited[i]==false) DFS(G,i);
    }
}

void BFST(MGraph *G)
{
    int i,j;
    Linkqueue<int> Q;
    for (i=0;i<G->numNodes;i++) visited[i]=false;
    for(i=0;i<G->numNodes;i++)
    {
        if(visited[i]==false)
        {
            visited[i]=true;
            cout<<G->vexs[i];
            Q.Enqueue(i);
            while (!Q.Empty())
            {
                i=Q.Dequeue();
                for(j=0;j<G->numNodes;j++)
                {
                    if(G->arc[i][j]==1&&!visited[j])
                    {
                        visited[j]=true;
                        cout<<G->vexs[j];
                        Q.Enqueue(j);
                    }
                }
            }
            
        }
    }
}

void BFST(GraphAdjList *G)
{
    int i,j;
    Linkqueue<int> Q;
    EdgeNode *p=new EdgeNode;
    for(i=0;i<G->numNodes;i++) visited[i]=false;
    for(i=0;i<G->numNodes;i++)
    {
        if(visited[i]==false)
        {
            visited[i]=true;
            cout<<G->adjList[i].data;
            Q.Enqueue(i);
            while(!Q.Empty())
            {
                i=Q.Dequeue();
                p=G->adjList[i].first;
                while(p)
                {
                    if(!visited[p->adjvex])
                    {
                        cout<<G->adjList[p->adjvex].data;
                        visited[p->adjvex]=true;
                        Q.Enqueue(p->adjvex);
                    }
                    p=p->next;
                }
            }
        }
    }
}

int main()
{
    MGraph *mgraph=new MGraph;
    GraphAdjList *graphlist=new GraphAdjList;
    CreateALGraph(graphlist);//9 15 A B C D E F G H I 0 1 0 5 1 2 1 6 1 8 2 3 2 8 3 4 3 6 3 7 3 8 4 5 4 7 5 6 6 7
    BFST(graphlist);
    //DFST(graphlist);
    //CreateMGraph(mgraph);9 15 A B C D E F G H I 0 1 1 0 5 1 1 2 1 1 6 1 1 8 1 2 3 1 2 8 1 3 4 1 3 6 1 3 7 1 3 8 1 //4 5 1 4 7 1 5 6 1 6 7 1
    //BFST(mgraph);
    //DFST(mgraph);
    return 0;
}