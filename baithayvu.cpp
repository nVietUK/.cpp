#include <bits/stdc++.h>
#include "bigint_function_definitions.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("BCP.inp", "r", stdin);
    freopen("BCP.out", "w", stdout);
#endif
    
    unsigned n; bigint in = 1, ou = 1; cin >> n;
    while (n-- && cin >> in)
        ou = big_lcm(in, ou);
    if 
    (
        (
            (
                (
                    (ou % to_bigint(10) == to_bigint(1)) ||
                    (ou % to_bigint(10) == to_bigint(9)) 
                ) &&
                (((ou / to_bigint(10)) % to_bigint(10)) % to_bigint(2) == to_bigint(0))
            ) ||
            (
                (ou % to_bigint(10) == to_bigint(5)) &&
                (((ou / to_bigint(10)) % to_bigint(10)) == to_bigint(2))
            ) ||
            (
                (ou % to_bigint(10) == to_bigint(6)) &&
                (((ou / to_bigint(10)) % to_bigint(10)) % to_bigint(2) == to_bigint(1))
            )
        ) &&
        (
            (ou % to_bigint(4) != to_bigint(2)) &&
            (ou % to_bigint(4) != to_bigint(3)) &&
            (ou % to_bigint(3) != to_bigint(2)) &&
            (
                (
                    (ou % to_bigint(2) == to_bigint(1)) && 
                    (ou % to_bigint(8) == to_bigint(1))
                ) ||
                (ou % to_bigint(2) == to_bigint(0))
            )
        )
    )
        cout << ou % to_bigint(100000007);
    else 
        cout << ou * ou % to_bigint(1000000007);
}