DELETE FROM
    Person
WHERE
    id NOT IN (
        SELECT
            temp.id
        FROM
            (
                SELECT
                    MIN(id) AS id
                FROM
                    Person
                GROUP BY
                    email
            ) AS temp
    );