#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
};

void FCFS(vector<Process>& processes) {
    int n = processes.size();

    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = processes[0].arrivalTime;
    vector<int> waitingTime(n, 0);

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime)
            currentTime = processes[i].arrivalTime;

        waitingTime[i] = currentTime - processes[i].arrivalTime;
        currentTime += processes[i].burstTime;
    }

    double avgWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
    }
    avgWaitingTime /= n;

    cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t\t" << processes[i].arrivalTime << "\t\t"
             << processes[i].burstTime << "\t\t" << waitingTime[i] << "\n";
    }
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
}

int main() {

    vector<Process> processes = {
        {1, 0, 6},
        {2, 1, 4},
        {3, 2, 8},
        {4, 3, 5}
    };

    FCFS(processes);

    return 0;
}
