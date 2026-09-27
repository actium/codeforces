#include <iostream>
#include <list>
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
    unsigned f[101] = {};
    for (const unsigned x : a)
        ++f[x];

    std::list<std::pair<unsigned, unsigned>> q;
    for (unsigned x = 100; x > 0; --x) {
        if (f[x] != 0)
            q.emplace_back(x, f[x]);
    }
    
    std::vector<unsigned> b;
    while (!q.empty()) {
        const unsigned k = q.begin()->second;

        for (auto it = q.begin(); it != q.end(); ) {
            if (it->second <= k) {
                b.insert(b.end(), it->second, it->first);
                it = q.erase(it);
            } else {
                b.insert(b.end(), k, it->first);
                it->second -= k;
                it = std::next(it);
            }
        }
    }

    answer(b);
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
