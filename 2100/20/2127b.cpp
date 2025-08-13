#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t x)
{
    const size_t n = s.size(), p = s.rfind('#', x-1), q = s.find('#', x);

    if (p == std::string::npos && q == std::string::npos)
        return answer(1);

    if (p == std::string::npos)
        return answer(std::min(x, n-q+1));

    if (q == std::string::npos)
        return answer(std::min(p+2, n-x+1));

    answer(std::max(std::min(x, n-q+1), std::min(p+2, n-x+1)));
}

void test_case()
{
    size_t n, x;
    std::cin >> n >> x;

    std::string s;
    std::cin >> s;

    solve(s, x);
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
