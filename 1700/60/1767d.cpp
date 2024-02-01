#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n, const std::string& s)
{
    unsigned f[2] = {}, lb = 1, ub = 1 << n;
    for (const char c : s) {
        if (c == '0') {
            ub -= 1 << f[1]++;
        } else {
            lb += 1 << f[0]++;
        }
    }

    std::vector<unsigned> v;
    for (unsigned i = lb; i <= ub; ++i)
        v.push_back(i);

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(n, s);

    return 0;
}
