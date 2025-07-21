#include <algorithm>
#include <iostream>
#include <vector>

struct Triple {
    unsigned l;
    unsigned r;
    unsigned v;
};

std::istream& operator >>(std::istream& input, Triple& t)
{
    return input >> t.l >> t.r >> t.v;
}

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

void solve(std::vector<Triple>& t, unsigned k)
{
    std::sort(t.begin(), t.end(), [](const Triple& lhs, const Triple& rhs) {
        return lhs.l != rhs.l ? lhs.l < rhs.l : lhs.r < rhs.r;
    });

    for (const Triple& q : t) {
        if (q.l > k)
            break;

        k = std::max(k, q.v);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<Triple> t(n);
    std::cin >> t;

    solve(t, k);
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
