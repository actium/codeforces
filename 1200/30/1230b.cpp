#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s, size_t k)
{
    if (k == 0)
        return answer(s);

    const size_t n = s.length();
    if (n == 1)
        return answer("0");

    if (s[0] > '1')
        s[0] = '1', --k;

    for (size_t i = 1; i < n && k > 0; ++i) {
        if (s[i] != '0')
            s[i] = '0', --k;
    }

    answer(s);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}

