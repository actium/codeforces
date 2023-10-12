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

void solve(std::vector<unsigned>& p)
{
    unsigned k = 0;

    std::vector<unsigned> s;
    for (const unsigned x : p) {
        auto it = std::lower_bound(s.begin(), s.end(), x);
        if (it == s.end())
            it = s.insert(s.end(), x);
        else
            *it = x;

        k += (it - s.begin() == 1);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
