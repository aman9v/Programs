// Example program
#include <iostream> 
#include <string>
#include <algorithm> // for sort
#include <vector>
#include <unordered_map> // a hashmap
#include <functional> // for greater or less

using namespace std;

void printAnagrams(unordered_map <string, vector <string> > &s){

    for(auto i = s.begin(); i != s.end(); i++){
        vector <string> temp_vec(i->second);
        for(unsigned int i = 0; i < temp_vec.size(); i++){
             cout << temp_vec[i] << " ";
            }
            cout << "\n";
        }
    
    }

void storeInMap(vector <string> &v){

    // unordered map is usually faster than map for simple key lookups as map allows only
    // lookups only in sorted order
    
    unordered_map < string, vector <string> > store;
    
    for (unsigned int i = 0; i < v.size(); i++){
        string temp_string(v[i]);
        sort(temp_string.begin(), temp_string.end());
        
        if(store.find(temp_string) == store.end()){
            vector <string> temp_vector;
            temp_vector.push_back(v[i]);
            store.insert(make_pair(temp_string, temp_vector));
            }
            
        else {
            vector <string> temp_vec = store[temp_string];
            temp_vec.push_back(v[i]);
            store[temp_string] = temp_vec;
            }    
        } 
    
    printAnagrams(store);
    
    }

int main()
{
    
    vector <string> v;
    v.push_back("cat");
    v.push_back("act");
    v.push_back("tac");
    v.push_back("god");
    v.push_back("odg");
    storeInMap(v);
    return 0;
 }
