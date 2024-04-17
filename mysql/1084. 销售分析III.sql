SELECT
    DISTINCT Product.product_id,
    Product.product_name
FROM
    Product
    JOIN Sales ON Product.product_id = Sales.product_id
WHERE
    (
        Sales.sale_date BETWEEN '2019-01-01'
        AND '2019-03-31'
    )
    AND Product.product_id NOT IN (
        SELECT
            Product.product_id
        FROM
            Product
            JOIN Sales ON Product.product_id = Sales.product_id
        WHERE
            NOT (
                Sales.sale_date BETWEEN '2019-01-01'
                AND '2019-03-31'
            )
    );