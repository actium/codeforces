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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, unsigned k, unsigned m, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const auto remove_link = [&](unsigned x) {
        if (x < k) {
            k -= x;
            n -= x;
        } else {
            n = x;
        }
    };

    const auto insert_link = [&](unsigned x) {
        k += (x <= k);
        n += (n < m);
    };

    for (const std::pair<unsigned, unsigned>& q : r) {
        if (q.first == 0) {
            remove_link(q.second);
        } else {
            insert_link(q.second);
        }

        answer(n, k);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, k, m;
    std::cin >> n >> k >> m;

    size_t t;
    std::cin >> t;

    std::vector<std::pair<unsigned, unsigned>> r(t);
    std::cin >> r;

    solve(n, k, m, r);

    return 0;
}
