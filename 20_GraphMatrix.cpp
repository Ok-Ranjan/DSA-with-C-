#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class GraphMatrix
{
    private:
        int v_count;    //total nodes in graph
        int e_count;    //total edges in graph
        int **adj;  //to point matrix
    public:
        int getVcount();
        int& getAdj();
        void createGraph(int,int); //take argements, total number of nodes and edges in graph
        void printMatrix();
        void printAdjNode(int); //take a argement as node number
        bool isIsolated(int); //take a argement as node number
        ~GraphMatrix();
};
int& GraphMatrix::getAdj()
{
    return **adj;
}
// vector<int>& BFS(GraphMatrix &G,int &s)
// {
//     // int &adj=G.getAdj();
//     int Vcount=G.getVcount();
//     int v[Vcount];
//     int n;
//     vector<int> *D;
//     queue<int> Q;
//     Q.push(s);
//     D->push_back(s);
//     v[s]=true;
//     while(!Q->empty())
//     {
//         n=Q->front();
//         Q->pop();
//         for(int u=0;u<Vcount;u++)
//         {
//             if([*s][u])
//             {
//                 D->push_back(u);
//                 if(v[u]==false)
//                 {
//                     Q->push(u);
//                     v[u]=true;
//                 }
//             }
//         }
//     }
//     return *D;
// }
void GraphMatrix::createGraph(int vno,int eno)
{
    int u,v;
    v_count=vno;
    e_count=eno;
    adj=new int*[v_count];  //create a array of pointer
    for(int i=0; i<v_count; i++)
        adj[i]=new int[v_count];
    for(int i=0; i<v_count; i++)
        for(int j=0; j<v_count; j++)
            adj[i][j]=0;
    for(int k=1; k<=e_count; k++)
    {
        cout<<"Enter node number and connecting edge";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
}
void GraphMatrix::printMatrix()
{
    cout<<endl;
    for(int i=0; i<v_count; i++)
    {
        for(int j=0; j<v_count; j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}
void GraphMatrix::printAdjNode(int v)
{
    if(v<v_count && v>=0)
    {
        for(int i=0; i<v_count; i++)
            if(adj[v][i])
                cout<<endl<<"v"<<i;
    }
}
int GraphMatrix::getVcount()
{
    return v_count;
}
bool GraphMatrix::isIsolated(int v)
{
    bool flag=true;
    if(v<v_count && v>=0)
    {
        for(int i=0; i<v_count; i++)
            if(adj[v][i])
            {
                flag=false;
                break;
            }
    }
    return flag;
}
GraphMatrix::~GraphMatrix()
{
    for(int i=0; i<v_count; i++)
        delete adj[i];
    delete adj;
}
int main()
{
    GraphMatrix g1;
    g1.createGraph(6,9);
    g1.printAdjNode(2);
    g1.printMatrix();
    // BFS(g1,g1.getAdj());
        
}