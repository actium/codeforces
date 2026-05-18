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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

bool filter(std::vector<unsigned>& v, const std::vector<bool>& s)
{
    while (!v.empty() && s[v.back()])
        v.pop_back();

    return v.empty();
}

void solve(std::vector<std::vector<unsigned>>& a)
{
    std::vector<unsigned> v;
    for (std::vector<bool> s(1000001); !a.empty(); ) {
        std::vector<std::vector<unsigned>*> q;
        for (auto& v : a)
            q.push_back(&v);

        while (!q.empty()) {
            unsigned x = ~0u;
            for (const auto p : q)
                x = std::min(x, p->back());

            q.erase(std::remove_if(q.begin(), q.end(), [x](auto p) { return p->back() != x; }), q.end());

            v.push_back(x);
            s[x] = true;

            for (const auto p : q) {
                if (filter(*p, s)) {
                    q.clear();
                    break;
                }
            }
        }

        a.erase(std::remove_if(a.begin(), a.end(), [&](auto& v) { return filter(v, s); }), a.end());
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(n);
    for (size_t i = 0; i < n; ++i) {
        size_t k;
        std::cin >> k;

        a[i].resize(k);
        std::cin >> a[i];
    }

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
