#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "Impossible" << '\n';
}

void solve(const std::string& t, size_t n)
{
    unsigned k = 0;
    {
        unsigned p = n + 1, q = 0;
        for (const char c : t) {
            if (c == ' ' && q == 0)
                continue;

            if (++q > n)
                return no_answer();

            if (c == '.' || c == '?' || c == '!') {
                p += (p != 0) + q;

                if (p > n) {
                    ++k;
                    p = q;
                }

                q = 0;
            }
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n >> std::ws;

    std::string t;
    std::getline(std::cin, t);

    solve(t, n);

    return 0;
}
