#include <iostream>
#include <map>
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

template <typename Iterator>
int balance(Iterator begin, Iterator end)
{
    int b = 0;
    for (auto it = begin; it != end; ++it)
        b += (*it == 1 ? 1 : -1);

    return b;
}

template <typename Iterator>
std::map<int, unsigned> count(Iterator begin, Iterator end)
{
    std::map<int, unsigned> c;
    {
        int b = balance(begin, end);
        for (auto it = begin; it != end; ++it) {
            c.emplace(b, it - begin);
            b -= (*it == 1 ? 1 : -1);
        }
        c.emplace(b, end - begin);
    }
    return c;
}

template <typename Iterator>
unsigned check(Iterator begin, Iterator end, const std::map<int, unsigned>& c)
{
    unsigned k = ~0u;
    {
        int b = balance(begin, end);
        for (auto it = begin; it != end; ++it) {
            const auto jt = c.find(-b);
            if (jt != c.end())
                k = std::min<unsigned>(k, it - begin + jt->second);

            b -= (*it == 1 ? 1 : -1);
        }

        const auto jt = c.find(-b);
        if (jt != c.end())
            k = std::min<unsigned>(k, end - begin + jt->second);
    }
    return k;
}


void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size() / 2;

    const std::map<int, unsigned> p = count(a.rbegin() + n, a.rend()), s = count(a.begin() + n, a.end());

    unsigned k = 2 * n;
    k = std::min(k, check(a.rbegin() + n, a.rend(), s));
    k = std::min(k, check(a.begin() + n, a.end(), p));

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
    std::cin >> a;

    solve(a);
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
