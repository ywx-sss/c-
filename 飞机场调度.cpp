#include<bits/stdc++.h>
using namespace std;

int way, ont, outt;
int t = -1;
queue<int> qon, qout;
vector<int> wayend;
vector<int> onwait;
vector<int> outwait;
vector<int> occupied;

int main() {
    cin >> way >> ont >> outt;
    wayend.resize(way + 1, 0);
    occupied.resize(way + 1, 0);

    int numon, numout;
    bool isclosed = false;
    while (true) {
        t++;
        printf("Current Time: %4d\n", t);

        vector<int> freeway;
        for (int i = 1; i <= way; i++) {
            if (wayend[i] == t) {
                freeway.push_back(i);
                if(t!=0)
                printf("runway %02d is free\n", i); 
            }
        }

        if (!isclosed) {
            cin >> numon >> numout;
            if (numon < 0 && numout < 0) {
                isclosed = true;
            } else {
                for (int i = 0; i < numon; i++) {
                    qon.push(5001 + onwait.size());
                    onwait.push_back(t);
                }
                for (int i = 0; i < numout; i++) {
                    qout.push(1 + outwait.size());
                    outwait.push_back(t);
                }
            }
        }

        for (int runway : freeway) {
            if (!qon.empty()) {
                int plane = qon.front();
                qon.pop();
                printf("airplane %04d is ready to land on runway %02d\n", plane, runway);
                wayend[runway] = t + ont;
                occupied[runway] += ont;
                onwait[plane - 5001] = t - onwait[plane - 5001];
            } else if (!qout.empty()) {
                int plane = qout.front();
                qout.pop();
                printf("airplane %04d is ready to takeoff on runway %02d\n", plane, runway);
                wayend[runway] = t + outt;
                occupied[runway] += outt;
                outwait[plane - 1] = t - outwait[plane - 1];
            }
        }

        if (isclosed && qon.empty() && qout.empty()) {
            bool allRunwaysFree = true;
            for (int i = 1; i <= way; i++) {
                if (wayend[i] > t) {
                    allRunwaysFree = false;
                    break;
                }
            }
            if (allRunwaysFree) {
                break;
            }
        }
    }

    double totalonwait = 0;
    for (int wait : onwait) {
        totalonwait += wait;
    }
    double avgonwait = totalonwait / onwait.size();

    double totaloutwait = 0;
    for (int wait : outwait) {
        totaloutwait += wait;
    }
    double avgoutwait = totaloutwait / outwait.size();

    double totaloccupied = 0;
    for (int time : occupied) {
        totaloccupied += time;
    }
    double avgoccupied = totaloccupied * 100 / (way * t);

    printf("simulation finished\n");
    printf("simulation time: %4d\n", t);
    printf("average waiting time of landing: %4.1f\n", avgonwait);
    printf("average waiting time of takeoff: %4.1f\n", avgoutwait);
    for (int i = 1; i <= way; i++) {
        printf("runway %02d busy time: %4d\n", i, occupied[i]);
    }
    printf("runway average busy time percentage: %4.1f%%\n", avgoccupied);
    return 0;
}
