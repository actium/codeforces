#include <bitset>
#include <iostream>
#include <queue>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

struct P {
    std::bitset<2000> p = 1;
    size_t size = 1;

    integer v = 2;
    integer f = 4;

    bool operator <(const P& x) const
    {
        return v < x.v;
    }

    P next(unsigned x) const
    {
        P a = *this;
        if (x == 1) {
            a.p.set(size);
            a.v += 2;
            a.f = 4;
        } else {
            a.v += f;
            a.f *= 2;
        }
        ++a.size;
        return a;
    }
};

void solve(integer k)
{
    if (k % 2 == 1)
        return no_answer();

    std::priority_queue<P> q;
    for (q.emplace(); !q.empty(); ) {
        const P top = q.top();
        q.pop();

        if (top.v == k) {
            std::vector<unsigned> x(top.size);
            for (size_t i = 0; i < top.size; ++i)
                x[i] = top.p[i];

            return answer(x);
        }

        for (const unsigned d : { 0, 1 }) {
            const P x = top.next(d);
            if (x.v <= k)
                q.push(x);
        }
    }

    no_answer();
}

void test_case()
{
    integer k;
    std::cin >> k;

    solve(k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

