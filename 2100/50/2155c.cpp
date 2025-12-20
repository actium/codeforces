#include <iostream>
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

unsigned check(const std::string& s, const std::vector<unsigned>& a)
{
    const size_t n = s.length();

    std::vector<unsigned> v(n, 1);
    for (size_t i = 0, k = 0; i < n; ++i) {
        v[i] += k;
        k += (s[i] == 'L');
    }
    for (size_t i = n, k = 0; i > 0; --i) {
        v[i-1] += k;
        k += (s[i-1] == 'R');
    }
    return v == a;
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t x = 1;
    while (x < n && a[x-1] == a[x])
        ++x;

    if (x == n) {
        std::string s(n, 'L'), t(n, 'R');
        for (size_t i = 1; i < n; i += 2) {
            s[i] = 'R';
            t[i] = 'L';
        }
        return answer(check(s, a) + check(t, a));
    }

    std::string s(n, ' ');

    const auto restore = [&](size_t i, size_t j) {
        if (a[i] == a[j])
            s[i] = s[j] ^ 'L' ^ 'R';
        else
            s[i] = s[j];
    };

    s[x] = (a[x-1] < a[x] ? 'L' : 'R');

    for (size_t i = x; i > 0; --i)
        restore(i-1, i);

    for (size_t i = x + 1; i < n; ++i)
        restore(i, i-1);

    answer(check(s, a));
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
