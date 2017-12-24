// usage of volatile in C/C++
// flags: g++ volatile.cc -O2 -std=c++11
// it is vital when you compile with O2 optimize

#include <vector>
#include <thread>
#include <iostream>

using namespace std;

// int val = 0;
volatile int val = 0;

void A(){
    while(val == 0);
    cout << "val = " << val << endl;
}

void B(){
    val = 1;
}

int main(int argc, const char * argv[]) {
    vector<std::thread> threads;

    for(int i = 0; i < 2; ++i){
        threads.push_back(std::thread (i % 2 ? A : B));
    }

    for (auto & thread : threads)
        thread.join();

    return 0;
}