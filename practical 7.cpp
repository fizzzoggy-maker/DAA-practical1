#include <iostream>
using namespace std;

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    int coins[n];

    cout << "Enter coin values: ";
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    int dp[amount + 1];

    // Base case
    dp[0] = 0;

    // Initialize all values
    for(int i = 1; i <= amount; i++)
        dp[i] = 999999;

    // Dynamic Programming
    for(int i = 1; i <= amount; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(coins[j] <= i)
            {
                dp[i] = min(dp[i],
                            1 + dp[i - coins[j]]);
            }
        }
    }

    cout << "Minimum number of coins = " << dp[amount] << endl;

    return 0;
}
