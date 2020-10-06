#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();

    unsigned x = 0;
    for (char b = 'a'; b <= 'z'; ++b) {
        unsigned c = 0, q = 0;
        for (size_t i = 0; i < n; ++i) {
            if (s[i] != b) {
                c = 0;
            } else if (++c == k) {
                ++q;
                c = 0;
            }
        }

        x = std::max(x, q);
    }

    answer(x);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}

