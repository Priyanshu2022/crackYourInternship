#combine two table
select person.firstName,person.lastName,address.city,address.state from person left join address on person.personId=address.personId;

# 2nd and nth highest salary
# select max(salary) as SecondHighestSalary from employee where salary not in(select max(salary) from employee);
select salary as SecondHighestSalary from employee e1 where 2-1=(select count(distinct salary) from employee e2 where e2.salary>e1.salary);

# city name end with vowel
select distinct(city) from station where city like '%a' or city like '%e' or city like '%i' or city like '%o'or city like '%u';
# vowels as both first and last
select city from station where city regexp '^[aeiou].*[aeiou]$';
# do not start with a vowel
select distinct city from station where city not in (select city from station where city regexp '^[aeiou].*');
# do not start with vowel or do not end with vowel
select distinct city from station where city not in (select city from station where city regexp '^[aeiou].*[aeiou]$');
#Given the CITY and COUNTRY tables, query the names of all cities where the CONTINENT is 'Africa'.
select ci.name from city ci join country co on ci.countrycode=co.code where co.continent='Africa';

# Rank Scores
select score , dense_rank() over(order by score desc) as "rank" from scores;

# employee earning more than managers
# select e1.name as "Employee" from employee e1 where e1.salary>(select e2.salary from employee e2 where e1.managerId=e2.id);
select e1.name as "Employee" from employee e1 , employee e2 where e1.managerId=e2.id and e1.salary>e2.salary;

# Duplicate emails
# select distinct p1.email as "Email" from person p1 where p1.email in (select p2.email from person p2 where p2.id!=p1.id);
select email as "Email" from person group by email having count(*)>1;

# customer who never never ordered
select name as Customers from customers where id not in (select customerId from orders);

# department highest salary
select department.name as Department, employee.name as Employee,salary from employee join department 
on employee.departmentId=department.id
where (departmentId,salary) in
(select departmentId,max(salary) from employee group by departmentId);


# is null

-- Logs table:
-- +----+-----+
-- | id | num |
-- +----+-----+
-- | 1  | 1   |
-- | 2  | 1   |
-- | 3  | 1   |
-- | 4  | 2   |
-- | 5  | 1   |
-- | 6  | 2   |
-- | 7  | 2   |
-- +----+-----+
# 3 consecutive num
select distinct num as ConsecutiveNums from Logs where
(id+1,num) in (select * from logs) and
(id+2,num) in (select * from logs);

#department highest salary 
select d.name as Department,e.name as Employee,e.salary as Salary from employee e join department d on e.departmentId=d.id
where e.salary=
(select max(salary) from employee where employee.departmentId=d.id);

select * from employe e join
(select dept,max(salary) salary from employee group by dept) d
on e.dept=d.dept and e.salary=d.salary; 