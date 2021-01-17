#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t l = 0, r = 0, d = 0;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] < a[l]) {
            l = r = i;
            d = 0;
        }

        if (a[i] == a[l] && i != r) {
            d = std::max(d, i - r - 1);
            r = i;
        }
    }
    d = std::max<int>(d, n - r + l - 1);

    answer(1ull * n * a[l] + d);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

