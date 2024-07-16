#include <string>
#include <queue>

class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        int size = senate.size();
        std::queue<char> q;

        for(int i = 0; i < size; i++) {
            q.push(senate[i]);
        }

        int bannedDire = 0;
        int bannedRadiant = 0;

        int dires = 0;
        int radiants = 0;

        do {
            std::queue<char> tmp;
            dires = 0;
            radiants = 0;
            
            while(!q.empty()) {
                char c = q.front();
                q.pop();

                if(c == 'R') {
                    if(bannedRadiant > 0) {
                        bannedRadiant--;
                    } else {
                        bannedDire++;
                        radiants++;
                        tmp.push(c);
                    }
                } else {    // c == 'D'
                    if(bannedDire > 0) {
                        bannedDire--;
                    } else {
                        bannedRadiant++;
                        dires++;
                        tmp.push(c);
                    }
                }
            }
            q = tmp;

        } while(dires != 0 && radiants != 0);

        return radiants > 0 ? "Radiant" : "Dire";
    }
};