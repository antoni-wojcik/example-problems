def guessingGame(ans):

    ans = int(ans)
    
    numberIsGeqTo = 0
    numberIsLThan = 1000

    while (numberIsGeqTo + 1) != numberIsLThan:
        guess = (numberIsGeqTo + numberIsLThan) // 2
        #response = input("Is your number less than " + str(guess) + ": ")
        if ans < guess:
            numberIsLThan = guess
        else:
            numberIsGeqTo = guess

    return numberIsGeqTo


print("Your number is " + str(guessingGame(input("What is your number? "))))
