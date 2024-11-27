#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept> 
using namespace std;

vector<long long> fibonarr(int n) {
    if (n < 0) {
        throw invalid_argument("The number must be natural");
    }
    vector<long long> fib(n);
    fib[0] = 0;
    if (n > 1) {
        fib[1] = 1;
    }
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] < fib[i - 1]) {
            throw overflow_error("Fibonacci number overflow detected.");
        }
    }
    return fib;
}

void testfib() {
    assert((fibonarr(1) == vector<long long>{0}));
    assert((fibonarr(2) == vector<long long>{0,1}));
    assert((fibonarr(7) == vector<long long>{0, 1, 1, 2, 3, 5, 8}));
}

int main()
{
    try {
        int n;
        cout << "Enter the number:";
        cin >> n;
        vector<long long> res = fibonarr(n);
        cout << "First " << n << " numbers of fibonacci:" << endl;
        for (int i = 0;i < n;i++) {
            cout << res[i] << endl;
        }
        testfib();
        cout << "The tests were passed" << endl;
    }
    catch(const exception& err){
        cout << "Mistake!" <<err.what()<< endl;
    }
    return 0;
}
