#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int time, profit, deadline;
};

bool byDeadline(const Job& a, const Job& b) {
    return a.deadline < b.deadline;
}

int main() {
  vector<Job> jobs = {
    {2, 50, 4},
    {1, 40, 1},
    {3, 60, 5},
    {2, 20, 3}
};

// vector<Job> jobs = {
//   {1, 10, 2},
//   {1, 15, 3},
//   {1, 20, 5}
// };
// int time;  Time needed to complete the job
// int profit;  Profit earned if the job is completed on time
// int deadline;  Latest time by which the job must be finished


    sort(jobs.begin(), jobs.end(), byDeadline);

    int currentTime = 0, totalProfit = 0;
    vector<Job> scheduled;

    for (const auto& job : jobs) {
        if (currentTime + job.time <= job.deadline) {
            currentTime += job.time;
            totalProfit += job.profit;
            scheduled.push_back(job);
        }
    }

    cout << "Total profit earned: " << totalProfit << "\n";
    cout << "Scheduled jobs:\n";

    for (const auto& job : scheduled) {
        cout << "Processing time: " << job.time
             << ", Profit: " << job.profit
             << ", Deadline: " << job.deadline << "\n";
    }

    return 0;
}
