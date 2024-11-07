mysql> CREATE TABLE Event (
    ->     event_id INT AUTO_INCREMENT PRIMARY KEY,
    ->     name VARCHAR(255),
    ->     `desc` TEXT,
    ->     city VARCHAR(255)
    -> );
Query OK, 0 rows affected (0.02 sec)

mysql> CREATE TABLE Participant (
    ->     player_id INT AUTO_INCREMENT PRIMARY KEY,
    ->     name VARCHAR(255),
    ->     event_id INT,
    ->     gender VARCHAR(10),
    ->     year INT,
    ->     FOREIGN KEY (event_id) REFERENCES Event(event_id)
    -> );
Query OK, 0 rows affected (0.03 sec)

mysql> CREATE TABLE Prizes (
    ->     prize_id INT AUTO_INCREMENT PRIMARY KEY,
    ->     money INT,
    ->     event_id INT,
    ->     `rank` INT,  -- Use backticks to escape the reserved word `rank`
    ->     year INT,
    ->     FOREIGN KEY (event_id) REFERENCES Event(event_id)
    -> );
Query OK, 0 rows affected (0.02 sec)

mysql> CREATE TABLE Winners (
    ->     prize_id INT,
    ->     player_id INT,
    ->     PRIMARY KEY (prize_id, player_id),
    ->     FOREIGN KEY (prize_id) REFERENCES Prizes(prize_id),
    ->     FOREIGN KEY (player_id) REFERENCES Participant(player_id)
    -> );
Query OK, 0 rows affected (0.03 sec)

mysql> DELIMITER $$
mysql> 
mysql> CREATE TRIGGER after_event_insert
    -> AFTER INSERT ON Event
    -> FOR EACH ROW
    -> BEGIN
    ->     -- Insert 1st Prize
    ->     INSERT INTO Prizes (money, event_id, `rank`, year)
    ->     VALUES (1500, NEW.event_id, 1, YEAR(CURDATE()));
    -> 
    ->     -- Insert 2nd Prize
    ->     INSERT INTO Prizes (money, event_id, `rank`, year)
    ->     VALUES (1000, NEW.event_id, 2, YEAR(CURDATE()));
    -> 
    ->     -- Insert 3rd Prize
    ->     INSERT INTO Prizes (money, event_id, `rank`, year)
    ->     VALUES (500, NEW.event_id, 3, YEAR(CURDATE()));
    -> END $$
Query OK, 0 rows affected (0.01 sec)

mysql> 
mysql> DELIMITER ;
mysql> INSERT INTO Event (name, `desc`, city)
    -> VALUES ('Annual Marathon', 'A marathon race in the city', 'New York');
Query OK, 1 row affected (0.01 sec)

mysql> SELECT * FROM Prizes;
+----------+-------+----------+------+------+
| prize_id | money | event_id | rank | year |
+----------+-------+----------+------+------+
|        1 |  1500 |        1 |    1 | 2024 |
|        2 |  1000 |        1 |    2 | 2024 |
|        3 |   500 |        1 |    3 | 2024 |
+----------+-------+----------+------+------+
3 rows in set (0.00 sec)

mysql> INSERT INTO Event (name, `desc`, city)
    -> VALUES ('Annual Ik', 'A marathon race in the city', 'New York');
Query OK, 1 row affected (0.01 sec)

mysql> 
mysql> INSERT INTO Event (name, `desc`, city) VALUES ('Annual kuku', 'A marathon
 race in the city', 'Thrissur');
Query OK, 1 row affected (0.01 sec)

mysql> SELECT * FROM Prizes;
+----------+-------+----------+------+------+
| prize_id | money | event_id | rank | year |
+----------+-------+----------+------+------+
|        1 |  1500 |        1 |    1 | 2024 |
|        2 |  1000 |        1 |    2 | 2024 |
|        3 |   500 |        1 |    3 | 2024 |
|        4 |  1500 |        2 |    1 | 2024 |
|        5 |  1000 |        2 |    2 | 2024 |
|        6 |   500 |        2 |    3 | 2024 |
|        7 |  1500 |        3 |    1 | 2024 |
|        8 |  1000 |        3 |    2 | 2024 |
|        9 |   500 |        3 |    3 | 2024 |
+----------+-------+----------+------+------+
9 rows in set (0.00 sec)


