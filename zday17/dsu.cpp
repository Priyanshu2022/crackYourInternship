// disjoint set
// given two nodes tell if belong to same component or not
// findPar(), Union()
// we will maintain a rank (initially rank will be zero of all the nodes)
// if attaching two same rank guys , rank of the node to which we are attaching should increase
// when rank is diffent attach smaller to larger (no need to change the rank)
void makeSet(){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		rank[i]=0;
	}
}
int findPar(int node){
	if(node==parent[node]){
		return node;
	}
	return parent[node]=findPar(parent[node]);
}
void union(int u,int v){
	u=findPar(u);
	v=findPar(v);
	if(rank[u]<rank[v]){
		parent[u]=v;
	}
	else if(rank[v]<rank[u]){
		parent[v]=u;
	}
	else{
		parent[v]=u;
		rank[u]++;
	} 
}
