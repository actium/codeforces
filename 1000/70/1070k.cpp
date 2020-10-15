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

void no_answer()
{
    std::cout << "No" << '\n';
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << "Yes" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    const unsigned t = std::accumulate(a.cbegin(), a.cend(), 0);
    if (t % k != 0)
        return no_answer();

    const unsigned p = t / k;

    std::vector<unsigned> s(k);
    for (size_t i = 0, j = 0; i < k; ++i) {
        unsigned d = 0;
        while (d < p) {
            d += a[j++];
            ++s[i];
        }

        if (d > p)
            return no_answer();
    }

    answer(s);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

