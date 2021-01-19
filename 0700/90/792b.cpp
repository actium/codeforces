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
    for (const size_t x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(size_t n, const std::vector<unsigned>& a)
{
    const size_t k = a.size();

    std::vector<std::pair<size_t, unsigned>> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = { i, 1+i };

    std::vector<unsigned> d;
    for (size_t i = 0, x = 0; i < k; ++i) {
        const size_t n = p.size();
        x = (x + a[i] % n) % n;
        d.push_back(p[x].second);
        p.erase(p.begin() + x);
    }

    answer(d);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(k);
    std::cin >> a;

    solve(n, a);

    return 0;
}

