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

void solve(const std::vector<unsigned>& a)
{
    std::vector<unsigned> s;
    std::set<unsigned> z;
    for (unsigned x : a) {
        if (z.count(x) == 1)
            x = 0;

        if (!s.empty() && x < s.back()) {
            z.insert(s.cbegin(), s.cend());
            s.clear();
        }

        if (x != 0)
            s.push_back(x);
    }

    answer(z.size());
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
