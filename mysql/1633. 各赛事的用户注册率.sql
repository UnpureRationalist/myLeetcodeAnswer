SELECT
    contest_id,
    ROUND(
        COUNT(user_id) * 100 / (
            SELECT
                COUNT(*)
            FROM
                users
        ),
        2
    ) AS percentage
FROM
    Register
GROUP BY
    contest_id
ORDER BY
    percentage DESC,
    contest_id;

-- Solution 2
SELECT
    contest_id,
    ROUND(
        SUM(r.user_id = u.user_id) * 100 / COUNT(DISTINCT(u.user_id)),
        2
    ) percentage
FROM
    Register r
    CROSS JOIN Users u
GROUP BY
    contest_id
ORDER BY
    percentage DESC,
    contest_id;