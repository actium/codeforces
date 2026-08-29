#include <iostream>
#include <string>
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

void solve(const std::string& s, const std::string& t, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = s.size();

    std::vector<unsigned> d01(1+n), d10(1+n);
    for (size_t i = 0; i < n; ++i) {
        d01[i+1] = d01[i] + (s[i] == '0' && t[i] == '1');
        d10[i+1] = d10[i] + (s[i] == '1' && t[i] == '0');
    }

    for (const auto& q : r) {
        const auto k01 = d01[q.second] - d01[q.first-1], k10 = d10[q.second] - d10[q.first-1];
        answer(k01 + k10 + std::max(k01, k10) - std::min(k01, k10) <= q.second - q.first + 1);
    }
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::string s, t;
    std::cin >> s >> t;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(s, t, r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
