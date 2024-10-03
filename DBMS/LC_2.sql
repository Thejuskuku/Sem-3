mysql> use employee;
Database changed
mysql> create table emp(emp_id int,emp_name varchar(20),Street_No int,city varchar(20));
Query OK, 0 rows affected (0.02 sec)

mysql> create table works(emp_id int,company_name varchar(20),salary int);
Query OK, 0 rows affected (0.03 sec)

mysql> create table company(company_name varchar(20),city varchar(20));
Query OK, 0 rows affected (0.02 sec)

mysql> create table manages(emp_id int,manager_id int);
Query OK, 0 rows affected (0.03 sec)

mysql> insert into emp(emp_id,emp_name,Street_No,city) VALUES (1, 'Alice Johnson', '123 Elm St', 'New York'),
    -> (2, 'Bob Smith', '456 Oak St', 'San Francisco')
    -> ,(3, 'Charlie Brown', '789 Pine St', 'Boston'),
    -> (4, 'Diana Prince', '101 Maple St', 'New York'),
    -> (5, 'Eve Adams', '202 Birch St', 'San Francisco');
ERROR 1265 (01000): Data truncated for column 'Street_No' at row 1
mysql> insert into emp(emp_id,emp_name,Street_No,city) VALUES (1, 'Alice Johnson', 123, 'New York'), (2, 'Bob Smith', 456, 'San Francisco') ,(3, 'Charlie Brown', 789, 'Boston'), (4, 'Diana Prince', 101, 'New York'), (5, 'Eve Adams', 202, 'San Francisco');
Query OK, 5 rows affected (0.02 sec)
Records: 5  Duplicates: 0  Warnings: 0

mysql> select * from emp;
+--------+---------------+-----------+---------------+
| emp_id | emp_name      | Street_No | city          |
+--------+---------------+-----------+---------------+
|      1 | Alice Johnson |       123 | New York      |
|      2 | Bob Smith     |       456 | San Francisco |
|      3 | Charlie Brown |       789 | Boston        |
|      4 | Diana Prince  |       101 | New York      |
|      5 | Eve Adams     |       202 | San Francisco |
+--------+---------------+-----------+---------------+
5 rows in set (0.00 sec)

mysql> insert into works(emp_id,comapny_name,salary) values (1, 'SBI', 70000), (2, 'Indian Bank', 75000), (3, 'SBI', 72000), (4, 'Indian Bank', 68000); 
ERROR 1054 (42S22): Unknown column 'comapny_name' in 'field list'
mysql> insert into works(emp_id,company_name,salary) values (1, 'SBI', 70000), (2, 'Indian Bank', 75000), (3, 'SBI', 72000), (4, 'Indian Bank', 68000);

Query OK, 4 rows affected (0.01 sec)
Records: 4  Duplicates: 0  Warnings: 0

mysql> insert into company(company_name,city) values ('SBI', 'New York'),
    -> ('Indian Bank', 'Chicago');
Query OK, 2 rows affected (0.00 sec)
Records: 2  Duplicates: 0  Warnings: 0

mysql> select * from works;
+--------+--------------+--------+
| emp_id | company_name | salary |
+--------+--------------+--------+
|      1 | SBI          |  70000 |
|      2 | Indian Bank  |  75000 |
|      3 | SBI          |  72000 |
|      4 | Indian Bank  |  68000 |
+--------+--------------+--------+
4 rows in set (0.00 sec)

mysql> select * from company;
+--------------+----------+
| company_name | city     |
+--------------+----------+
| SBI          | New York |
| Indian Bank  | Chicago  |
+--------------+----------+
2 rows in set (0.00 sec)

mysql> insert into manages(emp_id,manger_id) values(2, 1), 
    -> (4, 3);
ERROR 1054 (42S22): Unknown column 'manger_id' in 'field list'
mysql> insert into manages(emp_id,manager_id) values(2, 1),  (4, 3);
Query OK, 2 rows affected (0.00 sec)
Records: 2  Duplicates: 0  Warnings: 0

mysql> select * from manages;
+--------+------------+
| emp_id | manager_id |
+--------+------------+
|      2 |          1 |
|      4 |          3 |
+--------+------------+
2 rows in set (0.01 sec)

mysql> alter table emp change emp_id emp_id int not null;
Query OK, 0 rows affected (0.04 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> select * from emp;
+--------+---------------+-----------+---------------+
| emp_id | emp_name      | Street_No | city          |
+--------+---------------+-----------+---------------+
|      1 | Alice Johnson |       123 | New York      |
|      2 | Bob Smith     |       456 | San Francisco |
|      3 | Charlie Brown |       789 | Boston        |
|      4 | Diana Prince  |       101 | New York      |
|      5 | Eve Adams     |       202 | San Francisco |
+--------+---------------+-----------+---------------+
5 rows in set (0.00 sec)

mysql> select emp.emp_name from emp,works where emp.emp_id=works.emp_id and company_name="SBI";
+---------------+
| emp_name      |
+---------------+
| Alice Johnson |
| Charlie Brown |
+---------------+
2 rows in set (0.00 sec)

mysql> select emp.emp_name from emp,company where emp.city=company.city;
+---------------+
| emp_name      |
+---------------+
| Alice Johnson |
| Diana Prince  |
+---------------+
2 rows in set (0.00 sec)

mysql>  select * from emp group by Street_No;
ERROR 1055 (42000): Expression #1 of SELECT list is not in GROUP BY clause and contains nonaggregated column 'employee.emp.emp_id' which is not functionally dependent on columns in GROUP BY clause; this is incompatible with sql_mode=only_full_group_by
mysql>  select emp_name from emp where Street_No=Street_No;
+---------------+
| emp_name      |
+---------------+
| Alice Johnson |
| Bob Smith     |
| Charlie Brown |
| Diana Prince  |
| Eve Adams     |
+---------------+
5 rows in set (0.00 sec)

mysql>  select emp_name from emp where Street_No;
+---------------+
| emp_name      |
+---------------+
| Alice Johnson |
| Bob Smith     |
| Charlie Brown |
| Diana Prince  |
| Eve Adams     |
+---------------+
5 rows in set (0.00 sec)

