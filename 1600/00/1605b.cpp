#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    if (v.empty()) {
        std::cout << 0 << '\n';
    } else {
        std::cout << 1 << '\n';

        std::cout << v.size();
        for (const size_t x : v)
            std::cout << ' ' << 1+x;

        std::cout << '\n';
    }
}

void solve(std::string& s)
{
    const size_t n = s.length();

    const auto next = [&](size_t& i, size_t& j) {
        i = s.find('1', i);
        j = s.rfind('0', j);
        return i != std::string::npos && j != std::string::npos && i < j;
    };

    std::vector<size_t> p;
    for (size_t i = 0, j = n; next(i, j); ++i, --j) {
        p.push_back(i);
        p.push_back(j);
    }

    std::sort(p.begin(), p.end());

    answer(p);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
