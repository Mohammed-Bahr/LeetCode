#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
          map<char , pair<int , int>> mp;
          for (auto i: tasks) {
            mp[i].first++;
          }
          int time = 0;
          while (true) {
            int maxi = 0;
            char task = ' ';
            for (auto i: mp) {
              if (i.second.first > maxi && i.second.second <= time) {
                maxi = i.second.first;
                task = i.first;
              }
            }
            if (task == ' ') {
              break;
            }
            mp[task].first--;
            mp[task].second = time + n + 1;
            time++;
          }
          return time;
            
        }
    };

int main() {
    string s = "abc";
    string t = "ahbgdc";
    vector <int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    vector <char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    Solution S; 
    cout << S.leastInterval(tasks, n);

    return 0;
}
