#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::vector<unsigned> count(T begin, T end)
{
    std::vector<unsigned> q;
    {
        unsigned f[26] = {}, k = 0;
        for (auto it = begin; it != end; ++it) {
            if (f[*it - 'a']++ == 0)
                ++k;

            q.push_back(k);
        }
    }
    return q;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const auto ps = count(s.begin(), s.end());
    const auto ss = count(s.rbegin(), s.rend());

    unsigned k = 0;
    for (size_t i = 1; i < n; ++i)
        k = std::max(k, ps[i-1] + ss[n-1-i]);

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
