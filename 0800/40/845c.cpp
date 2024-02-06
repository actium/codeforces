#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& s)
{
    std::sort(s.begin(), s.end());

    unsigned t[2] = { ~0u, ~0u };
    for (const std::pair<unsigned, unsigned>& p : s) {
        if (t[0] == ~0u || p.first > t[0]) {
            t[0] = p.second;
            continue;
        }
        if (t[1] == ~0u || p.first > t[1]) {
            t[1] = p.second;
            continue;
        }
        return answer(false);
    }

    answer(true);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
