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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned s, std::vector<unsigned>& a)
{
    const size_t k = a.size();

    std::set<unsigned> c(a.cbegin(), a.cend());

    for (unsigned d = 0; d <= k; ++d) {
        if (s > d && c.count(s - d) == 0)
            return answer(d);

        if (s + d <= n && c.count(s + d) == 0)
            return answer(d);
    }

    answer(k + 1);  // unreachable
}

void test_case()
{
    unsigned n, s;
    std::cin >> n >> s;

    size_t k;
    std::cin >> k;

    std::vector<unsigned> a(k);
    std::cin >> a;

    solve(n, s, a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

