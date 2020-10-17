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

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const std::set<unsigned> u(a.cbegin(), a.cend());

    const unsigned k = u.size();
    if (k == 1)
        return answer(0);

    if (k == 2) {
        const unsigned d = *u.rbegin() - *u.begin();
        return answer(d % 2 == 0 ? d / 2 : d);
    }

    if (k == 3) {
        const auto mid = std::next(u.begin());

        const unsigned d1 = *mid - *u.begin();
        const unsigned d2 = *u.rbegin() - *mid;

        return answer(d1 == d2 ? d1 : -1);
    }

    answer(-1);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

