#include <iostream>
#include <string>
#include <vector>

void answer(size_t x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '1')
            p.push_back(i);
    }

    switch (p.size()) {
        case 1: return answer(0);
        case 2: return answer(1);
        default: return answer(p.back() - p.front());
    }
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
