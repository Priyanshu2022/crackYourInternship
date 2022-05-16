// we are given circular path of petrol pumps
// we need to start from any index of petrol pump and complete a circle
// arr given has petrol and distance to the next petrol pump
// we will take three variable start (will tell starting index)
// balance current extra petrol
// deficit is need (kami ) of petrol from start
// struct petrolPump
// {
//     int petrol;
//     int distance;
// };
int tour(petrolPump p[],int n)
    {
       int start=0;
       int balance=0;
       int deficit=0;
       for(int i=0;i<n;i++){
           balance+=p[i].petrol-p[i].distance;
           if(balance<0){
               deficit+=balance;
               start=i+1;
               balance=0;
           }
       }
       if(balance+deficit>=0) return start;
       else return -1;
    }