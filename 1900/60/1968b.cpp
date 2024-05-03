#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    auto it = a.begin();
    for (auto jt = b.begin(); it != a.end() && jt != b.end(); ++jt) {
        if (*it == *jt)
            ++it;
    }

    answer(it - a.begin());
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);
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
