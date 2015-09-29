//
// Created by Jesse on 9/28/2015.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <c++/bits/stl_vector.h>
#include <c++/bits/random.h>
#include <c++/chrono>
#include "hw28.h"

using namespace std;


using

class permutation {

    void permutationOne(int n) {
        vector<int> array;

    }

    void permutationTwo(int n) {
        vector<int> array;
    }

    void permutationThree(int n) {
        vector<int> array = {1, n};
    }

    int randomGen() {
        random_device rd; /* source of randomness */
        /* uniform distribution of integers between 10-39 */
        uniform_int_distribution<int> uni (10, 40);

        for (int k = 0; k < 16; k++) {
            cout << "Random #" << (k+1) << " is " << uni(rd) << endl;
        }
    }

    long fibonacci(unsigned n)
    {
        if (n < 2) return n;
        return fibonacci(n-1) + fibonacci(n-2);
    }

    int runTime () {
        chrono::time_point<chrono::system_clock> start, end;
        start = chrono::system_clock::now();
        cout << fibonacci(42) << endl;
        end = chrono::system_clock::now();

        chrono::duration<double> elapse = end - start;
        cout << "Elapse time is " << elapse.count() << endl;
        return 0;
    }
};