import pandas as pd
from datetime import datetime
import os

# Δημιουργία αρχικού DataFrame από τον πίνακα ΠΑΡΑΓΓΕΛΙΑ
data = [
    [1, "Άγγελος", "Βώρος", "Κορίνθου 200", "Πάτρα", "2610-9919890", "ΑΠΟΡΥΠΑΝΤΙΚΟ", 2, 25.00, "10/18/2004"],
    [2, "Άγγελος", "Βώρος", "Κορίνθου 200", "Πάτρα", "2610-9919890", "ΤΕΤΡΑΔΙΟ", 5, 3.00, "10/18/2004"],
    [3, "Κώστας", "Περδίου", "Αθηνών 6", "Αθήνα", "210-9919890", "ΤΗΛΕΟΡΑΣΗ", 1, 600.00, "10/18/2004"],
    [4, "Κώστας", "Περδίου", "Αθηνών 6", "Αθήνα", "210-9919890", "ΨΩΜΙ", 1, 2.00, "10/18/2004"],
    [5, "Γιώργος", "Καλέμης", "Αράτου 111", "Πάτρα", "2610-887960", "ΤΕΤΡΑΔΙΟ", 2, 3.00, "10/10/2004"],
    [6, "Γιώργος", "Καλέμης", "Αράτου 111", "Πάτρα", "2610-887960", "ΤΗΛΕΟΡΑΣΗ", 1, 600.00, "12/10/2004"],
]

columns = [
    "ΚΩΔ_ΠΑΡ", "ΟΝΟΜΑ", "ΕΠΩΝΥΜΟ", "ΔΙΕΥΘΥΝΣΗ", "ΠΟΛΗ", "ΤΗΛΕΦΩΝΟ",
    "ΠΡΟΙΟΝ", "ΠΟΣΟΤΗΤΑ_ΠΡΟΙΟΝΤΟΣ", "ΤΙΜΗ_ΜΟΝΑΔΑΣ", "ΗΜΕΡ_ΑΓΟΡΑΣ"
]

df_original = pd.DataFrame(data, columns=columns)

# Μετατροπή ημερομηνίας
df_original["ΗΜΕΡ_ΑΓΟΡΑΣ"] = pd.to_datetime(df_original["ΗΜΕΡ_ΑΓΟΡΑΣ"], dayfirst=False)

# Δημιουργία πίνακα ΠΕΛΑΤΕΣ
df_pelates = df_original[["ΚΩΔ_ΠΑΡ", "ΟΝΟΜΑ", "ΕΠΩΝΥΜΟ", "ΔΙΕΥΘΥΝΣΗ", "ΠΟΛΗ", "ΤΗΛΕΦΩΝΟ"]].drop_duplicates()

# Δημιουργία πίνακα ΠΡΟΪΟΝΤΑ με ID
df_proionta = df_original[["ΠΡΟΙΟΝ", "ΤΙΜΗ_ΜΟΝΑΔΑΣ"]].drop_duplicates().reset_index(drop=True)
df_proionta["ID_ΠΡΟΙΟΝΤΟΣ"] = df_proionta.index + 1

# Σύνδεση ID_ΠΡΟΙΟΝΤΟΣ στον πίνακα παραγγελιών
df_paraggelies = df_original.merge(df_proionta, on=["ΠΡΟΙΟΝ", "ΤΙΜΗ_ΜΟΝΑΔΑΣ"])
df_paraggelies_final = df_paraggelies[["ΚΩΔ_ΠΑΡ", "ID_ΠΡΟΙΟΝΤΟΣ", "ΠΟΣΟΤΗΤΑ_ΠΡΟΙΟΝΤΟΣ", "ΗΜΕΡ_ΑΓΟΡΑΣ"]]
df_paraggelies_final = df_paraggelies_final.reset_index(drop=True)
df_paraggelies_final["ID_ΠΑΡΑΓΓΕΛΙΑΣ"] = df_paraggelies_final.index + 1

# Rearranging columns
df_paraggelies_final = df_paraggelies_final[["ID_ΠΑΡΑΓΓΕΛΙΑΣ", "ΚΩΔ_ΠΑΡ", "ID_ΠΡΟΙΟΝΤΟΣ", "ΠΟΣΟΤΗΤΑ_ΠΡΟΙΟΝΤΟΣ", "ΗΜΕΡ_ΑΓΟΡΑΣ"]]

# Αποθήκευση σε Excel (στον φάκελο που τρέχει το script)
df_pelates.to_excel("ΠΕΛΑΤΕΣ.xlsx", index=False)
df_proionta.to_excel("ΠΡΟΙΟΝΤΑ.xlsx", index=False)
df_paraggelies_final.to_excel("ΠΑΡΑΓΓΕΛΙΕΣ.xlsx", index=False)

print("Τα αρχεία δημιουργήθηκαν επιτυχώς:")
print(" - ΠΕΛΑΤΕΣ.xlsx")
print(" - ΠΡΟΙΟΝΤΑ.xlsx")
print(" - ΠΑΡΑΓΓΕΛΙΕΣ.xlsx")
