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

void solve(std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), [](unsigned x, unsigned y) { return x % 10 > y % 10; });

    unsigned q = 0;
    for (const unsigned x : a) {
        q += x / 10;

        const unsigned d = 10 - x % 10;
        if (d <= k && d != 10) {
            ++q;
            k -= d;
        }
    }

    answer(std::min<unsigned>(q + k / 10, n * 10));
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
