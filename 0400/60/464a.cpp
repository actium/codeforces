#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(std::string& s, size_t p)
{
    const size_t n = s.length();

    for (size_t x = n - 1; ~x != 0; --x) {
        do {
            ++s[x];
        } while (x > 0 && s[x] == s[x-1] || x > 1 && s[x] == s[x-2]);

        if (s[x] < 'a' + p) {
            while (++x < n) {
                s[x] = 'a';

                while (x > 0 && s[x] == s[x-1] || x > 1 && s[x] == s[x-2])
                    ++s[x];

                if (s[x] == 'a' + p)
                    return no_answer();
            }
            return answer(s);
        }
    }

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, p;
    std::cin >> n >> p;

    std::string s;
    std::cin >> s;

    solve(s, p);

    return 0;
}
