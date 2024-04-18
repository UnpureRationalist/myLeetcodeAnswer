SELECT
    Department.name AS Department,
    out_t_e.name AS Employee,
    out_t_e.salary AS Salary
FROM
    Employee AS out_t_e
    JOIN Department ON out_t_e.departmentId = Department.id
WHERE
    3 > (
        SELECT
            COUNT(DISTINCT in_t_e.salary)
        FROM
            Employee AS in_t_e
        WHERE
            in_t_e.departmentId = out_t_e.departmentId
            AND in_t_e.salary > out_t_e.salary
    );