#include <iostream>
#include <map>
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

void solve(std::vector<unsigned>& a)
{
    std::map<unsigned, unsigned> f;
    for (const unsigned x : a)
        ++f[x];

    unsigned k = 0;
    while (!f.empty()) {
        std::set<unsigned> q;
        for (auto it = f.begin(); it != f.end(); ++it)
            q.insert(it->first);

        while (!q.empty()) {
            const unsigned x = a.back();
            a.pop_back();

            const auto it = f.find(x);
            if (--it->second == 0)
                f.erase(it);

            q.erase(x);
        }

        ++k;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
