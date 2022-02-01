#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = n;
    for (size_t i = n / 2; i > 0; --i) {
        if (s.compare(i, i, s, 0, i) == 0) {
            k = n - i + 1;
            break;
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
