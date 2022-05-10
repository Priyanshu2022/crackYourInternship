// we have to tell minimum substring where all characters of second string present
// we will first store the char of 2nd string in map with their frequency
// matchedCount variable shows how many matched char are present in current substring (window)
// low is starting point of substring we are checking and high ending point
// if same length substring present then we have to return the one with minimum index (therefore we have minStart)
// idea is we will move till we will move high untill we will get a substring with all char of 2nd string
// then we will start decreasing the char by moving low , and whenever we find out we have removed the important char
// we will start increasing high again and start acquiring again
string minWindow(string s, string t) {
        unordered_map<char,int> letters;
        for(int i=0;i<t.length();i++) letters[t[i]]++;
        int matchedCount=0;
        int low=0;
        int minLength=INT_MAX;
        int minStart=0;
        for(int high=0;high<s.length();high++){
            if(letters[s[high]]>0) matchedCount++;// if we get the char we want , we will increase matchedCount
            letters[s[high]]--;//we have acquired that element 
            if(matchedCount==t.length()){// if we got all element 
                while(low<high && letters[s[low]]<0) letters[s[low]]++,low++;// we will start removing from start
                if(minLength>high-low+1){ // if minLength is greater than we will update it with misStart
                    minLength=high-low+1;
                    minStart=low;
                }
                letters[s[low]]++;// we will increase it's count , means we are leaving this one , we need this again
                low++;
                matchedCount--;
            }
        }
        return minLength==INT_MAX?"":s.substr(minStart,minLength);
    }