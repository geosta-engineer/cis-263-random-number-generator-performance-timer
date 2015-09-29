//
// Created by Jesse on 9/24/2015.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <ctime>

using namespace std;

class permutation {
public:

    vector<int> permu;



    void permutationOne(int min, int max) {
        int r = randomGen(max);
//        cout << r << endl;
//        cout << permu.size() << endl;
        if (permu.size() == max) {
//            cout << "Finished" << endl;
//            for(int x : permu ) {
//                cout << x << endl;
//            }
            permu.clear();
//            cout << permu.size() << endl;
            return;
        }
        else {
            if (permu.size() == 0) {
                permu.push_back(r);
                permutationOne(min, max);
            }
            else {
                bool flag = false;
                for (int i: permu) {
                    if (i == r) {
                        flag = true;
                    }
                }
                if(flag){
                    permutationOne(min, max);
                }
                else {
                    permu.push_back(r);
                    permutationOne(min, max);
                }

            }
        }
    }

//    void permutationTwo(int min, int max) {
//        int r = randomGen(max);//
//        if (permu.size() == max) {
//            cout << "Finished" << endl;
//            for(int x : permu ) {
//                cout << x << endl;
//            }
//            permu.clear();
//            used.clear();
//            return;
//        }
//        else {
//            if (permu.size() == 0) {
//                permu.push_back(r);
////                cout << used[r] << endl;
//                used[r] = true;
////                cout << used[r] << endl;
//                permutationOne(min, max);
//            }
//            else {
//                cout << used.at(r) << endl;
//                if(used[r])
//                    permutationOne(min, max);
//
//                else {
//                    permu.push_back(r);
//                    cout << used.at(r) << endl;
//                    used.at(r) = true;
//                    cout << used.at(r) << endl;
//                    permutationOne(min, max);
//                }
//
//            }
//        }
//    }

    void permutationTwo(int min, int max) {
        vector<bool> used (max, false);
//        for(int x : used ) {
//            cout << x << endl;
//        }
        int r = randomGen(max);
        if (permu.size() == max) {
            cout << "Finished" << endl;
            for(int x : permu ) {
                cout << x << endl;
            }
            permu.clear();
            used.clear();
            return;
        }
        else {
            if (permu.size() == 0) {
                permu.push_back(r);
//                cout << used[r] << endl;
                used[r] = true;
//                cout << used[r] << endl;
                permutationOne(min, max);
            }
            else {
                cout << used.at(r) << endl;
                if(used[r])
                    permutationOne(min, max);

                else {
                    permu.push_back(r);
                    cout << used.at(r) << endl;
                    used.at(r) = true;
                    cout << used.at(r) << endl;
                    permutationOne(min, max);
                }

            }
        }
    }


    vector<int> permutationThree(int n) {
        vector<int> array = {1, n};
    }

    void setSeed() {
        srand(time(0));
    }

    int randomGen(int n) {
//        std::mt19937 rn;
//        rn.seed(std::random_device()());
//        std::uniform_int_distribution<std::mt19937::result_type> uni(1,6);
//        return uni(rn);
        return 0 + (rand()%n);
//        random_device rd;
//        uniform_int_distribution<int> uni (0, n);
//        int r = uni(rd);
//        return r;
//        for (int k = 0; k < 16; k++) {
//            cout << "Random #" << (k+1) << " is " << uni(rd) << endl;
//        }
    }

    long fibonacci(unsigned n)
    {
        if (n < 2) return n;
        return fibonacci(n-1) + fibonacci(n-2);
    }

    int runTime () {
        chrono::time_point<chrono::system_clock> start, end;
        start = chrono::system_clock::now();

        end = chrono::system_clock::now();
        auto diff = end - start;
        auto elapse = chrono::duration_cast<chrono::seconds>(diff);
        cout << "Elapse time is " << elapse.count() << endl;
        return 0;
    }
};