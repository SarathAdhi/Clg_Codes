# The stack-money  game is described as follows: Let ‘S’ be a stack  of coins of size ‘n’.
# For example, stack of coins of size  5 as show in below figure.
# Two players, ‘’Plus” and “Minus” , alternative moves with Minus making the first move.
# In each move, a player may remove up to k(k<n) coins from the stack. The player stuck with the last move is the loser.
# Design an algorithm to compute winner of the game and also print each player name and stack configuartion for each step.
# Implement your algorithm for any programming language

n=int(input("Please enter the number of coins"))
stack=[]
for i in range(0,n):
    stack.append("10 rupee Coin")
count =0
j=1
while(j!=0):
    print("Player Minus choose a k value")
    k=int(input())
    
    if k<n:
        count=1
        n=n-k
        for i in range (0,k):
            stack.pop()
        print(stack)
    else:
        if count==0:
            print("Player Minus Loses")
            break
        else:
            print("Player Plus Loses")
            break
    print("Player Plus choose a k value ")
    
    k=int(input())
    if k<n:
        count=0
        n=n-k
        for i in range (0,k):
            stack.pop()
        print(stack)
    else:
        if count==0:
            print("Player Minus Loses")
            break
        else:
            print("Player Plus Loses")
            break
