#include <iostream>
#include <vector>

using point_t = std::pair<unsigned, unsigned>;

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

void solve(size_t n, const std::vector<point_t>& p)
{
    std::vector<std::vector<unsigned>> b(2, std::vector<unsigned>(1+n+1));

    unsigned k = 0;
    for (const auto& q : p) {
        b[q.first-1][q.second] ^= 1;

        const int d = b[q.first%2][q.second-1] + b[q.first%2][q.second] + b[q.first%2][q.second+1];
        k += b[q.first-1][q.second] ? d : -d;

        answer(k == 0);
    }
}

int main()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<point_t> p(q);
    std::cin >> p;

    solve(n, p);

    return 0;
}
