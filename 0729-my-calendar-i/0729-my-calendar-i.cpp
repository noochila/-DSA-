class MyCalendar {
public:
    vector<pair<int, int>> v;
    MyCalendar() {}

    bool book(int start, int end) {

        if (v.size() == 0) {
            v.push_back({start, end});
            return true;
        }

        for (auto it : v) {

            if (start < it.second  && end>it.first)
                return false;
        }

        v.push_back({start, end});
        return true;
    }
};
