Implementing 3 stacks in one array.
Solution: Refer Stacks chapter of our book for explanation.
?#?include? <iostream>

#include <vector>
using namespace std;
const int STACK_SIZE = 20;
static vector<int> vec;
static int useful_len[3] = {STACK_SIZE, STACK_SIZE, STACK_SIZE};

bool push(int stackNumber, int data){
if(useful_len[stackNumber] == 0){
cout << "Stack " << stackNumber << " overflow " << endl;
return false;
}
useful_len[stackNumber] --;
vec.at(stackNumber * STACK_SIZE + useful_len[stackNumber]) = data;
return true;
}
bool pop(int stackNumber, int &data){
if(useful_len[stackNumber] == STACK_SIZE){
cout << "Stack " << stackNumber << " underflow " << endl;
return false;
}
data = vec.at(stackNumber * STACK_SIZE + useful_len[stackNumber]);
useful_len[stackNumber] ++;
return true;
}
bool top(int stackNumber, int &data){
if(useful_len[stackNumber] == STACK_SIZE){
cout << "Stack " << stackNumber << " is empty " << endl;
return false;
}
data = vec.at(stackNumber * STACK_SIZE + useful_len[stackNumber]);
return true;
}
int main(int argc, char* argv[]){
vec.reserve(3 * STACK_SIZE);
vec.resize(3 * STACK_SIZE);
cout << "Array size is: " << vec.capacity() << endl;
for(int i = 0; i < 25; i++){
push(1, i);
}
int value;
for(int i = 0; i < 25; i++){
top(1,value);
cout << "top value: " << value << endl;
pop(1, value);
cout << "value: " << value << endl;
}
return 0;
}