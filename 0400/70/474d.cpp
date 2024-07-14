#include <iostream>
#include <vector>

constexpr unsigned N = 100000, M = 1000000007;

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

void solve(const std::vector<std::pair<unsigned, unsigned>>& r, size_t k)
{
    unsigned c[1+N] = {};
    for (size_t i = 0; i < N; ++i) {
        if (i + k <= N)
            c[i+k] = (c[i+k] + c[i] + 1) % M;

        c[i+1] = (c[i+1] + c[i] + 1) % M;
    }

    for (const std::pair<unsigned, unsigned>& q : r)
        answer((M + c[q.second] - c[q.first-1]) % M);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t, k;
    std::cin >> t >> k;

    std::vector<std::pair<unsigned, unsigned>> r(t);
    std::cin >> r;

    solve(r, k);

    return 0;
}
