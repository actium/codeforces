#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& edges)
{
    const size_t n = edges.size() + 1;

    std::vector<unsigned> d(n);
    for (const std::pair<unsigned, unsigned>& e : edges) {
        ++d[e.first-1];
        ++d[e.second-1];
    }

    for (const unsigned x : d) {
        if (x == 2)
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> edges(n-1);
    std::cin >> edges;

    solve(edges);

    return 0;
}
