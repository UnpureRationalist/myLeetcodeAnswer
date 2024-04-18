SELECT
    DISTINCT t1.num AS ConsecutiveNums
FROM
    Logs AS t1
    JOIN Logs AS t2 ON t1.id = t2.id + 1
    JOIN Logs AS t3 ON t1.id = t3.id + 2
WHERE
    t1.num = t2.num
    AND t2.num = t3.num;