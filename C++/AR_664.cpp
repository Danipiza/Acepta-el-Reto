#include <iostream>

#pragma GCC optimize ("O2")

static const int _ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;


int main() {
    int n, m, a;
    int ret, tmp;
    cin >> n;
    int i, j;
    while (n != 0) {
        ret = 800;
        for (i = 0; i < n; i++) {
            cin >> m;
            tmp = 0;
            for (j = 0; j < m; j++) {
                cin >> a;
                if (tmp < a) tmp = a;
            }
            if (ret > tmp) ret = tmp;
        }
        cout << ret << "\n";
        cin >> n;
    }
    return 0;
}