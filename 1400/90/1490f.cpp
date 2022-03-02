#include <iostream>
#include <map>
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

void solve(const std::vector<unsigned>& a)
{
    std::map<unsigned, unsigned> f;
    for (const unsigned x : a)
        ++f[x];

    std::set<unsigned> s;
    for (const std::pair<unsigned, unsigned>& e : f)
        s.insert(e.second);

    unsigned k = a.size();
    for (const unsigned x : s) {
        unsigned q = 0;
        for (const std::pair<unsigned, unsigned>& e : f)
            q += (e.second >= x ? e.second - x : e.second);

        k = std::min(k, q);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
