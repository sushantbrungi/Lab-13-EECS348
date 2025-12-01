#include <iostream>
#include <vector>
using namespace std;

/*
EECS 348 - Lab 13: Debugging and Testing
Student: [YOUR NAME]

Q1. Is there a fault in the program? If so, locate it and explain.
Yes there is a fault in the program. It should be i=0 and not i=1. This is because the attendance_records[0] is never counted and if the student was absent for lec 0, then nothing wouldve happened.

Q2. Define a test case that does not execute the fault.
It is impossible to provide a test case that does not execute the fault above, because the bad and faulty loop header is always looked at whenever the function is called.

Q3. Define a test case that executes the fault but does not result in an error state.
A test case that will execute the fault but does not produce an error would be {1, 0, 0, 0, 1, 1, 1, 1, 1, 1}. In this scenarioo, the fault will execute because the loop still starts at the index 1, but no error state occurs because the first value is 1. This basically means that skipping it does not change the number of absences.

Q4. Define a test case that results in an error state but not a failure.
A test case that produces an error but not a failure would be {0, 0, 0, 0, 1, 1, 1, 1, 1, 1}. This input creates an incorrect count because the one absence at index 0 is not taken note of, but it does not lead to a failure since both the right logic and the faulty logic still make sure that the student has enough absences to fail the course.

Q5. Define a test case that results in failure.
A test case that will produce failure would be this {0,0,0,1,1,1,1,1,1,1}, but the buggy code returns pass because it ignores the absence at index 0 and only counts two absences instead of three, leading to a failure.
*/

// Buggy version 
bool faillecture_buggy(const vector<int>& attendance_records) {
    int absentcount = 0;
    // This is the bug: starts from i = 1 instead of 0
    for (int i = 1; i < (int)attendance_records.size(); ++i) {
        absentcount += (attendance_records[i] == 0);
    }
    return absentcount >= 3; 
}

// Correct version 
bool faillecture_correct(const vector<int>& attendance_records) {
    int absentcount = 0;
    for (int i = 0; i < (int)attendance_records.size(); ++i) {
        absentcount += (attendance_records[i] == 0);
    }
    return absentcount >= 3; 
}

void print_vector(const vector<int>& v) {
    cout << "{";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "}";
}

void run_test(const vector<int>& rec, const string& label) {
    bool expected = faillecture_correct(rec);
    bool actual   = faillecture_buggy(rec);

    cout << label << "\n";
    cout << "  attendance record = ";
    print_vector(rec);
    cout << "\n";
    cout << "  expected result (correct logic): "
         << (expected ? "FAIL" : "PASS") << "\n";
    cout << "  actual result (buggy logic):    "
         << (actual ? "FAIL" : "PASS") << "\n\n";
}

int main() {
    // Question 3: fauly
    vector<int> q3 = {1, 0, 0, 0, 1, 1, 1, 1, 1, 1};

    // Question 4: error 
    vector<int> q4 = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1};

    // Question 5: failure 
    vector<int> q5 = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};

    run_test(q3, "Test case for Q3 (fault executed, no error state):");
    run_test(q4, "Test case for Q4 (error state, no failure):");
    run_test(q5, "Test case for Q5 (failure):");

    return 0;
}
