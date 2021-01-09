#include <algorithm>
#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(const integer v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    for (std::string t = "47"; ; t = '4'+t+'7') {
        do {
            const integer z = std::stoull(t);
            if (z >= n)
                return answer(z);
        } while (std::next_permutation(t.begin(), t.end()));
    }
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

