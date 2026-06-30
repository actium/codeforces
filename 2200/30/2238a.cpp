#include <algorithm>
#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

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

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b, unsigned c)
{
    const size_t n = a.size();

    const auto evaluate = [&] {
        unsigned s = 0;
        for (size_t i = 0; i < n; ++i) {
            if (a[i] < b[i])
                return oo;

            s += a[i] - b[i];
        }
        return s;
    };

    const auto t1 = evaluate();
    if (t1 != oo)
        return answer(t1);

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    const auto t2 = evaluate();
    if (t2 != oo)
        return answer(t2 + c);

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned c;
    std::cin >> c;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, c);
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
