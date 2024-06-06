// #include <iostream>
// #include <vector>
// #include <algorithm>

// class Solution
// {
// public:
//     bool isNStraightHand(vector<int>& hand, int k) {
//     {
//         // sort(hand.begin(), hand.end());

//         // while (!hand.empty()) {
//         //     std::vector<int> demo;
//         //     demo.push_back(hand.front());
//         //     hand.erase(hand.begin());

//         //     for (int j = 0; j < groupSize - 1; ++j) {
//         //         auto it = std::find(hand.begin(), hand.end(), demo.back() + 1);
//         //         if (it != hand.end()) {
//         //             demo.push_back(*it);
//         //             hand.erase(it);
//         //         } else {
//         //             return false; // Sequence cannot be formed
//         //         }
//         //     }

//         // }

//         // return true;

        
//     }
// };


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
      if(hand.size()%k!=0)
       return false;
       priority_queue<int,vector<int>,greater<int>>pq(hand.begin(),hand.end());
       while(!pq.empty()){
           vector<int>remain;
           int cycle=k;
           while(cycle>1&&!pq.empty()){
               int temp=pq.top();
               pq.pop();
               while(pq.top()==temp&&!pq.empty()){
               remain.push_back(pq.top());
               pq.pop();
               }
               if(pq.top()-temp==1&&!pq.empty())
              cycle--;
               else
               return false;
           }
              pq.pop();
              for(auto it=remain.begin();it!=remain.end();it++){
               pq.push(*it);
                   }
                   if(pq.empty())
                   return true;
           }
        
       
       return true;
       
    }
};