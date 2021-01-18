#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    const auto x = [n](const std::vector<unsigned>& s) {
        std::vector<bool> v(n);
        for (const unsigned q : s)
            v[q-1] = true;

        unsigned q = 1;
        while (v[q-1])
            ++q;

        return q;
    };

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != b[i])
            p.push_back(i);
    }

    if (p.size() == 1 || a[p.front()] != x(b) || b[p.back()] != x(a))
        a[p.front()] = x(a);
    else
        a[p.back()] = x(a);

    answer(a);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

