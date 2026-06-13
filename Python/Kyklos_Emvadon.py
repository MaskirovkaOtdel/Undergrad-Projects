import math

def circle_area(radius):
    return math.pi * radius ** 2

def get_valid_radius():
    while True:
        try:
            radius = float(input("Δώσε την ακτίνα του κύκλου: "))
            if radius <= 0:
                print("Η ακτίνα πρέπει να είναι θετική. Δοκίμασε ξανά.")
            else:
                return radius
        except ValueError:
            print("Μη έγκυρη τιμή. Παρακαλώ εισάγετε έναν αριθμό.")

radius = get_valid_radius()
area = circle_area(radius)

print(f"Το εμβαδόν του κύκλου είναι: {area:.2f}")
