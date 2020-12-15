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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned x)
{
    const size_t n = a.size();

    std::set<unsigned> b(a.cbegin(), a.cend());
    if (b.size() < n)
        return answer(0);

    std::set<unsigned> c;
    for (const unsigned y : a) {
        const unsigned z = y & x;
        if (z != y && b.count(z) != 0)
            return answer(1);

        c.insert(z);
    }

    if (c.size() < n)
        return answer(2);

    no_answer();
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);

    return 0;
}

