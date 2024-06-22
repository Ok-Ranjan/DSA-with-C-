#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
    int item;
    int vertex;
    node *next;
};
class AdjList
{
    private:
        node *start;
        int vertex;
    public:
        AdjList();
        AdjList(int);
        node* getStart();
        void setVertex(int);
        void addNode(int,int );
        void removeFirstNode();
        void printList(int);
        ~AdjList();
};
node* AdjList::getStart()
{
    return start;
}
void AdjList::printList(int v)
{
    node *t;
    t=start;
    while(t)
    {
        cout<<"V"<<v<<"("<<t->vertex<<","<<t->item<<") ";
        t=t->next;
    }
}
AdjList::~AdjList()
{
    while(start)
        removeFirstNode();
}
void AdjList::removeFirstNode()
{
    node *r;
    if(start)
    {
        r=start;
        start=start->next;
        delete r;
    }
}
void AdjList::setVertex(int v)
{
    vertex=v;
}
void AdjList::addNode(int v,int data)
{
    node *n=new node;
    n->item=data;
    n->vertex=v;
    n->next=start;
    start=n;
}
AdjList::AdjList()
{
    start=NULL;
}
AdjList::AdjList(int v)
{
    start=NULL;
    vertex=v;
}
class Graph
{
    private:
        int v_count;
        AdjList *arr;
    public:
        Graph();
        int getVCount();
        void createGraph(int);
        void printGraph();
        ~Graph();
        // void BFS(AdjList&);
};
// void Graph::BFS(AdjList &s)
// {
//     queue<AdjList> Q;
//     Q.push(s.);
//     bool
// }
int Graph::getVCount()
{
    return v_count;
}
void Graph::printGraph()
{
    for(int i=0;i<v_count;i++)
    {
        cout<<endl;
        arr[i].printList(i);
    }
}
Graph::~Graph()
{
    delete []arr;
}
void Graph::createGraph(int vno)
{
    int n,v,data;
    v_count=vno;
    arr=new AdjList[v_count];
    for(int i=0;i<v_count;i++)
    {
        arr[i].setVertex(i);
        cout<<"\nHow many adjacent nodes of V"<<i<<":";
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cout<<"\n\tEnter vertex number: ";
            cin>>v;
            cout<<"\t  Enter data to store: ";
            cin>>data;
            // data=10;
            arr[i].addNode(v,data);
        }

    }
    
}
Graph::Graph()
{
    v_count=0;
    arr=NULL;
}
int main()
{
    Graph G;
    G.createGraph(6);
    G.printGraph();
    cout<<endl;
    return 0;

}