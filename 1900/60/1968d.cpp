#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& p, const std::vector<unsigned>& a, unsigned k, unsigned pb, unsigned ps)
{
    using integer = unsigned long long;

    const size_t n = p.size();

    const auto search = [&](size_t x) {
        integer s = 0, v = 0;
        for (unsigned t = 0; t < k && t < n; ++t) {
            v = std::max(v, s + integer(k - t) * a[x]);
            s += a[x];
            x = p[x] - 1;
        }
        return v;
    };

    const integer vb = search(pb-1), vs = search(ps-1);
    if (vb == vs)
        return answer("Draw");

    answer(vb > vs ? "Bodya" : "Sasha");
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k, pb, ps;
    std::cin >> k >> pb >> ps;

    std::vector<unsigned> p(n), a(n);
    std::cin >> p >> a;

    solve(p, a, k, pb, ps);
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
