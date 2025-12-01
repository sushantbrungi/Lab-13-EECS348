#include <iostream>
#include <vector>
using namespace std;

// Buggy version from the lab
bool faillecture_buggy(const vector<int>& attendance_records) {
    int absentcount = 0;
    for (int i = 1; i < (int)attendance_records.size(); ++i) {
        absentcount += (attendance_records[i] == 0);
    }
    return absentcount >= 3;
}

// Correct version (for checking expected behavior)
bool faillecture_correct(const vector<int>& attendance_records) {
    int absentcount = 0;
    for (int i = 0; i < (int)attendance_records.size(); ++i) {
        absentcount += (attendance_records[i] == 0);
    }
    return absentcount >= 3;
}

void run_test(const vector<int>& rec, const string& name) {
    bool expected = faillecture_correct(rec);
    bool actual   = faillecture_buggy(rec);

    cout << name << ":\n  attendance = [";
    for (size_t i = 0; i < rec.size(); ++i) {
        cout << rec[i];
        if (i + 1 < rec.size()) cout << ", ";
    }
    cout << "]\n";
    cout << "  expected (correct) = " << (expected ? "FAIL" : "PASS") << "\n";
    cout << "  actual  (buggy)   = " << (actual   ? "FAIL" : "PASS") << "\n\n";
}

int main() {
    // Q3: fault executed, no error state
    vector<int> q3 = {1,0,0,0,1,1,1,1,1,1};

    vector<int> q4 = {0,0,0,0,1,1,1,1,1,1};

  
    vector<int> q5 = {0,0,0,1,1,1,1,1,1,1};

    run_test(q3, "Q3: fault executed, no error state");
    run_test(q4, "Q4: error state, no failure");
    run_test(q5, "Q5: failure");

    return 0;
}
