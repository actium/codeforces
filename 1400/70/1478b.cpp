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

void solve(const std::vector<unsigned>& a, unsigned d)
{
    const auto check = [d](unsigned q) {
        for (unsigned k = d * d; k > 0 && d <= q; ++k) {
            if (q % d == 0)
                return true;

            for (unsigned x = q; x != 0; x /= 10) {
                if (x % 10 == d)
                    return true;
            }

            q -= d;
        }
        return false;
    };

    for (const unsigned q : a)
        answer(check(q));
}

void test_case()
{
    size_t q;
    std::cin >> q;

    unsigned d;
    std::cin >> d;

    std::vector<unsigned> a(q);
    std::cin >> a;

    solve(a, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

