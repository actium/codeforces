#include <iostream>
#include <set>
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

unsigned f(unsigned x)
{
    unsigned k = 0;
    do {
        x /= 10;
        ++k;
    } while (x != 0);

    return k;
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    unsigned k = 0;

    std::multiset<unsigned> x(a.cbegin(), a.cend()), y(b.cbegin(), b.cend());
    while (!x.empty()) {
        const unsigned c = *x.crbegin(), d = *y.crbegin();
        x.erase(--x.end());
        y.erase(--y.end());

        if (c == d)
            continue;

        if (c > d) {
            x.insert(f(c));
            y.insert(d);
        } else {
            x.insert(c);
            y.insert(f(d));
        }

        ++k;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
