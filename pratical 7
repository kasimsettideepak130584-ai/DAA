def min_coins(coins, amount):
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0

    for i in range(1, amount + 1):
        for coin in coins:
            if i - coin >= 0:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[amount] if dp[amount] != float('inf') else -1

# Get user input for coin values
raw_coins = input("Enter available coin values separated by spaces (e.g., 1 5 10 25): ")
coins = [int(x) for x in raw_coins.split() if x.isdigit()]

# Get user input for target amount
amount = int(input("Enter target amount: "))

# Calculate and display result
result = min_coins(coins, amount)

if result != -1:
    print(f"\nMinimum coins needed: {result}")
else:
    print(f"\nIt's impossible to make {amount} with the given coins.")
