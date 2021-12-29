#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

bool search(const std::vector<std::vector<size_t>>& g, size_t i, std::vector<bool>& v, std::vector<size_t>& path)
{
    path.push_back(i);
    v[i] = true;

    if (path.size() == g.size())
        return true;

    for (const size_t j : g[i]) {
        if (!v[j] && search(g, j, v, path))
            return true;
    }

    path.pop_back();
    v[i] = false;

    return false;
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<std::vector<size_t>> g(n+1);
    for (size_t i = 0; i < n-1; ++i)
        g[i].push_back(i+1);

    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 0)
            g[i].push_back(n);
        else
            g[n].push_back(i);
    }

    std::vector<bool> v(n+1);
    for (size_t i = 0; i < n+1; ++i) {
        std::vector<size_t> path;
        if (search(g, i, v, path))
            return answer(path);
    }

    no_answer();
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
