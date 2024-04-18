SELECT
    a.person_name
FROM
    Queue a,
    Queue b
WHERE
    a.turn >= b.turn
GROUP BY
    a.person_id,
    a.person_name
HAVING
    SUM(b.weight) <= 1000
ORDER BY
    a.turn DESC
LIMIT
    1;

--  Solution 2
select
    person_name
from
    (
        select
            person_name,
            weight,
            turn,
            sum(weight) over(
                order by
                    turn
            ) as total_weight
        from
            Queue
        order by
            turn
    ) t1
where
    total_weight <= 1000
order by
    total_weight desc
limit
    1;

--  Solution 3
SELECT
    a.person_name
FROM
    (
        SELECT
            person_name,
            @pre := @pre + weight AS weight
        FROM
            Queue,
            (
                SELECT
                    @pre := 0
            ) tmp
        ORDER BY
            turn
    ) a
WHERE
    a.weight <= 1000
ORDER BY
    a.weight DESC
LIMIT
    1;