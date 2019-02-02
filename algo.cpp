#include<iostream>
#include<list>
#include<iterator>

using namespace std;

int n,s,g;
int **a;
int *states,*parent,*visited,*cost;

int main()
{
	int i,j,k,o=0;
	list <int> ord,t;
	list<int>::iterator r;
	cout<<"no. of nodes : ";
	cin>>n;
	a = new int*[n];
	for(int i=0;i<n;i++)
		a[i]=new int[n];
	cout<<"\nEnter adjacency matrix =>\n";
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		cin>>a[i][j];
	cout<<"Starting node : ";
	cin>>s;
	cout<<"Goal node : ";
	cin>>g;
	ord.push_back(s);               // starting node

	states=new int[n];
	visited=new int[n];
    parent=new int[n];
    cost=new int[n];

	for(i=0;i<n;i++)
	{
		states[i]=i;
		parent[i]=-1;
		visited[i]=-1;
		cost[i]=9999;
	}

	cost[s]=0;

	for(r=ord.begin();r!=ord.end();++r)
	{
		for(i=*r,j=0;j<n;j++)
		if(a[i][j]!=0)
		{
			t.push_back(j);
			if(cost[j]>a[i][j]+cost[i])
			{
				cost[j]=a[i][j]+cost[i];
				parent[j]=i;
			}
		}
			ord.merge(t);                           // adding to closed list
			t.clear();
		visited[i]=1;
	}

	cout<<"open list =>\nstates\tvisited\tparent\tcost"<<endl;
	for(i=0;i<n;i++)
		cout<<states[i]<<"\t"<<visited[i]<<"\t"<<parent[i]<<"\t"<<cost[i]<<endl;

	t.push_back(g);                                                                     // goal node
	for(r=t.begin();parent[*r]!=-1 && r!=t.end();r++)
		t.push_back(parent[*r]);
	t.reverse();                                                                        // path is traced
	if(t.size()<2)
		cout<<g<<" can not be reached\n";
    else
    {
        cout<<"\nPath => ";
        for(r=t.begin();r!=t.end();r++)
       		cout<<*r<<"->";
		cout<<"\nCost = "<<cost[g]<<endl;
    }
	for(i=0;i<n;i++)
		delete[] a[i];
	delete *a;
	delete states;
	delete parent;
	delete cost;
	delete visited;
	return 0;
}
