// is there a subset which add up to target
f(ind ,target){
	if(target==0) return true;
	if(ind==0) return (a[0]==target);
	bool notTake=f(ind-1,target);
	bool take=false;
	if(a[ind]<=target) take=f(ind-1,target-a[i]);
	return take||notTake;
}