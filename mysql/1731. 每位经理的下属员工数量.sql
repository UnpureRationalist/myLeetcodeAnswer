WITH manager_id_lst AS (
    SELECT
        DISTINCT reports_to AS manager_id
    FROM
        Employees
    WHERE
        reports_to IS NOT NULL
),
manager AS (
    SELECT
        manager_id,
        name
    FROM
        manager_id_lst
        JOIN Employees ON manager_id = Employees.employee_id
)
SELECT
    manager_id AS employee_id,
    manager.name AS name,
    COUNT(*) AS reports_count,
    ROUND(AVG(age)) AS average_age
FROM
    manager
    JOIN Employees ON manager_id = Employees.reports_to
GROUP BY
    manager.manager_id,
    manager.name
ORDER BY
    manager_id;