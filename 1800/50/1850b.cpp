#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << 1 + x << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& p)
{
    const size_t n = p.size();

    size_t x = 0;
    for (size_t i = 1; i < n; ++i) {
        if (p[i].first > 10)
            continue;

        if (p[x].first > 10 || p[i].second > p[x].second)
            x = i;
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> p(n);
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
