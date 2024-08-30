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

std::multiset<unsigned> prepare(const std::vector<unsigned>& v)
{
    std::multiset<unsigned> s;
    for (const unsigned x : v)
        s.insert(x >> __builtin_ctz(x));

    return s;
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    std::multiset<unsigned> s = prepare(a), t = prepare(b);
    while (!s.empty()) {
        unsigned x = *t.rbegin();
        t.erase(std::prev(t.end()));

        const auto it = s.find(x);
        if (it != s.end()) {
            s.erase(it);
            continue;
        }

        x >>= 1;
        if (x < *s.begin())
            return answer(false);

        t.insert(x);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
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
