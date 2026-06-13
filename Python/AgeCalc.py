import os
from datetime import datetime
from colorama import Fore, Style, init

# Initialize colorama
init(autoreset=True)

# Function to clear the terminal screen
def clear_terminal():
    os.system('cls' if os.name == 'nt' else 'clear')

# Function to set a custom color theme
def set_color_theme():
    Fore.RED = Fore.LIGHTRED_EX
    Fore.GREEN = Fore.LIGHTGREEN_EX
    Fore.YELLOW = Fore.LIGHTYELLOW_EX
    Fore.BLUE = Fore.LIGHTBLUE_EX
    Fore.MAGENTA = Fore.LIGHTMAGENTA_EX
    Fore.CYAN = Fore.LIGHTCYAN_EX

def is_leap_year(year):
    if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
        return True
    else:
        return False

def calculate_age(birthdate):
    today = datetime.today()
    age = today.year - birthdate.year - ((today.month, today.day) < (birthdate.month, birthdate.day))
    return age

# Function to display the guide and get user choice
def display_guide():
    print("\nOptions:")
    print("1. Calculate another age")
    print("2. Exit")
    choice = input("Enter your choice (1/2): ")
    return choice

# Main loop for age calculation
while True:
    # Clear the terminal and set the custom color theme
    clear_terminal()
    set_color_theme()

    birthdate_str = input("Enter your birthdate (YYYY-MM-DD): ")
    birthdate = datetime.strptime(birthdate_str, "%Y-%m-%d")

    if not is_leap_year(birthdate.year):
        print(f"{Fore.RED} {birthdate.year} is not a leap year.")
    else:
        age = calculate_age(birthdate)
        years = age
        months = 0
        days = 0

        if birthdate.month > datetime.today().month or (birthdate.month == datetime.today().month and birthdate.day > datetime.today().day):
            years -= 1

        if birthdate.month < datetime.today().month:
            months = datetime.today().month - birthdate.month
        elif birthdate.month > datetime.today().month:
            months = 12 - (birthdate.month - datetime.today().month)

        if birthdate.day < datetime.today().day:
            days = datetime.today().day - birthdate.day
        elif birthdate.day > datetime.today().day:
            days = (datetime.today().day + 30) - birthdate.day

        print(f"Your age is {Fore.GREEN}{years} years, {Fore.BLUE}{months} months, and {Fore.RED}{days} days.{Style.RESET_ALL}")
        print(f"Months: {Fore.GREEN}{age * 12 + months} months")
        print(f"Weeks: {Fore.YELLOW}{int((age * 365 + months * 30 + days) / 7)} weeks")
        print(f"Days: {Fore.CYAN}{age * 365 + months * 30 + days} days")

    choice = display_guide()

    if choice == '2':
        print("Exiting the program. Goodbye!")
        break