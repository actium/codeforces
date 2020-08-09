#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

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

void solve(std::vector<unsigned>& d)
{
    std::sort(d.begin(), d.end(), std::greater<unsigned>());

    std::set<unsigned> v;

    const unsigned x = d.front();
    const unsigned y = *std::find_if(d.begin(), d.end(), [&](unsigned k) { return x % k != 0 || !v.insert(k).second; });

    answer(x, y);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> d(n);
    std::cin >> d;

    solve(d);

    return 0;
}

