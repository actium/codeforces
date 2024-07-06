#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, size_t k)
{
    a.erase(std::unique(a.begin(), a.end()), a.end());

    std::vector<unsigned> c(1+k);
    ++c[a.front()];
    ++c[a.back()];
    for (size_t i = 1; i + 1 < a.size(); ++i)
        c[a[i]] += 1 + (a[i-1] == a[i+1]);

    unsigned x = 1;
    for (size_t i = 2; i <= k; ++i) {
        if (c[i] > c[x])
            x = i;
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
