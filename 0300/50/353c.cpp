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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::string& s)
{
    const size_t n = a.size();

    std::vector<unsigned> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + a[i];

    unsigned t = 0, v = 0;
    for (size_t i = n-1; ~i != 0; --i) {
        if (s[i] == '1') {
            v = std::max(v, t + p[i]);
            t += a[i];
        }
    }

    answer(std::max(t, v));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::string s;
    std::cin >> s;

    solve(a, s);

    return 0;
}
