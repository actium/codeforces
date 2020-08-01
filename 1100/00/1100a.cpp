#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<int>& a, size_t k)
{
    const size_t n = a.size();

    int d = 0;
    for (size_t b = 0; b < n; ++b) {
        int m = 0;
        for (size_t i = 0; i < n; ++i) {
            if (i % k != b % k)
                m += a[i];
        }

        d = std::max(d, abs(m));
    }

    answer(d);
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

