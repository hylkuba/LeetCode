SELECT e.name as Employee
FROM employee m
INNER JOIN employee e ON m.id = e.managerID
WHERE m.salary < e.salary
