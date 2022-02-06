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

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& q)
{
    const size_t n = a.size();

    unsigned s = 0;
    for (size_t i = 0; i < n; ++i)
        s += a[i];

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    a.push_back(0);         // sentinel

    const unsigned p = *std::min_element(q.cbegin(), q.cend());
    for (size_t i = p; i < n; i += p) {
        s -= a[i++];
        s -= a[i++];
    }

    answer(s);
}

int main()
{
    size_t m;
    std::cin >> m;

    std::vector<unsigned> q(m);
    std::cin >> q;

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, q);

    return 0;
}
