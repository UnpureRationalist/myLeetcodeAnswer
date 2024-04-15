SELECT
    Signups.user_id AS user_id,
    ROUND(
        COUNT(IF(Confirmations.action = 'confirmed', 1, NULL)) / COUNT(*),
        2
    ) AS confirmation_rate
FROM
    Signups
    LEFT JOIN Confirmations ON Signups.user_id = Confirmations.user_id
GROUP BY
    Signups.user_id;