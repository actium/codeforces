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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a, unsigned h)
{
    const size_t n = a.size();

    unsigned k = 0;
    for (unsigned v = 0; v <= h && k++ < n; ) {
        std::sort(a.begin(), a.begin() + k, std::greater<unsigned>());

        v = 0;
        for (size_t i = 0; i < k; i += 2)
            v += a[i];
    }

    answer(k - 1);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned h;
    std::cin >> h;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, h);

    return 0;
}

