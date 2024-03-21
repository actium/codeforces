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
        std::cout << 1 + x.first << ' ' << 1 + x.second << '\n';
}

void solve(const std::vector<unsigned>& p, unsigned x)
{
    size_t lb = 0, ub = p.size();
    while (lb + 1 < ub) {
        const size_t mid = (lb + ub) / 2;
        (p[mid] > x ? ub : lb) = mid;
    }

    std::vector<std::pair<unsigned, unsigned>> s;
    if (p[lb] != x) {
        size_t r = 0;
        while (p[r] != x)
            ++r;

        s.emplace_back(lb, r);
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p, x);
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
