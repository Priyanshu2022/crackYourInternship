int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        if(k==0) num%10==0?1:0;
        for(int i=1;i*k<=num && i<=10;i++){
            if((num-i*k)%10==0) return i;
        }
        return -1;
    }