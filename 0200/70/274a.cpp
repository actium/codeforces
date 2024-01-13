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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned k)
{
    std::set<unsigned> s(a.begin(), a.end());

    if (k != 1) {
        for (auto it = s.begin(); it != s.end(); ) {
            if (*it % k == 0 && s.find(*it / k) != s.end())
                it = s.erase(it);
            else
                ++it;
        }
    }

    answer(s.size());
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
