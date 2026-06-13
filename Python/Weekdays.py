day = int(input("insert number"))
match day:
    case 1:
        print("Monday")
    case 2:
        print("Tuesday")
    case 3:
        print("Sunday")
    case _:
        print("not a day of the week")