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

void answer(size_t u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& h)
{
    std::sort(h.begin(), h.end());

    std::vector<unsigned> q[3];
    for (const unsigned x : h) {
        for (size_t i = 0; i < 3; ++i) {
            if (q[i].empty() || q[i].back() < x || i == 2) {
                q[i].push_back(x);
                break;
            }
        }
    }

    std::vector<unsigned> v;
    v.insert(v.end(), q[0].begin(), q[0].end());
    v.insert(v.end(), q[2].begin(), q[2].end());
    v.insert(v.end(), q[1].rbegin(), q[1].rend());

    answer(q[0].size() + q[1].size(), v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h);
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
