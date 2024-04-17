SELECT
    employee_id,
    department_id
FROM
    Employee
WHERE
    primary_flag = 'Y'
    OR employee_id IN (
        -- 只属于一个部门的员工
        SELECT
            employee_id
        FROM
            Employee
        GROUP BY
            employee_id
        HAVING
            COUNT(*) = 1
    );