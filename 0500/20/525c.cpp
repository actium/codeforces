#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& l)
{
    std::sort(l.begin(), l.end(), std::greater<unsigned>());

    integer s = 0;

    std::vector<unsigned> p;
    for (auto it = l.begin(); it != l.end(); ++it) {
        if (p.size() % 2 == 0 || p.back() - *it < 2)
            p.push_back(*it);
        else
            p.back() = *it;

        if (p.size() == 4) {
            s += 1ull * p[1] * p[3];
            p.clear();
        }
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> l(n);
    std::cin >> l;

    solve(l);

    return 0;
}
