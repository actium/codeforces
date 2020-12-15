#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned s = 0;
    for (const unsigned x : a)
        s += x;

    const auto check = [&](unsigned k) {
        const unsigned p = s / (n - k);

        unsigned q = 0;
        for (const unsigned x : a) {
            q += x;

            if (q > p)
                return false;

            if (q == p)
                q = 0;
        }
        return q == 0;
    };

    for (unsigned k = 0; k < n-1; ++k) {
        if (s % (n - k) == 0 && check(k))
            return answer(k);
    }

    answer(n - 1);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

