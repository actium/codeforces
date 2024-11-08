#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::string& s, size_t a, size_t b)
{
    const size_t n = s.length();

    std::vector<size_t> q;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '1')
            q.push_back(i);
    }
    q.push_back(n);

    std::vector<size_t> x;
    {
        size_t p = 0;
        for (const size_t c : q) {
            while (p + b <= c) {
                x.push_back(p + b - 1);
                p += b;
            }
            p = c + 1;
        }
    }

    x.erase(x.end() - a + 1, x.end());

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, a, b, k;
    std::cin >> n >> a >> b >> k;

    std::string s;
    std::cin >> s;

    solve(s, a, b);

    return 0;
}
