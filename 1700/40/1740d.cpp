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
    constexpr const char* s[2] = { "TIDAK", "YA" };
    std::cout << s[v] << '\n';
}

void solve(size_t n, size_t m, const std::vector<unsigned>& a)
{
    std::set<unsigned> r;

    unsigned x = a.size();
    for (const unsigned q : a) {
        if (q != x) {
            r.insert(q);
            if (r.size() == n * m - 3)
                return answer(false);
        } else {
            while (r.erase(--x) != 0);
        }
    }

    answer(true);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(k);
    std::cin >> a;

    solve(n, m, a);
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
