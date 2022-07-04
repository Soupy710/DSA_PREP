def maxProfit(prices) -> int:
    
    l,r = 0,0
    res = 0
    while r<len(prices):
        if(prices[l]>prices[r]):
            l = r
        else:
            res = max(res,prices[r]-prices[l])
        r+=1
    return res

if __name__ == '__main__':
    n = int(input())
    prices = [int(i) for i in list(input().split(' '))]
    print(maxProfit(prices))
