#include <iostream>
#include <numeric>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    std::vector<unsigned> v;
    {
        std::multiset<unsigned> s(a.begin(), a.end());
        while (!s.empty()) {
            const unsigned x = *s.rbegin();

            for (const unsigned y : v) {
                const unsigned g = std::gcd(x, y);
                s.erase(s.find(g));
                s.erase(s.find(g));
            }
            s.erase(std::prev(s.end()));

            v.push_back(x);
        }
    }
    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n * n);
    std::cin >> a;

    solve(a);

    return 0;
}
