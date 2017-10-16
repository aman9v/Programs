#include <bits/stdc++.h>

using namespace std;

class Box {
    private: 
        int height;
        int width;
        int depth;
        
    public:
        Box(int h=0, int w=0, int d=0): height(h), width(w), depth(d) {}
        
        int getHeight(){
            return height;
            }
            
        int getWidth(){
            return width;
            }   
        
        int getDepth(){
            return depth;
            }    
        
        bool canBeAbove(Box &box) {
            return this->height > box.height && this->width && this->depth > box.depth;
            }
    };

int createStackUtils(vector<Box> boxes, unsigned int bottomIndex, map <int, int> hashMap) {
    if (hashMap[bottomIndex] > 0 && bottomIndex < boxes.size()) return hashMap[bottomIndex];
    
    Box bottom = boxes[bottomIndex];
    int maxHeight = 0;
    
    for (unsigned int i = bottomIndex + 1; i < boxes.size(); ++i) {
        if (boxes[i].canBeAbove(bottom)) {
            int height = createStackUtils(boxes, i, hashMap);
            maxHeight = max(height, maxHeight);
            }
        }
        
    maxHeight += bottom.getHeight();
    hashMap.insert(make_pair(bottomIndex, maxHeight));
    return maxHeight;
    }

int createStack(vector<Box> boxes) {
    int maxHeight = 0;
    map <int, int> hashMap;
    for (unsigned int i = 0; i < boxes.size(); i++) {
        int height = createStackUtils(boxes, i, hashMap);
        maxHeight = max(maxHeight, height);
        }
    return maxHeight;    
    }

int main(){
    ios_base::sync_with_stdio(false);
    vector <Box> boxes;
    Box b1(2, 3, 7);
    boxes.push_back(b1);
    Box b2(9, 3, 1);
    boxes.push_back(b2);
    Box b3(7, 4, 1);
    boxes.push_back(b3);
    Box b4(2, 2, 6);
    boxes.push_back(b4);
    Box b5(3, 3, 4);
    boxes.push_back(b5);
    sort(boxes.begin(), boxes.end(), [](Box &b1, Box &b2) -> bool { // this is lambda function in c++ -> return type, [captures from enclosing scope]
        return b1.getHeight() > b2.getHeight();
        });
    int maxHeight = createStack(boxes);
    cout << "Maximum height with these boxes is: " << maxHeight;
    return 0;
    }