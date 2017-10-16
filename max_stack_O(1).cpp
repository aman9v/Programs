#include <bits/stdc++.h>

using namespace std;

class maxStack{
    
    stack <int> origStack; // original stack.
    stack <int> auxStack; // keeps track of the max element. 
    
    public:
        void push(int x){
            origStack.push(x);
            if(auxStack.empty()) auxStack.push(x);
            else auxStack.push(max(x, auxStack.top())); 
            }
            
        int getMax(){
            if (!auxStack.empty()) return auxStack.top();
            return -1;
            }    
        
        void pop(){
            if (!origStack.empty()){
                origStack.pop();
                auxStack.pop();
                }
        }
        
        int top(){
            if(!origStack.empty()) return origStack.top();
            return -1;
            }
    
    
    };

int main() {
    maxStack s;
    s.push(19);
    s.push(4);
    s.push(7);
    s.push(14);
    s.push(2);
    cout << "Top of the stack is " << s.top() << endl ;
    cout << "Max element is " << s.getMax();
    return 0;
    }

// optimized in terms of space

// void push(int x){
//     greater<int> grt;
//     origStack.push(x);

//     if(auxStack.empty()) auxStack.push(x);

//     else{
//         if(x > auxStack.top()) auxStack.push(x);
//     }

// }

// void pop(){
//     if(auxStack.top() == origStack.top()) {
//         origStack.pop(); auxStack.pop();
//     }
//     else origStack.pop();
// }    

