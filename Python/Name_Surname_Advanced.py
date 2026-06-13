import time
import random
import sys
import os

def enable_utf8():
    """Enables UTF-8 encoding for Windows cmd."""
    if os.name == "nt": 
        try:
            import ctypes
            ctypes.windll.kernel32.SetConsoleOutputCP(65001) 
        except Exception:
            pass 

def supports_unicode():
    """Checks if the terminal supports Unicode emojis."""
    try:
        "✅".encode(sys.stdout.encoding)
        return True
    except UnicodeEncodeError:
        return False

def display_banner(use_emojis=True):
    """Displays a stylish welcome banner."""
    banner = "🌟 WELCOME TO OUR PROGRAM 🌟" if use_emojis else "WELCOME TO OUR PROGRAM"
    print("\n" + "=" * 50)
    print(banner.center(50))
    print("=" * 50 + "\n")

def get_valid_name(prompt, max_attempts=3):
    """Prompts user for input, ensuring it's not empty, with a retry limit."""
    attempts = 0
    while attempts < max_attempts:
        name = input(prompt).strip().title()
        if name:
            return name
        attempts += 1
        print("❌ Input cannot be empty. Please try again.")

    print("⚠️ Too many invalid attempts. Using 'Guest' as default.")
    return "Guest"

def get_greeting(use_emojis=True):
    """Returns a greeting based on the current time."""
    current_hour = time.localtime().tm_hour

    if 5 <= current_hour < 12:
        return "🌅 Good morning" if use_emojis else "Good morning"
    elif 12 <= current_hour < 18:
        return "☀️ Good afternoon" if use_emojis else "Good afternoon"
    elif 18 <= current_hour < 22:
        return "🌙 Good evening" if use_emojis else "Good evening"
    else:
        return "🌟 Hello" if use_emojis else "Hello"

def get_random_message(use_emojis=True):
    """Returns a random uplifting message."""
    messages = [
        ("🌈 Wishing you a day filled with joy and success!", "Wishing you a joyful and successful day!"),
        ("😊 Keep smiling! You’re doing great!", "Keep smiling! You're doing great!"),
        ("✨ You are capable of amazing things!", "You are capable of amazing things!"),
        ("🌟 Stay positive and keep pushing forward!", "Stay positive and keep pushing forward!"),
        ("💪 Believe in yourself – you've got this!", "Believe in yourself – you've got this!")
    ]
    return random.choice(messages)[0] if use_emojis else random.choice(messages)[1]


enable_utf8()


use_emojis = supports_unicode()


display_banner(use_emojis)


first_name = get_valid_name("📝 Enter your first name: " if use_emojis else "Enter your first name: ")
surname = get_valid_name("📝 Enter your surname: " if use_emojis else "Enter your surname: ")


greeting = get_greeting(use_emojis)
random_message = get_random_message(use_emojis)


print("\n" + "-" * 50)
print(f"{greeting}, {first_name} {surname}! 🎉".center(50) if use_emojis else f"{greeting}, {first_name} {surname}!".center(50))
print(random_message.center(50))
print("-" * 50)
