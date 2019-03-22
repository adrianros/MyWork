#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("bfs.in");
ofstream out("bfs.out");
vector <int> adiacenta[100003];

int main()
{
    int m,n,s,i,nod1,nod2,st,dr;
    in>>n>>m>>s;
    int dist[100003];
    int viz[100003];
    int coada[100003];
    for(i=0; i<=n; i++)
    {
        dist[i]=-1;
        coada[i]=0;
        viz[i]=0;
    }

    for(i=1; i<=m; i++)
    {
        in>>nod1>>nod2;
        adiacenta[nod1].push_back(nod2);
    }

    dist[s]=0;
    viz[s]=1;
    coada[1]=s;
    st=dr=1;
    while(st<=dr)
    {
        int index=coada[st];
        int lim=adiacenta[index].size();
        for(i=0; i<lim; i++)
        {
            int vecin=adiacenta[index][i];
            if(viz[vecin]==0)
            {
                dist[vecin]=dist[index]+1;
                viz[vecin]=1;
                dr++;
                coada[dr]=vecin;
            }
        }
        st++;
    }

    for(i=1; i<=n; i++)
        out<<dist[i]<<" ";
    return 0;
}
