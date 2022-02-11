#include <iostream>

void answer(size_t v)
{
    constexpr const char* s[40] = {
        "Washington",
        "Adams",
        "Jefferson",
        "Madison",
        "Monroe",
        "Adams",
        "Jackson",
        "Van Buren",
        "Harrison",
        "Tyler",
        "Polk",
        "Taylor",
        "Fillmore",
        "Pierce",
        "Buchanan",
        "Lincoln",
        "Johnson",
        "Grant",
        "Hayes",
        "Garfield",
        "Arthur",
        "Cleveland",
        "Harrison",
        "Cleveland",
        "McKinley",
        "Roosevelt",
        "Taft",
        "Wilson",
        "Harding",
        "Coolidge",
        "Hoover",
        "Roosevelt",
        "Truman",
        "Eisenhower",
        "Kennedy",
        "Johnson",
        "Nixon",
        "Ford",
        "Carter",
        "Reagan",
    };
    std::cout << s[v] << '\n';
}

void solve(unsigned a)
{
    answer(a-1);
}

int main()
{
    unsigned a;
    std::cin >> a;

    solve(a);

    return 0;
}
