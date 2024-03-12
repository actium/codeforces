#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    unsigned q = 0;

    const auto fix = [&](const std::string& p) {
        const size_t d = p.length() / 2;

        for (size_t x = s.find(p); x != std::string::npos; x = s.find(p, x+1)) {
            s[x + d] = 'x';
            ++q;
        }
    };

    fix("mapie");
    fix("map");
    fix("pie");

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
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
