#include <iostream>
#include <string>

void no_answer()
{
    std::cout << "No" << '\n';
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s, size_t p)
{
    const size_t n = s.length();

    for (size_t x = 0; x = s.find('.', x), x != std::string::npos; ++x) {
        if (x >= p)
            s[x] = s[x-p] ^ 1;
        else if (x + p < n && s[x+p] != '.')
            s[x] = s[x+p] ^ 1;
        else
            s[x] = '0';
    }

    for (size_t i = p; i < n; ++i) {
        if (s[i] != s[i-p])
            return answer(s);
    }

    no_answer();
}

int main()
{
    size_t n, p;
    std::cin >> n >> p;

    std::string s;
    std::cin >> s;

    solve(s, p);

    return 0;
}

