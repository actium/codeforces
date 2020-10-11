#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    for (size_t l = s.find_first_not_of('L'), r = l + 1; l < n; l = r++) {
        while (r < n && s[r] == '.')
            ++r;

        if (r < n) {
            if (s[l] == 'R') {
                k += (r - l - 1) % 2;
                ++r;
            } else if (s[r] == 'L') {
                ++r;
            } else {
                k += r - l;
            }
        } else if (s[l] == '.') {
            k += n - l;
        }
    }

    answer(k);
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

