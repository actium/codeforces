#include <iostream>
#include <vector>

#include <climits>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<int>& f, const std::vector<int>& t, int k)
{
    const size_t n = f.size();

    int p = INT_MIN;
    for (size_t i = 0; i < n; ++i) {
        if (t[i] > k)
            p = std::max(p, f[i] - (t[i] - k));
        else
            p = std::max(p, f[i]);
    }

    answer(p);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> f(n), t(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> f[i] >> t[i];

    solve(f, t, k);

    return 0;
}

