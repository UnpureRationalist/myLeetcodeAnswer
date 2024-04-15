SELECT
    e2.name
FROM
    Employee AS e1
    JOIN Employee AS e2 ON e1.managerId = e2.id
GROUP BY
    e2.id,
    e2.name
HAVING
    COUNT(DISTINCT e1.id) >= 5