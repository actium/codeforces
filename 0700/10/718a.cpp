#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void round(std::string& s)
{
    s.pop_back();

    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        if (*it == '.')
            continue;

        if (*it == '9') {
            *it = '0';
        } else {
            ++*it;
            break;
        }
    }

    while (s.back() == '0')
        s.pop_back();
}

void solve(std::string& s, unsigned t)
{
    const size_t x = s.find_first_of("56789", s.find('.'));
    if (x != std::string::npos) {
        s.resize(x+1);

        s.insert(s.begin(), '0');
        do {
            round(s);
        } while (--t != 0 && s.back() == '5');

        if (s[0] == '0')
            s.erase(s.begin());

        if (s.back() == '.')
            s.pop_back();
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned t;
    std::cin >> t;

    std::string s;
    std::cin >> s;

    solve(s, t);

    return 0;
}
