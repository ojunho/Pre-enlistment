db = [{"Name": "oh", "Score": "100"},{"Name": "oh", "Score": "20"}, {"Name": "lee", "Score": "100"}]

for i in db:
    if i["Name"] == "oh":
        db.remove(i)

print(db)
print(len(db))