SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM insurance i1
WHERE 1 = (
    SELECT COUNT(*)
    FROM insurance i2
    WHERE i1.lat = i2.lat AND i1.lon = i2.lon
)
AND 1< (
    SELECT count(*)
    FROM insurance i3
    WHERE i1.tiv_2015 = i3.tiv_2015

);
