#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Volunteer {
    unsigned t;
    unsigned z;
    unsigned y;
};

std::istream& operator >>(std::istream& input, Volunteer& v)
{
    return input >> v.t >> v.z >> v.y;
}

template <typename T, typename F>
T search(T lb, T ub, F&& f)
{
    if (f(lb))
        return lb;

    for (auto k = ub - lb; k > 1; ) {
        const auto half = k / 2;
        if (!f(lb + half))
            lb += half;

        k -= half;
    }
    return lb + 1;
}

void answer(unsigned v, const std::vector<unsigned>& t)
{
    std::cout << v << '\n';

    for (const unsigned x : t)
        std::cout << x << '\n';
}

void solve(unsigned m, const std::vector<Volunteer>& v)
{
    const auto k = [](const Volunteer& v, unsigned t) {
        const unsigned c = v.z * v.t + v.y;
        return t / c * v.z + std::min(v.z, t % c / v.t);
    };

    const auto f = [&](unsigned t) {
        unsigned long long c = 0;
        for (const auto& q : v)
            c += k(q, t);

        return c >= m;
    };

    const unsigned t = search(0u, m * 200, f);

    std::vector<unsigned> d;
    for (const auto& q : v) {
        const unsigned c = std::min(m, k(q, t));
        d.push_back(c);
        m -= c;
    }

    answer(t, d);
}

int main()
{
    unsigned m;
    std::cin >> m;

    size_t n;
    std::cin >> n;

    std::vector<Volunteer> v(n);
    std::cin >> v;

    solve(m, v);

    return 0;
}

