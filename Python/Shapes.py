import math

def calculate_area():
    
    print("Welcome to the Area Calculator!")
    print("You can calculate the area of different geometric shapes.")

    while True:
        print("\nChoose a shape to calculate the area:")
        print("1. Square")
        print("2. Rectangle")
        print("3. Triangle")
        print("4. Circle")
        print("5. Trapezoid")
        print("6. Exit")

        choice = input("Choose a shape (1-6): ")

        if choice == "1":
            try:
                alpha = float(input("Enter the length of side α: "))
                if alpha <= 0:
                    print("Side length must be a positive number.")
                    continue
                area = alpha ** 2
                print(f"The area of the square is: {area}")
            except ValueError:
                print("Invalid input! Please enter a valid number.")

        elif choice == "2":
            try:
                beta = float(input("Enter the length β: "))
                upsilon = float(input("Enter the width υ: "))
                if beta <= 0 or upsilon <= 0:
                    print("Length and width must be positive numbers.")
                    continue
                area = beta * upsilon
                print(f"The area of the rectangle is: {area}")
            except ValueError:
                print("Invalid input! Please enter valid numbers.")

        elif choice == "3":
            try:
                beta = float(input("Enter the base β: "))
                upsilon = float(input("Enter the height υ: "))
                if beta <= 0 or upsilon <= 0:
                    print("Base and height must be positive numbers.")
                    continue
                area = (beta * upsilon) / 2
                print(f"The area of the triangle is: {area}")
            except ValueError:
                print("Invalid input! Please enter valid numbers.")

        elif choice == "4":
            try:
                radius = float(input("Enter the radius of the circle: "))
                if radius <= 0:
                    print("Radius must be a positive number.")
                    continue
                area = math.pi * radius ** 2
                print(f"The area of the circle is: {area}")
            except ValueError:
                print("Invalid input! Please enter a valid number.")

        elif choice == "5":
            try:
                a = float(input("Enter the length of the first base a: "))
                b = float(input("Enter the length of the second base b: "))
                h = float(input("Enter the height h: "))
                if a <= 0 or b <= 0 or h <= 0:
                    print("Bases and height must be positive numbers.")
                    continue
                area = (a + b) * h / 2
                print(f"The area of the trapezoid is: {area}")
            except ValueError:
                print("Invalid input! Please enter valid numbers.")

        elif choice == "6":
            print("Goodbye!!!")
            break

        else:
            print("Invalid choice! Please try again.")

# Run the function
calculate_area()
