#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n)
{
    unsigned k = ~0u;

    const std::string x = std::to_string(n);
    for (unsigned i = 1; i * i <= n; ++i) {
        const std::string t = std::to_string(i * i);

        size_t j = 0;
        for (const char c : x) {
            if (c == t[j])
                ++j;
        }

        if (j == t.length())
            k = std::min<unsigned>(k, x.length() - t.length());
    }

    if (k != ~0u)
        return answer(k);

    no_answer();
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
