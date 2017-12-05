import mysql.connector

cnx = mysql.connector.connect(user='projekti', password='projekti2017',
                              host='139.59.170.58', database='projekti')
cursor = cnx.cursor()
query = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/logger/mqtt_log.txt' INTO TABLE Rotta FIELDS TERMINATED BY '\t';"
cursor.execute(query)
cnx.commit()
cnx.close()