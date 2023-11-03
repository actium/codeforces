#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::string r(n, ' ');
    {
        unsigned s[2] = {};
        for (size_t i = 0; i < n; ++i) {
            if (s[0] + a[i] <= s[1] + 500) {
                r[i] = 'A';
                s[0] += a[i];
            } else {
                r[i] = 'G';
                s[1] += 1000 - a[i];
            }
        }
    }

    answer(r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    for (size_t i = 0; i < n; ++i) {
        unsigned g;
        std::cin >> a[i] >> g;
    }

    solve(a);

    return 0;
}
