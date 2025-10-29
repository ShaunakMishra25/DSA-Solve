def maxProfit(prices):
    min_price = float('inf')
    max_profit = 0

    for p in prices:
        if p < min_price:
            min_price = p
        else:
            max_profit = max(max_profit, p - min_price)

    return max_profit

if __name__=="__main__":
    prices=[1,4,5,1,8]
    result=maxProfit(prices)
    print("Max profit: ", result)

