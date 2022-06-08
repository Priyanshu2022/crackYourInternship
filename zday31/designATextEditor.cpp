// design a text editor
string left="";
    string right="";
    TextEditor() {
        
    }
    
    void addText(string text) {
        left+=text;
    }
    
    int deleteText(int k) {
        int deleted=0;
        while(k>0 && left.size()!=0){
            left.pop_back();
            k--;
            deleted++;
        }
        return deleted;
    }
    
    string cursorLeft(int k) {
        while(k>0 && left.size()!=0){
            right.push_back(left.back());
            left.pop_back();
            k--;
        }
        if(left.length()<10) return left;
        else return left.substr(left.size()-10);
    }
    
    string cursorRight(int k) {
        while(k>0 && right.size()!=0){
            left.push_back(right.back());
            right.pop_back();
            k--;
        }
        if(left.length()<10) return left;
        else return left.substr(left.size()-10);
    }