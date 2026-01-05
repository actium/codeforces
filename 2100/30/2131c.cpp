#include <iostream>
#include <set>
#include <vector>

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

void solve(std::vector<unsigned>& s, std::vector<unsigned>& t, unsigned k)
{
    std::multiset<unsigned> p;
    for (const unsigned x : s)
        p.insert(x % k);

    for (const unsigned x : t) {
        auto it = p.find(x % k);
        if (it == p.end())
            it = p.find(k - x % k);

        if (it == p.end())
            return answer(false);

        p.erase(it);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> s(n), t(n);
    std::cin >> s >> t;

    solve(s, t, k);
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
