#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(std::vector<int>& a, size_t k)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    for (size_t i = 0; i < n && k > 0; ++i) {
        if (a[i] < 0) {
            a[i] = -a[i];
            --k;
        }
    }

    if (k % 2 == 1) {
        const auto it = std::min_element(a.begin(), a.end());
        *it = -*it;
    }

    answer(std::accumulate(a.cbegin(), a.cend(), 0));
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
