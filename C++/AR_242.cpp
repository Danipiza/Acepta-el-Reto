#include <iostream>
#include <vector>

using namespace std;

// Pre: true
long long int erasmus(const vector<int>& v) {
    long long int ret = 0;
    
    if (v.size() != 1) {
        long long int sum = v[v.size() - 1];
        for (int i = v.size() - 2; i >= 0; --i) {
            ret = ret + v[i]*sum;
            sum = sum + v[i];
        }
    }
        


    return ret;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool resuelveCaso() {
    // read case
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];


    // write solution
    cout << erasmus(v) << endl;

    return true;
}

int main() {
    while (resuelveCaso());

    return 0;
}