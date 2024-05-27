#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a)
{
    std::sort(a.begin(), a.end());

    std::map<unsigned, unsigned> s;
    s.emplace(1, 0);
    for (const unsigned q : a) {
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            const auto m = std::lcm<unsigned long long>(it->first, q);
            if (m > a.back())
                return answer(a.size());

            s[m] = std::max(s[m], it->second + 1);
        }
    }

    unsigned x = 0;
    for (const auto& e : s) {
        if (!std::binary_search(a.begin(), a.end(), e.first))
            x = std::max(x, e.second);
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
