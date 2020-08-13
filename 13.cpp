class CombinationIterator {
public:
    string c;
    vector<string> combination;
    int index=0;
    
    void helper(string seq,int start,int k){
        if(seq.size() == k){
            combination.push_back(seq);
            return;
            
        }
        for(int i=start;i<c.size();i++){
            seq.push_back(c[i]);
            helper(seq,i+1,k);
            seq.pop_back();
        }
        
    }
    
    CombinationIterator(string characters, int combinationLength) {
        c = characters;
        helper("",0,combinationLength);
    }
    
    string next() {
        string val = combination[index];
        index++;
        return val;
    }
    
    bool hasNext() {
        return index != combination.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
