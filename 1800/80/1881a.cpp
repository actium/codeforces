#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::string& x, const std::string& s)
{
    for (unsigned k = 0; k < 6; ++k) {
        if (x.find(s) != std::string::npos)
            return answer(k);

        x += x;
    }

    no_answer();
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string x, s;
    std::cin >> x >> s;

    solve(x, s);
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
