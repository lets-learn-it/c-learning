myString = "I am Parikshit Patil from Kavathe Ekand. Kavathe Ekand is small town in Maharashtra state in India."

print("Length of myString: ", #myString, "\n")

-- string.gsub(string, pattern, newPattern, firstNMatches)
print("Replace Kavathe Ekand with Tasgaon: ", string.gsub(myString, "Kavathe Ekand", "Tasgaon"))

-- find index of substring
print("Index of Patil: ", string.find(myString, "Patil"))

-- uppercase or lowercase
print("UPPERCASE: ", string.upper(myString))
print("lowercase: ", string.lower(myString))