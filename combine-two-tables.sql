# Write your MySQL query statement below
select FirstName, LastName, City, State
from Person as A left join Address as B on A.PersonId = B.PersonId