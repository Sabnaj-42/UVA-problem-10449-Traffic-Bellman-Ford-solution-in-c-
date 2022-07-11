#include<bits/stdc++.h>
using namespace std;
int inf=10000000;
struct node
{
    int a,b,c;
};
int main()
{
    int n;
    int t=1;
    while(cin>>n)
    {
        int ar[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>ar[i];
        }
        int dist[n+1];
        for(int i=1;i<=n;i++)dist[i]=inf;
        int m;cin>>m;
        struct node graph[m+3];
        for(int i=0;i<m;i++)
        {
            int u,v;cin>>u>>v;
            graph[i].a=u;graph[i].b=v;graph[i].c=(ar[v]-ar[u])*(ar[v]-ar[u])*(ar[v]-ar[u]);

        }
        dist[1]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dist[graph[j].a]<inf)
                {
                    dist[graph[j].b]=min(dist[graph[j].b],dist[graph[j].a]+graph[j].c);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            if(dist[graph[i].a]<inf)
            {
                if(dist[graph[i].b]>dist[graph[i].a]+graph[i].c)
                    dist[graph[i].b]=-inf;
            }
        }
        printf("Set #%d\n",t);
        int q;
        cin>>q;
        while(q--)
        {
            int d;cin>>d;
            if(dist[d]<3||dist[d]==inf)cout<<"?"<<endl;
            else
            cout<<dist[d]<<endl;
        }
        t++;

    }
}
