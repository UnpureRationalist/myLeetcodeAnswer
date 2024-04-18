WITH users AS (
    (
        SELECT
            DISTINCT requester_id AS user_id
        FROM
            RequestAccepted
    )
    UNION
    (
        SELECT
            DISTINCT accepter_id AS user_id
        FROM
            RequestAccepted
    )
)
SELECT
    users.user_id AS id,
    COUNT(
        DISTINCT RequestAccepted.requester_id,
        RequestAccepted.accepter_id
    ) AS num
FROM
    users
    JOIN RequestAccepted ON users.user_id = RequestAccepted.requester_id
    OR users.user_id = RequestAccepted.accepter_id
GROUP BY
    users.user_id
ORDER BY
    num DESC
LIMIT
    1;