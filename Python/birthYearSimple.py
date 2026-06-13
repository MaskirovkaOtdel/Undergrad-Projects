C_year = 2025
    birthYear = int(input("Enter your Birth Year: "))
    age = C_year - birthYear
    print("My age is:", age)
except ValueError:
    print("Please enter a valid number for the birth year.")
