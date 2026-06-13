import tkinter as tk
from tkinter import messagebox
from time import strftime

# Function to handle form submission
def submit_form():
    username = username_entry.get()
    password = password_entry.get()
    
    # Validate if both fields are filled
    if not username or not password:
        messagebox.showerror("Error", "Please enter both username and password.")
        return

    # Show a confirmation message box
    response = messagebox.askyesno("Confirmation", f"Are these details correct?\n\nUsername: {username}")
    
    if response:
        messagebox.showinfo("Success", "Thank you! Your details have been confirmed.")
    else:
        messagebox.showwarning("Cancelled", "Details not confirmed. Please try again.")

# Function to update the time and date every second
def time():
    string = strftime('%Y-%m-%d %H:%M:%S %p')  # Current time and date format
    time_label.config(text=string)  # Update the label text
    time_label.after(1000, time)  # Update the time every 1000ms (1 second)

# Create main window
root = tk.Tk()
root.title("User Authentication")
root.geometry("300x350")  # Adjust window size

# Menu Bar
menu_bar = tk.Menu(root)

# Add a Time menu
time_menu = tk.Menu(menu_bar, tearoff=0)
menu_bar.add_cascade(label="Time & Date", menu=time_menu)
time_menu.add_command(label="Current Time/Date", state="disabled")  # Disable this menu item

# Configure the root window to use the menu bar
root.config(menu=menu_bar)

# Create and place labels, entries, and buttons on the window
tk.Label(root, text="Enter Username:").pack(pady=5)
username_entry = tk.Entry(root)
username_entry.pack(pady=5)

tk.Label(root, text="Enter Password:").pack(pady=5)
password_entry = tk.Entry(root, show="*")  # Use asterisks for password input
password_entry.pack(pady=5)

submit_button = tk.Button(root, text="Submit", command=submit_form)
submit_button.pack(pady=20)

# Time/Date label
time_label = tk.Label(root, font=("calibri", 12))
time_label.pack(pady=10)

# Start the time function to update time every second
time()

# Run the Tkinter event loop
root.mainloop()
