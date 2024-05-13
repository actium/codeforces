#include <iomanip>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(double x)
{
    std::cout << std::fixed << std::setprecision(10) << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& e, unsigned u)
{
    const size_t n = e.size();

    unsigned p = 0, q = 1;
    for (size_t j = 1, k = 1; j + 1 < n; ++j) {
        while (k + 1 < n && e[k+1] <= e[j-1] + u)
            ++k;

        if (k > j && 1ull * (e[k] - e[j]) * q > 1ull * (e[k] - e[j-1]) * p) {
            p = e[k] - e[j];
            q = e[k] - e[j-1];
        }
    }

    p != 0 ? answer(double(p) / q) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned u;
    std::cin >> u;

    std::vector<unsigned> e(n);
    std::cin >> e;

    solve(e, u);

    return 0;
}
