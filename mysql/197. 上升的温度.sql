SELECT
    W2.id
FROM
    Weather AS W1
    JOIN Weather AS W2 ON W1.recordDate = DATE_SUB(W2.recordDate, INTERVAL 1 DAY)
WHERE
    W2.temperature > W1.temperature;