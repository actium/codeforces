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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& s, const std::vector<unsigned>& c)
{
    constexpr unsigned oo = 1000000000;

    const size_t n = s.size();

    std::vector<unsigned> dp2(n, oo), dp3(n, oo);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (s[j] < s[i]) {
                dp2[i] = std::min(dp2[i], c[j] + c[i]);
                dp3[i] = std::min(dp3[i], dp2[j] + c[i]);
            }
        }
    }

    unsigned x = oo;
    for (size_t i = 0; i < n; ++i)
        x = std::min(x, dp3[i]);

    x != oo ? answer(x) : no_answer();
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n), c(n);
    std::cin >> s >> c;

    solve(s, c);

    return 0;
}
