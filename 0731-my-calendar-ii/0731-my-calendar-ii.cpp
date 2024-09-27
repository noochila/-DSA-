class MyCalendarTwo {
public:
    vector<pair<int, int>> s;
    vector<pair<int, int>> d;

    MyCalendarTwo() {}

    bool checkOverlap(int a1, int a2, int b1, int b2) {
        if (max(a1, a2) < min(b1, b2))
            return true;
        else
            return false;
    }

    bool book(int start, int end) {

        for (auto it : d) {
            if (checkOverlap(it.first, start, it.second, end))
                return false;
        }

        for (auto it : s) {
            if (checkOverlap(it.first, start, it.second, end)) {
                d.push_back({max(it.first, start), min(it.second, end)});
            }
        }

        s.push_back({start, end});
        return true;
    }
};
