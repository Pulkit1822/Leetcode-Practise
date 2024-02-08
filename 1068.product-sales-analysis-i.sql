# Write your MySQL query statement below
select Product.product_name, year, price from Sales Join Product On
Sales.product_id=Product.product_id;