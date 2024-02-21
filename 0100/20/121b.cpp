#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, size_t k)
{
    const size_t n = s.length();

    for (size_t i = 1; i < n && k > 0; ++i) {
        if (s[i-1] != '4' || s[i] != '7')
            continue;

        if (i % 2 == 1) {
            s[i] = '4';
            --k;
            continue;
        }
        if (s[i-2] != '4') {
            s[i-1] = '7';
            --k;
            continue;
        }

        s[i-1] = "47"[k % 2];
        break;
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}
