#include<bits/stdc++.h>

using namespace std;

// equivalent to template<class T1, class T2>
// this is a functor and is nothing but a class or a struct that defines the operator() function. 
template<typename T1, typename T2>
struct less_second
{
    typedef pair<T1, T2> type;
    bool operator() (type const& a, type const&b) const {
        return a.second > b.second;
    }
};


bool compare(pair<int, int> &p1, pair<int, int> &p2){
    
    if(p1.second == p2.second) return p1.first < p2.first;
    
    return p1.second > p2.second;

    }

void printSorted(map<int, int> &s){
    vector < pair<int, int> > v;
    
    for(auto i = s.begin(); i != s.end(); ++i){
        v.push_back(make_pair(i->first, i->second));
        }
    
    sort(v.begin(), v.end(), less_second<int, int>()); // calls the operator for every two elements of vector v.
    // sort(v.begin(), v.end(), compare); // compare can be anything that implements the operator() function.

    for (auto i = v.begin(); i != v.end(); ++i){
        while(i->second--)cout << i->first << " ";
        }
    }

void storeInMap(vector<int> &v){
    
     map<int, int> store;
     
     for (unsigned int i = 0; i < v.size(); ++i){
            if(store.find(v[i]) == store.end()){
                store.insert(make_pair(v[i], 1));
                }
            else {
                store[v[i]] = store[v[i]] + 1;
                }    
         }
         
     cout << "key" << "\t" << "value" << endl;
     
     for (auto i = store.begin(); i != store.end(); ++i){
            cout << i->first << "\t " << i->second << endl;    
         }

     printSorted(store);

    }
    
int main(){
    
    vector<int> v = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
    storeInMap(v);
    return 0;
    
    }