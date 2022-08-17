class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> s;
        for(int i=0;i<words.size();i++)
        {
            string temp="";
            for(int j=0;j<words[i].size();j++)
                temp+=v[words[i][j]-97];
            
            s.insert(temp);
        }
        return s.size();
    }
};