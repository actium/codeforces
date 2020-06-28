#include <algorithm>
#include <iostream>
#include <vector>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a, size_t d, unsigned sum)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    size_t count = 0;
    for (size_t i = 0, median = a[n / 2]; i < n; ++i)
        count += abs(median - a[i]) / d;

    answer(count);
}

int main()
{
    size_t n, m, d;
    std::cin >> n >> m >> d;

    const size_t k = n * m;
    std::vector<unsigned> a(k);

    bool solvable = true;
    unsigned sum = 0;
    for (size_t i = 0; i < k; ++i) {
        std::cin >> a[i];

        if (a[i] % d != a[0] % d)
            solvable = false;

        sum += a[i];
    }

    if (!solvable) {
        answer(-1);
    } else {
        solve(a, d, sum);
    }

    return 0;
}

