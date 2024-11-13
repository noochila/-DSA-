// #include <queue>
// #include <unordered_set>
// using namespace std;

// // Custom hash function for pairs to use with unordered_set
// struct pair_hash {
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const {
//         auto hash1 = hash<T1>{}(p.first);
//         auto hash2 = hash<T2>{}(p.second);
//         return hash1 ^ (hash2 << 1); // Combine the two hash values
//     }
// };

// class Solution {
// public:
//     int racecar(int target) {

//         queue<pair<long long, pair<long long, int>>> q;
//         q.push({0, {1, 0}});

//         unordered_set<pair<long long, long long>, pair_hash> s; // Using unordered_set with custom hash

//         while (!q.empty()) {
//             auto temp = q.front();
//             q.pop();

//             long long pos = temp.first;
//             long long speed = temp.second.first;
//             int moves = temp.second.second;

//             if (pos == target) {
//                 return moves;
//             }

//             long long op1pos = pos + speed;
//             long long op1speed = speed * 2;

//             if (s.find({op1pos, op1speed}) == s.end()) {
//                 q.push({op1pos, {op1speed, moves + 1}});
//                 s.insert({op1pos, op1speed});
//             }

//             long long op2speed = (speed > 0) ? -1 : 1;
//             if (s.find({pos, op2speed}) == s.end()) {
//                 q.push({pos, {op2speed, moves + 1}});
//                 s.insert({pos, op2speed});
//             }
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int racecar(int target) {
        // 1. Initialize double ended queue as 0 moves, 0 position, +1 velocity
        queue<vector<int>> q;
        q.push({0, 0, 1});
        while (!q.empty()) {
            
            vector<int> item = q.front();
            q.pop();
            
            // (moves) moves, (pos) position, (vel) velocity)
            int moves = item[0];
            int pos = item[1];
            int vel = item[2];
            
            if (pos == target) return moves;
            
            // Avoid integer overflow - stop whenever we've passed twice the magnitude of target.
            if (abs(pos) > 2 * target) continue;
            
            // 2. Always consider moving the car in the direction it is already going
            q.push({moves + 1, pos + vel, 2 * vel});
            
            // 3. Only consider changing the direction of the car if one of the following conditions is true
            //    i.  The car is driving away from the target.
            //    ii. The car will pass the target in the next move.  
            if ((pos + vel > target && vel > 0) || (pos + vel < target && vel < 0)) {
                q.push({moves + 1, pos, (vel > 0) ? -1 : 1});
            }
        }
        
        return 0;
    }
};