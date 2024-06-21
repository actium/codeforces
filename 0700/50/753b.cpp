#include <iostream>
#include <string>

std::pair<unsigned, unsigned> query(const std::string& q)
{
    std::cout << q << std::endl;

    unsigned b, c;
    std::cin >> b >> c;
    return std::make_pair(b, c);
}

void solve()
{
    std::string s(4, '0');
    {
        std::string q(4, '0');
        std::pair<unsigned, unsigned> v = query(q);
        if (v.first == 4)
            return;

        for (size_t i = 0; i < 4; ++i) {
            for (q[i] = '9'; q[i] != '0'; --q[i]) {
                const std::pair<unsigned, unsigned> u = query(q);
                if (u.first == 4)
                    return;

                if (u.first > v.first)
                    s[i] = q[i];
            }
        }
    }

    query(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}
