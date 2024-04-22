// FULL NAME: SHALLON MARIA OMWONO
// REGISTRATION NUMBER: 230ADB062

// https://leetcode.com/problems/maximum-difference-between-increasing-elements/
// https://cplusplus.com/doc/tutorial/files/
//https://www.programiz.com/cpp-programming/vectors

// C++ libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;
// findMaxInc finds maximum increase in the sequence of integers provided
int findMaxInc(const vector<int>& nums) {
    //maxInc is initialized to the minimum integer
    int maxInc = numeric_limits<int>::min();
    int minNum = nums[0]; // minNum initialized to first element

// loop to iterate from second element
    for (size_t i = 1; i < nums.size(); ++i) {
        // increase calculation got by subtracting current number from least number so far
        int inc = nums[i] - minNum;

        // If the calculated inc is greater than the current maxInc, the maxInc is updated
        if (inc > maxInc) {
            maxInc = inc;
        }
        
        //if current number is less than the minimum number, min number is updated
        if (nums[i] < minNum) {
            minNum = nums[i];
        }
    }

    return maxInc; // maximum increase is returned
}

int main() {
    // files with inputs
    ifstream inputFile("ints_10.txt");


    // checks if the file fails to open and returns error
    if (!inputFile) {
        cout << "Input file  failed to open." << endl;
        return 1;
    }

    //vector to store integers
    vector<int> nums;
    int num;
    while (inputFile >> num) { // integers are read from first to last
        nums.push_back(num);
    }

    inputFile.close(); // input file closed

    //findMaxInc function is called
    int maxInc = findMaxInc(nums); 
    //outputs results
    cout << "The biggest increase is: " << maxInc << endl;

    return 0;
}
