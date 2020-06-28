#include <bitset>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<size_t> dp(n + 1);
    {
        std::vector<unsigned> a(n);
        std::cin >> a;

        std::bitset<100000> seen;
        for (size_t i = n; i > 0; --i) {
            const unsigned ai = a[i-1] - 1;

            dp[i-1] = dp[i] + !seen.test(ai);
            seen.set(ai);
        }
    }

    while (m-- > 0) {
        size_t l;
        std::cin >> l;

        answer(dp[l-1]);
    }

    return 0;
}

