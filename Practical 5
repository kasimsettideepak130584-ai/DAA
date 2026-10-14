def complete_knapsack():
    try:
        n = int(input("Enter number of items: "))
        cap = int(input("Enter capacity: "))
        wt = list(map(int, input("Enter weights: ").split()))
        val = list(map(int, input("Enter values: ").split()))

        # dp[w] stores [max_value, list_of_counts] for weight capacity w
        dp = [[0, [0] * n] for _ in range(cap + 1)]

        for w in range(1, cap + 1):
            for i in range(n):
                if wt[i] <= w:
                    prev_val = dp[w - wt[i]][0]
                    if prev_val + val[i] > dp[w][0]:
                        new_counts = list(dp[w - wt[i]][1])
                        new_counts[i] += 1
                        dp[w] = [prev_val + val[i], new_counts]

        print(f"\nMaximum Value: {dp[cap][0]}")
        for i in range(n):
            print(f"Item {i+1} ({wt[i]} kg, ${val[i]}): {dp[cap][1][i]} units")

    except ValueError:
        print("Invalid input! Please enter numbers only.")

if __name__ == "__main__":
    complete_knapsack()
