# Write your MySQL query statement below
select D.Name as Department, E.Name as Employee, Salary
from Employee as E join Department as D on E.DepartmentId = D.Id
where E.Salary >= all (select Salary
                       from Employee as E1
                       where E1.DepartmentId = E.DepartmentId)