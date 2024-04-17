SELECT
    customer_id
FROM
    Customer
    JOIN Product ON Customer.product_key = Product.product_key
GROUP BY
    customer_id
HAVING
    COUNT(DISTINCT Product.product_key) = (
        SELECT
            COUNT(*)
        FROM
            Product
    );