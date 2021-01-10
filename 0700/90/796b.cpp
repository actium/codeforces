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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(size_t n, const std::vector<unsigned>& h, const std::vector<std::pair<unsigned, unsigned>>& q)
{
    const size_t k = q.size();

    std::vector<bool> b(1+n);
    for (const unsigned x : h)
        b[x] = true;

    unsigned x = 1;
    for (size_t i = 0; i < k && !b[x]; ++i) {
        if (x == q[i].first || x == q[i].second)
            x = q[i].first + q[i].second - x;
    }

    answer(x);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> h(m);
    std::cin >> h;

    std::vector<std::pair<unsigned, unsigned>> q(k);
    std::cin >> q;

    solve(n, h, q);

    return 0;
}

