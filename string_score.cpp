#include<bits/stdc++.h>

using namespace std;

int calcPre(string t, string p) {
    stack<char> charStack;
    for (auto it = p.end(); it != p.begin(); it--) {
        charStack.push(*it);
        }
    int i = 0;
    int score = 0;
    while (i < t.size() && !charStack.empty())  {
        if (t[i] == charStack.top()) {
            
            i++;
            charStack.pop();
            score++;
            } else {
            	charStack.pop();
            }
        }
        return score;
    }

int calcPost(string t, string p) {
    stack<char> charStack;
    for (char &c : p) {
        charStack.push(c);
        }
    int i = t.size()-1 ;
    int score = 0;
    while (i >= 0 && !charStack.empty())  {
        if (t[i] == charStack.top()) {
            
            i--;
            charStack.pop();
            score++;
            } else {
            	charStack.pop();
            }
        }
        return score;
    }

int main() {
    string text = "nothing";
    string pre_text = "bruno";
    string post_text = "ingenious";
    int preScore = calcPre(text, pre_text);
    int postScore = calcPost(text, post_text);
    cout << postScore + preScore;
    return 0;
    }