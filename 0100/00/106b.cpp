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

struct Notebook {
    unsigned cpu;
    unsigned ram;
    unsigned hdd;
    unsigned cost;
};

std::istream& operator >>(std::istream& input, Notebook& v)
{
    return input >> v.cpu >> v.ram >> v.hdd >> v.cost;
}

void answer(size_t v)
{
    std::cout << 1+v << '\n';
}

void solve(const std::vector<Notebook>& d)
{
    const size_t n = d.size();

    size_t best = n;
    for (size_t i = 0; i < n; ++i) {
        const auto greater = [&](const Notebook& x) {
            return x.cpu > d[i].cpu && x.ram > d[i].ram && x.hdd > d[i].hdd;
        };
        if (std::any_of(d.cbegin(), d.cend(), greater))
            continue;

        if (best == n || d[i].cost < d[best].cost)
            best = i;
    }

    answer(best);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<Notebook> d(n);
    std::cin >> d;

    solve(d);

    return 0;
}

