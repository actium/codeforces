#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::string& s, unsigned a, unsigned b)
{
    s.push_back('*');

    unsigned c = 0, k = 0;
    for (const char x : s) {
        if (x == '.') {
            ++c;
        } else {
            if (a < b)
                std::swap(a, b);

            k += std::min(a, (c + 1) / 2), a -= std::min(a, (c + 1) / 2);
            k += std::min(b, c / 2), b -= std::min(b, c / 2);
            c = 0;
        }
    }

    answer(k);
}

int main()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    std::string s;
    std::cin >> s;

    solve(s, a, b);

    return 0;
}

