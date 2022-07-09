
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int binarySearch(vector<int> v, int To_Find)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    // This below check covers all cases , so need to check
    // for mid=lo-(hi-lo)/2
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (v[mid] < To_Find) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if (v[lo] == To_Find) {
        cout << "Found"
             << " At Index " << lo << endl;
    }
    else if (v[hi] == To_Find) {
        cout << "Found"
             << " At Index " << hi << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
}

int main()
{
    const long long TIMES_TO_RUN{100};
    const long long NUM_VALS{500000};
    int To_Find{499999};

    vector<double> runtimes;


    for (int i = 0; i < TIMES_TO_RUN; ++i)
    {
        vector<int> dataset;

        for (int j = 0; j < NUM_VALS; ++j) {
            dataset.push_back(j);
        }
        std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());
        binarySearch(dataset, To_Find);
        std::chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());
        double runtime = std::chrono::duration_cast<std::chrono::duration<double>>(
                _end - _start).count();
        runtimes.push_back(runtime);
        dataset.clear();
    }

    double totRuntime{0};
    double avgRuntime{0};
    //Sum the runtimes
    for (double& n : runtimes)
        totRuntime += n;

    avgRuntime = totRuntime / runtimes.size();

    cout << "\n\n Total run time: " << totRuntime;
    cout << "\n\n Average run time: " << avgRuntime;

    return 0;
}