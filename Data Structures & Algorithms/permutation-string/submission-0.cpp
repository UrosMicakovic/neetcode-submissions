class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        std::string sorted=s1;
        std::sort(sorted.begin(), sorted.end());

        for(int i=0; i <= (int)s2.size() - (int)s1.size(); i++){
            std::string comp = s2.substr(i, s1.size());
            std::sort (comp.begin(),comp.end());
            if (sorted==comp) return true;
        }
        return false;
    }
};
