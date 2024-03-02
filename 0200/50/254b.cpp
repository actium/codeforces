#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Contest {
    unsigned m;
    unsigned d;
    unsigned p;
    unsigned t;
};

std::istream& operator >>(std::istream& input, Contest& c)
{
    return input >> c.m >> c.d >> c.p >> c.t;
}

unsigned date(unsigned m, unsigned d)
{
    constexpr unsigned p[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

    return 100 + p[m-1] + d;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<Contest>& c)
{
    std::vector<std::pair<unsigned, int>> events;
    for (const Contest& x : c) {
        const unsigned t = date(x.m, x.d);
        events.emplace_back(t - x.t, x.p);
        events.emplace_back(t, -x.p);
    }

    std::sort(events.begin(), events.end());

    int k = 0;
    for (const std::pair<unsigned, int>& e : events) {
        if (e.second > k)
            k += e.second - k;

        k -= e.second;
    }

    answer(k);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<Contest> c(n);
    std::cin >> c;

    solve(c);

    return 0;
}
