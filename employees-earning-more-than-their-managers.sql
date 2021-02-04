# Write your MySQL query statement below
select A.name as Employee
from Employee as A join Employee as B on (A.ManagerId = B.Id)
where A.Salary > B.Salary