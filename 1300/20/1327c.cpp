#include <iostream>
#include <string>
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

void answer(const std::string& x)
{
    std::cout << x.length() << '\n';
    std::cout << x << '\n';
}

void solve(size_t n, size_t m, const std::vector<std::pair<unsigned, unsigned>>& s)
{
    std::string p;
    p.append(n - 1, 'U');
    p.append(m - 1, 'R');
    for (size_t i = 0; i < n; ++i) {
        p.append(m - 1, "LR"[i % 2]);
        p.push_back('D');
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::pair<unsigned, unsigned>> s(k), f(k);
    std::cin >> s >> f;

    solve(n, m, s);

    return 0;
}
