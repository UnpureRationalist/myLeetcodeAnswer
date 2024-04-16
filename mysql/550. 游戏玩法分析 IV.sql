-- 报告在首次登录的第二天再次登录的玩家的 比率，四舍五入到小数点后两位。
-- 换句话说，你需要计算从首次登录日期开始至少连续两天登录的玩家的数量，然后除以玩家总数。
SELECT
    ROUND(AVG(a.event_date IS NOT NULL), 2) AS fraction
FROM
    (
        SELECT
            player_id,
            min(event_date) AS login
        FROM
            activity
        GROUP BY
            player_id
    ) AS p
    LEFT JOIN activity AS a ON p.player_id = a.player_id
    AND DATEDIFF(a.event_date, p.login) = 1;