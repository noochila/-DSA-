#include <set>
using namespace std;

class MyCalendar {
public:
    set<pair<int, int>> v;
    MyCalendar() {}

    bool book(int start, int end) {
     
        auto it = v.lower_bound({start, end});

       
        if (it != v.end() && it->first < end) 
            return false;

        if (it != v.begin()) {
            auto prevt = prev(it);
            if (prevt->second > start)
                return false;
        }

        v.insert({start, end});
        return true;
    }
};
