WITH changed_before AS (
    SELECT
        product_id,
        new_price AS price
    FROM
        Products AS outer_p
    WHERE
        change_date <= "2019-08-16"
        AND change_date = (
            SELECT
                MAX(change_date)
            FROM
                Products AS inner_p
            WHERE
                change_date <= "2019-08-16"
                AND outer_p.product_id = inner_p.product_id
        )
) (
    SELECT
        *
    FROM
        changed_before
)
UNION
(
    SELECT
        DISTINCT product_id,
        10 AS price
    FROM
        Products
    WHERE
        product_id NOT IN (
            SELECT
                product_id
            FROM
                changed_before
        )
);

-- Solution 2
select
    p1.product_id,
    ifnull(p2.new_price, 10) as price
from
    (
        select
            distinct product_id
        from
            products
    ) as p1 -- 所有的产品
    left join (
        select
            product_id,
            new_price
        from
            products
        where
            (product_id, change_date) in (
                select
                    product_id,
                    max(change_date)
                from
                    products
                where
                    change_date <= '2019-08-16'
                group by
                    product_id
            )
    ) as p2 -- 在 2019-08-16 之前有过修改的产品和最新的价格
    on p1.product_id = p2.product_id;