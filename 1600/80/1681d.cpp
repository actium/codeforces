#include <iostream>
#include <map>
#include <string>

using integer = unsigned long long;

constexpr unsigned oo = ~0u >> 1;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

std::map<integer, unsigned> memo;

unsigned search(integer x, unsigned n)
{
    const std::string s = std::to_string(x);
    if (s.length() == n)
        return 0;
    if (s.length() > n)
        return oo;

    auto it = memo.find(x);
    if (it == memo.end()) {
        unsigned v[10] = { 1, 1 }, k = oo;
        for (const char c : s) {
            const unsigned d = c - '0';
            if (v[d]++ == 0)
                k = std::min(k, 1 + search(x * d, n));
        }

        it = memo.emplace(x, k).first;
    }
    return it->second;
}

void solve(unsigned n, integer x)
{
    const unsigned k = search(x, n);
    k < oo ? answer(k) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    integer x;
    std::cin >> x;

    solve(n, x);

    return 0;
}
