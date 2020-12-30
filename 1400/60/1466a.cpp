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

void solve(const std::vector<unsigned>& x)
{
    const size_t n = x.size();

    std::set<unsigned> s;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j)
            s.insert(x[i] - x[j]);
    }

    answer(s.size());
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

