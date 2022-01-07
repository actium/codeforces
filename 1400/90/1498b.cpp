#include <iostream>
#include <set>
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

void solve(const std::vector<unsigned>& w, unsigned b)
{
    unsigned k = 0, d = 0;
    for (std::multiset<unsigned> s(w.cbegin(), w.cend()); !s.empty(); ) {
        auto it = s.upper_bound(d);
        if (it-- == s.begin()) {
            ++k;
            d = b;
        } else {
            d -= *it;
            s.erase(it);
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned b;
    std::cin >> b;

    std::vector<unsigned> w(n);
    std::cin >> w;

    solve(w, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
