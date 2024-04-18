WITH statisfy AS (
    SELECT
        pid,
        tiv_2016
    FROM
        Insurance AS t1
    WHERE
        tiv_2015 IN (
            SELECT
                tiv_2015
            FROM
                Insurance AS t2
            WHERE
                t1.pid != t2.pid
        )
        AND (lat, lon) NOT IN (
            SELECT
                lat,
                lon
            FROM
                Insurance AS t3
            WHERE
                t1.pid != t3.pid
        )
)
SELECT
    ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM
    statisfy;