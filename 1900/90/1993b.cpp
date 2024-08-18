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

void solve(const std::vector<unsigned>& a)
{
    std::vector<unsigned> s[2];
    for (const unsigned x : a)
        s[x%2].push_back(x);

    if (s[0].empty() || s[1].empty())
        return answer(0);

    for (size_t i = 0; i < 2; ++i)
        std::sort(s[i].begin(), s[i].end());

    const auto check = [&](unsigned x) {
        for (const unsigned q : s[0]) {
            if (q > x)
                return false;

            x += q;

            if (x > s[0].back())
                break;
        }
        return true;
    };

    answer(s[0].size() + !check(s[1].back()));
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
