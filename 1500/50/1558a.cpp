#include <iostream>
#include <set>

void answer(const std::set<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned a, unsigned b)
{
    const unsigned c1 = (a + b) / 2, c2 = (a + b + 1) / 2;

    std::set<unsigned> v;

    const auto h = [&](unsigned k1, unsigned k2) {
        const unsigned lb = std::abs(int(k1) - int(a));
        const unsigned ub = std::min(k1, a) + std::min(k2, b);

        for (unsigned x = lb; x <= ub; x += 2)
            v.insert(x);

        v.insert(ub);
    };

    h(c1, c2);
    h(c2, c1);

    answer(v);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

/*
    A       B

    games won
    1       4

    possible games distributions
    2       3
    3       2

    max wins of own games (min breaks)
    1/2     3/3     -> k = 1 (|1-2| or |4-3|)
    1/3     2/2     -> k = 2 (|1-3| or |4-2|)

    max breaks
    1/3     2/2     -> k = 3 (1+2)
    1/2     3/3     -> k = 4 (1+3)

    ------------------------------------------

    games won
    0       5

    possible games distributions
    2       3
    3       2

    max wins of own games (min breaks)
    0/2     3/3     -> k = 2 (|0-2| or |5-3|)
    0/3     2/2     -> k = 3 (|0-3| or |5-2|)

    max breaks
    0/3     2/2     -> k = 2 (0+2)
    0/2     3/3     -> k = 3 (0+3)

    ------------------------------------------

    games won
    3       8

    possible games distributions
    5       6
    6       5

    max wins of own games (min breaks)
    3/5     6/6     -> k = 2 (|3-5| or |8-6|)
    3/6     5/5     -> k = 3 (|3-6| or |8-5|)

    max breaks
    3/6     5/5     -> k = 8 (3+5)
    3/5     6/6     -> k = 9 (3+6)

    ------------------------------------------

    1       1

    1       1

    1/1     1/1     -> k = 0

    1/1     1/1     -> k = 2

    ------------------------------------------

    0       1

    0       1
    1       0

    0/0     1/1     -> k = 0
    0/1     1/1     -> k = 1

    0/1     0/0     -> k = 0
    0/0     1/1     -> k = 1

    ------------------------------------------

    0       3

    1       2
    2       1

    0/1     2/2     -> k = 1
    0/2     1/1     -> k = 2

    0/2     1/1     -> k = 1
    0/1     2/2     -> k = 2
*/
