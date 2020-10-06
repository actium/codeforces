#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned c = 0, k[26] = {};
    for (size_t i = 0; i < n; i += 2) {
        const size_t a = s[i+0] - 'a';
        ++k[a];

        const size_t b = s[i+1] - 'A';
        if (k[b] > 0)
            --k[b];
        else
            ++c;
    }

    answer(c);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

