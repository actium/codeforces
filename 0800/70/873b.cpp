#include <iostream>
#include <map>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    {
        std::map<int, int> h;
        h[0] = -1;

        int b = 0;
        for (size_t i = 0; i < n; ++i) {
            b += (s[i] == '0' ? 1 : -1);

            const auto s = h.emplace(b, i);
            if (!s.second)
                k = std::max<unsigned>(k, i - s.first->second);
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
