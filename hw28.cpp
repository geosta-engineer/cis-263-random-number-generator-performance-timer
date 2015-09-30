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

//    void permutationOne(int min, int max) {
//        int r = randomGen(max);
//        cout << r << endl;
//        cout << permu.size() << endl;
//        if (permu.size() == max) {
//            cout << "Finished" << endl;
//            for(int x : permu ) {
//                cout << x << endl;
//            }
//            permu.clear();
//            cout << permu.size() << endl;
//            return;
//        }
//        else {
//            if (permu.size() == 0) {
//                permu.push_back(r);
//                permutationOne(min, max);
//            }
//            else {
//                bool flag = false;
//                for (int i: permu) {
//                    if (i == r) {
//                        flag = true;
//                    }
//                }
//                if(flag){
//                    permutationOne(min, max);
//                }
//                else {
//                    permu.push_back(r);
//                    permutationOne(min, max);
//                }
//
//            }
//        }
//    }
unsigned long randomGen(unsigned long n) {
        std::mt19937 rn;
        rn.seed(std::random_device()());
        std::uniform_int_distribution<unsigned long> uni(0,n-1);
        return uni(rn);
//    return 0 + (rand() % n);
//        random_device rd;
//        uniform_int_distribution<int> uni (0, n);
//        int r = uni(rd);
//        return r;
//        for (int k = 0; k < 16; k++) {
//            cout << "Random #" << (k+1) << " is " << uni(rd) << endl;
//        }
}

void permutationOne(int min, int max) {
    vector<int> permu;
    while (permu.size() < max) {
        int r = randomGen(max);
//            if (permu.size() == max) {
//                cout << "Finished" << endl;
//                for (int x : permu) {
//                    cout << x << endl;
//                }
//                permu.clear();
//                cout << permu.size() << endl;
//                return;
//            }
        if (permu.size() == 0) {
            permu.push_back(r);
        }
        else {
            bool flag = true;
            for (int i: permu) {
                if (i == r) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                permu.push_back(r);
            }
        }
    }
    cout << "Finished" << endl;
    for (int x : permu) {
        cout << x << endl;
    }
//        permu.clear();
//      cout << permu.size() << endl;
}


void permutationTwo(int min, unsigned long max) {
    vector<unsigned long> permu;
    vector<bool> used(max, false);
//    unsigned long r = randomGen(max);

    std::mt19937 rn;
    rn.seed(std::random_device()());
    std::uniform_int_distribution<unsigned long> uni(0,max-1);
    unsigned long r =  uni(rn);
    permu.push_back(r);
    used.at(r) = true;
    while (permu.size() < max) {
//        unsigned long r = randomGen(max);
        unsigned long r =  uni(rn);
//        if (permu.size() == 0) {
//            permu.push_back(r);
//            used[r] = true;
//        }
//        else {
            if (!used.at(r)) {
                permu.push_back(r);
                used[r] = true;
            }
//        }
    }
        cout << "Finished" << endl;
        for (int x : permu) {
            cout << x << endl;
        }
        permu.clear();
}

void permutationThree(int min, int n){         //fills vector
    //random_device rd; //source of randomness
//    srand(time(0));
    vector<int> vector1;
    for(int i=1; i<=n; i++){
        vector1.push_back(i);
    }

//    cout << "vector 1 contains:";           //prints vector
    for(int i=0; i<vector1.size(); i++){
//        cout << ' ' << vector1[i];
    }

//    cout << endl;

    for(int i=1; i<n; ++i){                 //creates random permutation
        //uniform_int_distribution<int> uni (0,i);

        swap(vector1[i], vector1[randomGen(i)]);
    }

//    cout << "vector 1 contains:";           //prints vector
    for(int i=0; i<vector1.size(); i++){
//        cout << ' ' << vector1[i];
    }


}

//int randInt(int n){
//    return (rand()%n);
//}



void setSeed() {
    srand(time(0));
}

//int runTime() {
//    chrono::time_point<chrono::system_clock> start, end;
//    start = chrono::system_clock::now();
//
//    end = chrono::system_clock::now();
//    auto diff = end - start;
//    auto elapse = chrono::duration_cast<chrono::seconds>(diff);
//    cout << "Elapse time is " << elapse.count() << endl;
//    return 0;
//}

int main() {

    srand(time(0));

    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    permutationTwo(0, 32769);
    end = chrono::system_clock::now();
    auto diff = end - start;
    auto elapse = chrono::duration_cast<chrono::nanoseconds>(diff);
    cout << "Elapse time is " << elapse.count() << endl;
    return 0;



//    cout << "Hello, World!" << endl;

//    test.permutationTwo(0,100);

//    int r = test.randomGen(10);
//    cout << r << endl;
//    for (int k = 0; k < 20; k++) {
//        cout << "Random #" << (k+1) << " is " << test.randomGen(100) << endl;
//    }

}