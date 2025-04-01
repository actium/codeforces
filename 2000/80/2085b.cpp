#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> x;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 0)
            x.push_back(i);
    }

    std::vector<std::pair<unsigned, unsigned>> p;
    {
        size_t k = n;
        if (!x.empty() && x.back() > 1) {
            p.emplace_back(3, n);
            k = 3;
        }
        if (!x.empty() && x.front() < 2) {
            p.emplace_back(1, 2);
            k -= 1;
        }
        p.emplace_back(1, k);
    }
    answer(p);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
