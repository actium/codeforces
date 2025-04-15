#include <iostream>
#include <string>
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

void solve(const std::vector<unsigned>& p, std::string& s, const std::vector<unsigned>& r)
{
    const size_t n = p.size();

    std::vector<int> d(n);
    for (size_t i = 0; i < n; ++i) {
        if (p[i] < i + 1) {
            ++d[p[i]-1];
            --d[i];
        }
        if (p[i] > i + 1) {
            ++d[i];
            --d[p[i]-1];
        }
    }

    for (size_t i = 1; i < n; ++i)
        d[i] += d[i-1];

    unsigned k = 0;
    for (size_t i = 1; i < n; ++i)
        k += (s[i-1] == 'L' && s[i] == 'R' && d[i-1] != 0);

    for (const unsigned x : r) {
        if (s[x-1] == 'L') {
            k -= (s[x] == 'R' && d[x-1] != 0);
            s[x-1] = 'R';
            k += (x > 1 && s[x-2] == 'L' && d[x-2] != 0);
        } else {
            k -= (x > 1 && s[x-2] == 'L' && d[x-2] != 0);
            s[x-1] = 'L';
            k += (s[x] == 'R' && d[x-1] != 0);
        }

        answer(k == 0);
    }
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> p(n);
    std::cin >> p;

    std::string s;
    std::cin >> s;

    std::vector<unsigned> r(q);
    std::cin >> r;

    solve(p, s, r);
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
