// Example program
#include <bits/stdc++.h>
using namespace std;

int main()
{   
    vector <int> v = {0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0};
    int start = 0, end = v.size() - 1;
    vector < pair<int, int> > vp;
    for (int i = 0; i < v.size(); i++) vp.push_back(make_pair(v[i], i));
    int count_1 = 0;
    while(start < end){
    	while(vp[start].first != 1) start++;
    	while(vp[end].first != 0)end--;
    	if(start != end){
    	    pair <int, int> temp = vp[start]; 
    	    vp[start] = vp[end]; 
    	    vp[end] = temp;
    	    }
    	start++; 
    	end--;
    }
    // int first_one = 0;
    //for(int i = 0; i < vp.size(); ++i){if (vp[i].first == 1) {first_one = i + 1; break;}}
    //cout << first_one << endl;
    //cout << vp[first_one].first << " " << vp[first_one].second << endl;
    //int initial_cost = abs(vp[first_one].second-vp[0].second);
    int from_last = v.size() - 1;
    
    
    //first_one += 1;
    //while(first_one <= vp.size()){
    //	total_cost += abs(vp[first_one].second-vp[first_one-1].second) * total_items;
    //	total_items++;
    //	first_one++;
    //}
    
    while(from_last >= 0){
	if(v[from_last] == 1)count_1 += 1;
	from_last--;
	if(count_1 == 4) break;
    }
    
    
    
    int new_from = from_last + 1;
    int initial_cost = abs(new_from-0);
    cout << initial_cost << endl;
    int total_cost = initial_cost, total_items = 1;
    while(new_from <= v.size()){
    	if(v[new_from] == 1){
    	total_cost += abs(new_from-from_last) * total_items;
    	total_items++;
    	from_last = new_from;
    	}
	new_from++;    	
    }
   //for(pair <int, int> p : vp) cout << p.first << " " << p.second << endl;
   cout << total_cost;
	
}
