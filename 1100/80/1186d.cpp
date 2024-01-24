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

void answer(const std::vector<int>& v)
{
    for (const int x : v)
        std::cout << x << '\n';
}

void solve(const std::vector<double>& a)
{
    const size_t n = a.size();

    std::vector<int> b(a.begin(), a.end());

    long long sum = std::accumulate(b.begin(), b.end(), 0);
    for (size_t i = 0; i < n && sum != 0; ++i) {
        if (a[i] == b[i])
            continue;

        if (a[i] < 0 && sum > 0) {
            --b[i];
            --sum;
        }
        if (a[i] > 0 && sum < 0) {
            ++b[i];
            ++sum;
        }
    }

    answer(b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<double> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
