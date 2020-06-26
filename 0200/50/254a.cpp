#include <iostream>
#include <unordered_map>
#include <vector>

#include <cstdio>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void answer(size_t x, size_t y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size() / 2;

    std::unordered_map<unsigned, std::vector<size_t>> m;
    for (size_t i = 0; i < 2 * n; ++i)
        m[a[i]].push_back(i + 1);

    for (const auto& entry : m) {
        if (entry.second.size() % 2 != 0)
            return answer(-1);
    }

    for (const auto& entry : m) {
        const std::vector<size_t>& indices = entry.second;
        for (size_t i = 0, n = indices.size(); i < n; i += 2)
            answer(indices[i], indices[i+1]);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
    std::cin >> a;

    solve(a);

    return 0;
}

