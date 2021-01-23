#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Request {
    unsigned t;
    unsigned k;
    unsigned d;
};

std::istream& operator >>(std::istream& input, Request& v)
{
    return input >> v.t >> v.k >> v.d;
}

void solve(size_t n, const std::vector<Request>& r)
{
    std::vector<bool> s(n);
    std::map<unsigned, std::vector<size_t>> p;
    for (auto [t, k, d] : r) {
        while (!p.empty() && p.begin()->first <= t) {
            for (const size_t i : p.begin()->second) {
                s[i] = false;
                ++n;
            }
            p.erase(p.begin());
        }

        if (k > n) {
            std::cout << -1 << '\n';
        } else {
            unsigned b = 0;
            for (size_t i = 0; k > 0; ++i) {
                if (!s[i]) {
                    b += 1 + i;
                    s[i] = true;
                    p[t + d].push_back(i);
                    --n, --k;
                }
            }
            std::cout << b << '\n';
        }
    }
}

int main()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<Request> r(q);
    std::cin >> r;

    solve(n, r);

    return 0;
}

