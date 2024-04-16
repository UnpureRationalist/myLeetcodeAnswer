SELECT
    query_name,
    ROUND(AVG(rating / position), 2) AS quality,
    ROUND(100 * SUM(rating < 3) / COUNT(*), 2) AS poor_query_percentage
FROM
    Queries
WHERE
    query_name IS NOT NULL
GROUP BY
    query_name;