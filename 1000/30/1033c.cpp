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

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> x(1+n);
    for (size_t i = 0; i < n; ++i)
        x[a[i]] = i;

    std::string s(n, 'B');

    const auto check = [&](unsigned d) {
        for (size_t i = x[d]; i >= d; i -= d) {
            if (a[i-d] > a[x[d]] && s[i-d] == 'B')
                return 1;
        }
        for (size_t i = x[d]; i + d < n; i += d) {
            if (a[i+d] > a[x[d]] && s[i+d] == 'B')
                return 1;
        }
        return 0;
    };

    for (unsigned i = n; i > 0; --i)
        s[x[i]] -= check(i);

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
