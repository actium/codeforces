#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();
    if (n < 2)
        return answer(0);

    unsigned k = 0;
    for (size_t i = 1; i < n; ++i) {
        if (s[i-1] == 'V' && s[i] == 'K')
            ++k, ++i;
    }

    if (s.find("VVV") < n || s.find("KKK") < n || s.find("KK") == 0 || s.rfind("VV") == n-2)
        ++k;

    answer(k);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

