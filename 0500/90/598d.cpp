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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned count(const std::vector<std::string>& b, size_t i, size_t j, unsigned k, std::vector<std::vector<unsigned>>& c)
{
    if (i >= b.size() || j >= b[0].size() || c[i][j] != ~0u)
        return 0;

    if (b[i][j] == '*')
        return 1;

    c[i][j] = k;
    return count(b, i-1, j, k, c) + count(b, i, j+1, k, c) + count(b, i+1, j, k, c) + count(b, i, j-1, k, c);
}

void solve(const std::vector<std::string>& b, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = b.size(), m = b[0].size();

    std::vector<std::vector<unsigned>> c(n, std::vector<unsigned>(m, ~0u));
    std::vector<unsigned> f;
    for (const std::pair<unsigned, unsigned>& q : r) {
        if (c[q.first-1][q.second-1] == ~0u)
            f.push_back(count(b, q.first-1, q.second-1, f.size(), c));

        answer(f[c[q.first-1][q.second-1]]);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::string> b(n);
    std::cin >> b;

    std::vector<std::pair<unsigned, unsigned>> r(k);
    std::cin >> r;

    solve(b, r);

    return 0;
}
