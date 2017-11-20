#!/usr/bin/python
import MySQLdb

# Connect
db = MySQLdb.connect(host="localhost",
                     user="root",
                     passwd="projekti2017",
                     db="sensoriarvot")

cursor = db.cursor()

# Execute SQL select statement
cursor.execute("SELECT * FROM mqtt")

# Commit your changes if writing
# In this case, we are only reading data
# db.commit()

# Get the number of rows in the resultset
numrows = cursor.rowcount

# Get and display one row at a time
for x in range(0, numrows):
    row = cursor.fetchone()
    print row[0], "-->", row[1]

# Close the connection
db.close()