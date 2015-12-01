#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> indexOf(string s, string pattern) {
    vector<int> matchTable;
    vector<int> res;
    res.push_back(-1);
    
    if (pattern.size() == 0  || s.size() < pattern.size()) {
        return res;
    }

    // build the partical match table for pattern which contains: 
    // the length of the longest proper prefix in the (sub)pattern that
    // matches a proper suffix in the same (sub)pattern.
    for(int i = 0; i < pattern.size(); i++) {
        string subpattern = pattern.substr(0,i+1);
        int count = 0;
        string::iterator pbegin = subpattern.begin();
        string:: iterator pend = subpattern.end();
        while (pbegin != pend) {
           if (*pbegin == *pend) {
              count++;
           }
           else {
               break;
           }
           pbegin++;
           pend++;
        }
        matchTable.push_back(count);
    }
    
    // use the partial match table to find pattern in string
    int i = 0;
    while(i < s.size()) {
        if ((s.size()-i) < pattern.size()) {
            return res;
        }
        int j = i;
        int partial_match_length = 0;
        string::iterator pbegin = pattern.begin();
        while (pbegin != pattern.end() && *pbegin == s[j]) {
            pbegin++;
            j++;
            partial_match_length++;
        }
        if (partial_match_length == pattern.size()) {
            res.push_back(i);
        }
        if (partial_match_length == 0) {
            i++;
        }
        else {
            i += partial_match_length - matchTable[partial_match_length-1];
        }
    }
    return res;
}
    
int main() {
    // no match
    string s = "baacdfaabcdab";
    string pattern = "abababca";
    vector<int> res;
    res = indexOf(s,pattern);
    for (vector<int>::iterator it = res.begin(); it != res.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // there are two matches at places 0 and 3
    string s1 = "abaaba";
    string pattern1 = "aba";
    vector<int> res1;
    res1 = indexOf(s1,pattern1);
    for (vector<int>::iterator it = res1.begin(); it != res1.end(); ++it) {
        cout << *it << " ";
    }
    
    return 0;
}
    
    
    
    
    
    
    

