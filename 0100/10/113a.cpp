#include <iostream>
#include <string>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

unsigned encode(const std::string& s)
{
    const size_t m = s.length();

    if (m >= 4 && s.compare(m - 4, 4, "lios") == 0)
        return 1 << 1 | 0;      // A, M

    if (m >= 6 && s.compare(m - 6, 6, "initis") == 0)
        return 1 << 3 | 0;      // V, M

    if (m >= 6 && s.compare(m - 6, 6, "inites") == 0)
        return 1 << 3 | 1;      // V, F

    if (m >= 3 && s.compare(m - 3, 3, "etr") == 0)
        return 1 << 2 | 0;      // N, M

    if (m >= 5 && s.compare(m - 5, 5, "liala") == 0)
        return 1 << 1 | 1;      // A, F

    if (m >= 4 && s.compare(m - 4, 4, "etra") == 0)
        return 1 << 2 | 1;      // N, F

    return 0;
}

void solve(const std::vector<std::string>& s)
{
    const size_t k = s.size();

    std::vector<unsigned> t(k);
    for (size_t i = 0; i < k; ++i)
        t[i] = encode(s[i]);

    if (k == 1)
        return answer(t[0] != 0);

    unsigned n = (t[0] / 2 == 2);
    for (size_t i = 1; i < k; ++i) {
        if (t[i] < t[i-1] || t[i] % 2 != t[i-1] % 2)
            return answer(false);

        n += (t[i] / 2 == 2);
    }

    answer(n == 1);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::vector<std::string> s;
    for (std::string b; std::cin >> b; s.push_back(b));

    solve(s);

    return 0;
}
