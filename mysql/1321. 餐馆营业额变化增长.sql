WITH date_lst AS (
    SELECT
        DISTINCT visited_on
    FROM
        Customer
)
SELECT
    t1.visited_on,
    SUM(t2.amount) AS amount,
    ROUND(SUM(t2.amount) / 7, 2) AS average_amount
FROM
    date_lst AS t1
    JOIN Customer AS t2 ON DATEDIFF(t1.visited_on, t2.visited_on) BETWEEN 0
    AND 6
GROUP BY
    t1.visited_on
HAVING
    COUNT(DISTINCT t2.visited_on) >= 7
ORDER BY
    t1.visited_on;