#include <iostream>
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

void solve(const std::vector<unsigned>& w)
{
    const size_t n = w.size();

    if (n % 2 == 1)
        return answer(false);

    unsigned p = w[0], q = w[1];
    for (size_t i = 3; i < n; i += 2) {
        p = std::min(p, w[i-1]);
        q = std::max(q, w[i]);
    }

    answer(q + 1 < p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> w(n);
    std::cin >> w;

    solve(w);
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
