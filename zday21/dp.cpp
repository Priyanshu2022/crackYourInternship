// dp
// tabulation -> bottom up
// memoization -> top down

// fibonacci (dp)
// tc=n,sc=n
// tabulation -> bottom up (try go from the base case)
// space optimized
// prev and prev2
for(int i=2;i<=n;i++){
	cur=prev+prev2;
	prev2=prev;
	prev=cur;
}
ans =prev;

// try represent problem in terms of index
// do all possible stuffs on that index acc. to problem
// sum of all suffs -> count all ways
// min (of all stuffs) -> minimmum
