#include <iostream>
#include <string>

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    int v = -1;
    for (size_t i = 1; i < n; ++i) {
        if (i > 1 && s[0] == '0' || i > 7)
            continue;

        for (size_t j = 1; i + j < n; ++j) {
            if (j > 1 && s[i] == '0' || j > 7)
                continue;

            const size_t k = n - (i + j);
            if (k > 1 && s[i+j] == '0' || k > 7)
                continue;

            const unsigned x1 = std::stoi(s.substr(0, i));
            const unsigned x2 = std::stoi(s.substr(i, j));
            const unsigned x3 = std::stoi(s.substr(i + j));

            if (x1 <= 1000000 && x2 <= 1000000 && x3 <= 1000000)
                v = std::max<int>(v, x1 + x2 + x3);
        }
    }

    answer(v);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
