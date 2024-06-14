#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

integer evaluate(const std::string& s)
{
    const size_t n = s.length();

    std::string t(n, '0');
    for (size_t i = 0; i < n; ++i)
        t[i] += '9' - s[i];

    return std::stoull(s) * std::stoull(t);
}

void solve(const std::string& l, const std::string& r)
{
    if (l.length() == r.length() && l[0] > '4')
        return answer(evaluate(l));

    if (r[0] > '4')
        return answer(evaluate('4' + std::string(r.length() - 1, '9')));

    answer(evaluate(r));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string l, r;
    std::cin >> l >> r;

    solve(l, r);

    return 0;
}
