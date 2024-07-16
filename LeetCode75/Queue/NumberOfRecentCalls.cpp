#include <queue>

class RecentCounter {
    std::queue<int> q;
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        q.push(t);

        int min = t - 3000;

        while(true) {
            if(q.front() < min) {
                q.pop();
            } else{
                break;
            }
        }

        return q.size();
    }
};