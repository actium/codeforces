#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned a = 0, z = 0, k = 0, q = 0;
    for (const char c : s) {
        if (c == 'G') {
            ++z;
            ++q;
        } else {
            a = z;
            z = 0;
        }

        k = std::max(k, a + 1 + z);
    }

    answer(std::min(k, q));
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
