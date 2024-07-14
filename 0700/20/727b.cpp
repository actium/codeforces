#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned long long k = 0, v = 0, t = 0;
    for (const char c : s) {
        if (isalpha(c)) {
            t += (k == 2 ? v : v * 100);
            k = 0;
            v = 0;
        }
        if (isdigit(c)) {
            v = v * 10 + (c - '0');
            ++k;
        }
        if (c == '.')
            k = 0;
    }

    std::string p;
    {
        unsigned q = t / 100;
        do {
            unsigned r = q % 1000;
            q /= 1000;
            if (q != 0) {
                p = '.' + p;
                for (unsigned i = 0; i < 3; ++i) {
                    p = char('0' + r % 10) + p;
                    r /= 10;
                }
            } else {
                p = std::to_string(r) + '.' + p;
            }
        } while (q != 0);

        if (t % 100 != 0) {
            p.push_back('0' + t % 100 / 10);
            p.push_back('0' + t % 10);
        } else {
            p.pop_back();
        }
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s + 'x');

    return 0;
}
