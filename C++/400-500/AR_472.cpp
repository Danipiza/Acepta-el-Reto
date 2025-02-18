#include <iostream>
#include <vector>


using namespace std;

// Pre: true
bool senderismo(const vector<int>& v, int D) {
    bool ret = true;
    int a = 0, b = 0;
    while (ret && b < v.size()-1) {
        if (v[b + 1] > v[b]) b++;
        else {            
            if (v[b] == v[a]) b++;
            a++;
        }
        if ((v[b] - v[a]) > D) ret = false;
    }

    return ret;
}
// Pos: r = Sum k: 0 <= k < v.size(): v[k]

bool solve() {
    int n, D;
    cin >> D >> n;
	
    if (!cin)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];   
    

    if (senderismo(v, D)) cout << "APTA" << "\n";
    else cout << "NO APTA" << "\n";

    return true;
}

int main() {
    while (solve());

    return 0;
}