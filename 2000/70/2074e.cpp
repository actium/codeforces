#include <iostream>
#include <vector>

#include <cassert>

unsigned query(unsigned i, unsigned j, unsigned k)
{
    std::cout << '?' << ' ' << i << ' ' << j << ' ' << k << std::endl;

    int r;
    std::cin >> r;
    assert(r != -1);
    return r;
}

void answer(unsigned i, unsigned j, unsigned k)
{
    std::cout << '!' << ' ' << i << ' ' << j << ' ' << k << std::endl;
}

void solve(unsigned n)
{
    std::vector<unsigned> q = { 1, 2, 3 };
    while (true) {
        const unsigned p = query(q[0], q[1], q[2]);
        if (p == 0)
            return answer(q[0], q[1], q[2]);

        q[rand() % 3] = p;
    }
}

void test_case()
{
    int n;
    std::cin >> n;
    assert(n != -1);

    solve(n);
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
