#include <iostream>
#include <vector>
using namespace std;
vector< pair<int,int> > miau[11110];
int viz[1000];
int dist[1000];

int s,k,i,m,n,INF=99999,mi,cost,x,y;
void prelucrare()
{


    dist[1]=0;


    for(int t = 1; t <= n; t++)
    {

            int minim=1000000005, mi = -1;
            for(i=1; i <= n; ++i)
                if(dist[i]<minim && viz[i]==0)
                {

                    mi = i;
                    minim=dist[i];
                }
            viz[mi]=1;
            int dim2=miau[mi].size();
            for(i=0; i<dim2; ++i) {
                int vecin = miau[mi][i].first;
                int cost_muchie = miau[mi][i].second;
                if(cost_muchie + dist[mi] < dist[vecin])
                    dist[vecin] = dist[mi] + cost_muchie;
            }

    }


}
int main()
{

    cin>>n;
    cin>>m;

    for(i=0; i<m; ++i)
    {
        cin>>x>>y;
        cin>>cost;
        miau[x].push_back(make_pair(y,cost));

    }

    for(int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[1] = 0;
    prelucrare();
    for(i=2;i<=n;++i)
        cout<<dist[i]<<" ";



    return 0;
}
