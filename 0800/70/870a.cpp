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

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    for (const unsigned x : a) {
        const auto it = std::lower_bound(b.cbegin(), b.cend(), x);
        if (it != b.cend() && *it == x)
            return answer(x);
    }

    const auto& [d1, d2] = std::minmax(a.front(), b.front());
    answer(d1 * 10 + d2);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(m);
    std::cin >> b;

    solve(a, b);

    return 0;
}

