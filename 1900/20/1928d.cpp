#include <iostream>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& c, unsigned b, unsigned x)
{
    const auto count = [](integer k) {
        return k * (k - 1) / 2;
    };

    const auto evaluate = [&](unsigned k) {
        integer s = 0;
        for (const unsigned u : c) {
            const unsigned q = u / k, r = u % k;
            s += b * (count(u) - r * count(q + 1) - (k - r) * count(q));
        }
        return s - (k - 1LL) * x;
    };

    unsigned lb = 1, ub = 200000;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;

        const integer lv = evaluate(mid - 1), mv = evaluate(mid), uv = evaluate(mid + 1);
        if (lv < mv && mv > uv)
            return answer(mv);

        (mv < uv ? lb : ub) = mid;
    }

    answer(std::max(evaluate(lb), evaluate(ub)));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned b, x;
    std::cin >> b >> x;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c, b, x);
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
