#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned s = 0;
    for (const unsigned x : a)
        s += x;

    if (s % n != 0) {
        std::cout << "Unrecoverable configuration." << '\n';
        return;
    }

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != s / n)
            p.push_back(i);
    }

    if (p.empty())
        std::cout << "Exemplary pages." << '\n';

    if (p.size() == 2) {
        size_t i = p.front(), j = p.back();
        if (a[i] < a[j])
            std::swap(i, j);

        const unsigned d = (a[i] - a[j]) / 2;
        std::cout << d << " ml. from cup #" << 1+j << " to cup #" << 1+i << "." << '\n';
    }

    if (p.size() > 2)
        std::cout << "Unrecoverable configuration." << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

