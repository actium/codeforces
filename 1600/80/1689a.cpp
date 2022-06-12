#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& a, std::string& b, unsigned k)
{
    std::sort(a.begin(), a.end(), std::greater<char>());
    std::sort(b.begin(), b.end(), std::greater<char>());

    std::string c;
    for (unsigned x = 0, y = 0; !a.empty() && !b.empty(); ) {
        if (a.back() < b.back() && x < k || y == k) {
            c.push_back(a.back());
            a.pop_back();
            ++x;
            y = 0;
        } else {
            c.push_back(b.back());
            b.pop_back();
            ++y;
            x = 0;
        }
    }

    answer(c);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned k;
    std::cin >> k;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}