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

void solve(const std::vector<unsigned>& a, unsigned m, unsigned k)
{
    const size_t n = a.size();

    unsigned d = std::count(a.cbegin(), a.cend(), 1), e = n - d;
    if (m >= d) {
        m -= d, d = 0;
    } else {
        d -= m, m = 0;
    }

    e -= std::min(e, m + k);

    answer(d + e);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned m, k;
    std::cin >> m >> k;


    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m, k);

    return 0;
}

