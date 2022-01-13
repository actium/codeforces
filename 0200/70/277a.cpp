#include <iostream>
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

void traverse(const std::vector<std::vector<unsigned>>& a, const std::vector<std::vector<size_t>>& b, size_t i, std::vector<bool>& v)
{
    v[i] = true;

    for (const unsigned u : a[i]) {
        for (const size_t j : b[u]) {
            if (!v[j])
                traverse(a, b, j, v);
        }
    }
}

void solve(const std::vector<std::vector<unsigned>>& a, size_t m)
{
    const size_t n = a.size();

    std::vector<std::vector<size_t>> b(1 + m);
    for (size_t i = 0; i < n; ++i) {
        for (const unsigned x : a[i])
            b[x].push_back(i);
    }

    unsigned k = 0, q = 0;

    std::vector<bool> v(n);
    for (size_t i = 0; i < n; ++i) {
        if (!v[i]) {
            traverse(a, b, i, v);
            ++k;

            if (!a[i].empty())
                q = 1;
        }
    }

    answer(k - q);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n);
    for (size_t i = 0; i < n; ++i) {
        size_t k;
        std::cin >> k;

        a[i].resize(k);
        std::cin >> a[i];
    }

    solve(a, m);

    return 0;
}
