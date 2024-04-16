SELECT
    ROUND (
        SUM(order_date = customer_pref_delivery_date) * 100 / COUNT(*),
        2
    ) as immediate_percentage
FROM
    Delivery
WHERE
    (customer_id, order_date) IN (
        SELECT
            customer_id,
            MIN(order_date)
        FROM
            delivery
        GROUP BY
            customer_id
    );